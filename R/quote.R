#' @include PqConnection.R
NULL

#' Quote postgres strings, identifiers, and literals
#'
#' If an object of class [Id] is used for `dbQuoteIdentifier()`, it needs
#' at most one `table` component and at most one `schema` component.
#'
#' @param conn A [PqConnection-class] created by `dbConnect()`
#' @param x A character to escaped
#' @param ... Other arguments needed for compatibility with generic
#' @examples
#' # For running the examples on systems without PostgreSQL connection:
#' run <- postgresHasDefault()
#'
#' library(DBI)
#' if (run) con <- dbConnect(RPostgres::Postgres())
#'
#' x <- c("a", "b c", "d'e", "\\f")
#' if (run) dbQuoteString(con, x)
#' if (run) dbQuoteIdentifier(con, x)
#' if (run) dbDisconnect(con)
#' @name quote
NULL

#' @export
#' @rdname quote
setMethod("dbQuoteString", c("PqConnection", "character"), function(conn, x, ...) {
  if (length(x) == 0) return(SQL(character()))
  res <- SQL(connection_quote_string(conn@ptr, enc2utf8(x)))
  res
})

#' @export
#' @rdname quote
setMethod("dbQuoteString", c("PqConnection", "SQL"), function(conn, x, ...) {
  x
})

#' @export
#' @rdname quote
setMethod("dbQuoteIdentifier", c("PqConnection", "character"), function(conn, x, ...) {
  if (anyNA(x)) {
    stop("Cannot pass NA to dbQuoteIdentifier()", call. = FALSE)
  }
  SQL(connection_quote_identifier(conn@ptr, x), names = names(x))
})

#' @export
#' @rdname quote
setMethod("dbQuoteIdentifier", c("PqConnection", "SQL"), function(conn, x, ...) {
  x
})

#' @export
#' @rdname quote
setMethod("dbQuoteIdentifier", c("PqConnection", "Id"), function(conn, x, ...) {
  stopifnot(all(names(x@name) %in% c("schema", "table")))
  stopifnot(!anyDuplicated(names(x@name)))

  ret <- ""
  if ("schema" %in% names(x@name)) {
    ret <- paste0(ret, dbQuoteIdentifier(conn, x@name[["schema"]]), ".")
  }
  if ("table" %in% names(x@name)) {
    ret <- paste0(ret, dbQuoteIdentifier(conn, x@name[["table"]]))
  }
  SQL(ret)
})

#' @export
#' @rdname quote
setMethod("dbUnquoteIdentifier", c("PqConnection", "SQL"), function(conn, x, ...) {
  rx <- '^(?:(?:|"((?:[^"]|"")+)"[.])(?:|"((?:[^"]|"")*)")|([^". ]+))$'
  bad <- grep(rx, x, invert = TRUE)
  if (length(bad) > 0) {
    stop("Can't unquote ", x[bad[[1]]], call. = FALSE)
  }

  schema <- gsub(rx, "\\1", x)
  schema <- gsub('""', '"', schema)
  table <- gsub(rx, "\\2", x)
  table <- gsub('""', '"', table)
  naked_table <- gsub(rx, "\\3", x)

  ret <- Map(schema, table, naked_table, f = as_table)
  names(ret) <- names(x)
  ret
})

as_table <- function(schema, table, naked_table = NULL) {
  args <- c(schema = schema, table = table, table = naked_table)
  # Also omits NA args
  args <- args[!is.na(args) & args != ""]
  do.call(Id, as.list(args))
}

# locally for now, requires DBI > 0.7
#' @rdname quote
setGeneric("dbQuoteLiteral",
  def = function(conn, x, ...) standardGeneric("dbQuoteLiteral")
)

#' @export
#' @rdname quote
setMethod("dbQuoteLiteral", c("PqConnection", "logical"), function(conn, x, ...) {
  ret <- as.character(x)
  ret[is.na(ret)] <- "NULL"
  SQL(ret, names = names(ret))
})

#' @export
#' @rdname quote
setMethod("dbQuoteLiteral", c("PqConnection", "integer"), function(conn, x, ...) {
  ret <- paste0(as.character(x), "::int4")
  ret[is.na(x)] <- "NULL"
  SQL(ret, names = names(ret))
})

#' @export
#' @rdname quote
setMethod("dbQuoteLiteral", c("PqConnection", "numeric"), function(conn, x, ...) {
  ret <- paste0(as.character(x), "::float8")
  ret[is.na(x)] <- "NULL"
  SQL(ret, names = names(ret))
})

#' @export
#' @rdname quote
setMethod("dbQuoteLiteral", c("PqConnection", "factor"), function(conn, x, ...) {
  dbQuoteLiteral(conn, as.character(x))
})

#' @export
#' @rdname quote
setMethod("dbQuoteLiteral", c("PqConnection", "Date"), function(conn, x, ...) {
  ret <- paste0("'", as.character(x), "'::date")
  ret[is.na(x)] <- "NULL"
  SQL(ret, names = names(ret))
})

#' @export
#' @rdname quote
setMethod("dbQuoteLiteral", c("PqConnection", "POSIXt"), function(conn, x, ...) {
  ret <- paste0("'", as.character(x), "'::timestamp")
  ret[is.na(x)] <- "NULL"
  SQL(ret, names = names(ret))
})

#' @export
#' @rdname quote
setMethod("dbQuoteLiteral", c("PqConnection", "difftime"), function(conn, x, ...) {
  ret <- paste0(as.character(x), "::time")
  ret[is.na(x)] <- "NULL"
  SQL(ret, names = names(ret))
})

#' @export
#' @rdname quote
setMethod("dbQuoteLiteral", c("PqConnection", "list"), function(conn, x, ...) {
  quote_blob(x)
})

# Workaround, remove when blob > 1.1.0 is on CRAN
setOldClass("blob")

#' @export
#' @rdname quote
#' @importFrom blob blob
setMethod("dbQuoteLiteral", c("PqConnection", "blob"), function(conn, x, ...) {
  quote_blob(x)
})

quote_blob <- function(x) {
  blob_data <- vcapply(
    x,
    function(x) {
      if (is.null(x)) "NULL"
      else if (is.raw(x)) paste0("E'\\\\x", paste(format(x), collapse = ""), "'")
      else {
        stop("Lists must contain raw vectors or NULL", call. = FALSE)
      }
    }
  )
  SQL(blob_data, names = names(x))
}
