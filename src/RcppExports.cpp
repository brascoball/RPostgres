// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "RPostgres_types.h"
#include <Rcpp.h>

using namespace Rcpp;

// connection_create
XPtr<DbConnectionPtr> connection_create(std::vector<std::string> keys, std::vector<std::string> values);
RcppExport SEXP _RPostgres_connection_create(SEXP keysSEXP, SEXP valuesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type keys(keysSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type values(valuesSEXP);
    rcpp_result_gen = Rcpp::wrap(connection_create(keys, values));
    return rcpp_result_gen;
END_RCPP
}
// connection_is_valid
bool connection_is_valid(XPtr<DbConnectionPtr> con);
RcppExport SEXP _RPostgres_connection_is_valid(SEXP conSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbConnectionPtr> >::type con(conSEXP);
    rcpp_result_gen = Rcpp::wrap(connection_is_valid(con));
    return rcpp_result_gen;
END_RCPP
}
// connection_release
void connection_release(XPtr<DbConnectionPtr> con_);
RcppExport SEXP _RPostgres_connection_release(SEXP con_SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbConnectionPtr> >::type con_(con_SEXP);
    connection_release(con_);
    return R_NilValue;
END_RCPP
}
// connection_info
List connection_info(DbConnection* con);
RcppExport SEXP _RPostgres_connection_info(SEXP conSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbConnection* >::type con(conSEXP);
    rcpp_result_gen = Rcpp::wrap(connection_info(con));
    return rcpp_result_gen;
END_RCPP
}
// connection_escape_string
CharacterVector connection_escape_string(DbConnection* con, CharacterVector xs);
RcppExport SEXP _RPostgres_connection_escape_string(SEXP conSEXP, SEXP xsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbConnection* >::type con(conSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type xs(xsSEXP);
    rcpp_result_gen = Rcpp::wrap(connection_escape_string(con, xs));
    return rcpp_result_gen;
END_RCPP
}
// connection_escape_identifier
CharacterVector connection_escape_identifier(DbConnection* con, CharacterVector xs);
RcppExport SEXP _RPostgres_connection_escape_identifier(SEXP conSEXP, SEXP xsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbConnection* >::type con(conSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type xs(xsSEXP);
    rcpp_result_gen = Rcpp::wrap(connection_escape_identifier(con, xs));
    return rcpp_result_gen;
END_RCPP
}
// connection_copy_data
void connection_copy_data(DbConnection* con, std::string sql, List df);
RcppExport SEXP _RPostgres_connection_copy_data(SEXP conSEXP, SEXP sqlSEXP, SEXP dfSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbConnection* >::type con(conSEXP);
    Rcpp::traits::input_parameter< std::string >::type sql(sqlSEXP);
    Rcpp::traits::input_parameter< List >::type df(dfSEXP);
    connection_copy_data(con, sql, df);
    return R_NilValue;
END_RCPP
}
// connection_is_transacting
bool connection_is_transacting(DbConnection* con);
RcppExport SEXP _RPostgres_connection_is_transacting(SEXP conSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbConnection* >::type con(conSEXP);
    rcpp_result_gen = Rcpp::wrap(connection_is_transacting(con));
    return rcpp_result_gen;
END_RCPP
}
// connection_set_transacting
void connection_set_transacting(DbConnection* con, bool transacting);
RcppExport SEXP _RPostgres_connection_set_transacting(SEXP conSEXP, SEXP transactingSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbConnection* >::type con(conSEXP);
    Rcpp::traits::input_parameter< bool >::type transacting(transactingSEXP);
    connection_set_transacting(con, transacting);
    return R_NilValue;
END_RCPP
}
// encode_vector
std::string encode_vector(RObject x);
RcppExport SEXP _RPostgres_encode_vector(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< RObject >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(encode_vector(x));
    return rcpp_result_gen;
END_RCPP
}
// encode_data_frame
std::string encode_data_frame(List x);
RcppExport SEXP _RPostgres_encode_data_frame(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< List >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(encode_data_frame(x));
    return rcpp_result_gen;
END_RCPP
}
// encrypt_password
String encrypt_password(String password, String user);
RcppExport SEXP _RPostgres_encrypt_password(SEXP passwordSEXP, SEXP userSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< String >::type password(passwordSEXP);
    Rcpp::traits::input_parameter< String >::type user(userSEXP);
    rcpp_result_gen = Rcpp::wrap(encrypt_password(password, user));
    return rcpp_result_gen;
END_RCPP
}
// init_logging
void init_logging(const std::string& log_level);
RcppExport SEXP _RPostgres_init_logging(SEXP log_levelSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::string& >::type log_level(log_levelSEXP);
    init_logging(log_level);
    return R_NilValue;
END_RCPP
}
// result_create
XPtr<DbResult> result_create(XPtr<DbConnectionPtr> con, std::string sql);
RcppExport SEXP _RPostgres_result_create(SEXP conSEXP, SEXP sqlSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbConnectionPtr> >::type con(conSEXP);
    Rcpp::traits::input_parameter< std::string >::type sql(sqlSEXP);
    rcpp_result_gen = Rcpp::wrap(result_create(con, sql));
    return rcpp_result_gen;
END_RCPP
}
// result_release
void result_release(XPtr<DbResult> res);
RcppExport SEXP _RPostgres_result_release(SEXP resSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbResult> >::type res(resSEXP);
    result_release(res);
    return R_NilValue;
END_RCPP
}
// result_fetch
List result_fetch(DbResult* res, const int n);
RcppExport SEXP _RPostgres_result_fetch(SEXP resSEXP, SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbResult* >::type res(resSEXP);
    Rcpp::traits::input_parameter< const int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(result_fetch(res, n));
    return rcpp_result_gen;
END_RCPP
}
// result_bind
void result_bind(DbResult* res, List params);
RcppExport SEXP _RPostgres_result_bind(SEXP resSEXP, SEXP paramsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbResult* >::type res(resSEXP);
    Rcpp::traits::input_parameter< List >::type params(paramsSEXP);
    result_bind(res, params);
    return R_NilValue;
END_RCPP
}
// result_has_completed
bool result_has_completed(DbResult* res);
RcppExport SEXP _RPostgres_result_has_completed(SEXP resSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbResult* >::type res(resSEXP);
    rcpp_result_gen = Rcpp::wrap(result_has_completed(res));
    return rcpp_result_gen;
END_RCPP
}
// result_valid
bool result_valid(XPtr<DbResult> res_);
RcppExport SEXP _RPostgres_result_valid(SEXP res_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< XPtr<DbResult> >::type res_(res_SEXP);
    rcpp_result_gen = Rcpp::wrap(result_valid(res_));
    return rcpp_result_gen;
END_RCPP
}
// result_rows_fetched
int result_rows_fetched(DbResult* res);
RcppExport SEXP _RPostgres_result_rows_fetched(SEXP resSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbResult* >::type res(resSEXP);
    rcpp_result_gen = Rcpp::wrap(result_rows_fetched(res));
    return rcpp_result_gen;
END_RCPP
}
// result_rows_affected
int result_rows_affected(DbResult* res);
RcppExport SEXP _RPostgres_result_rows_affected(SEXP resSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbResult* >::type res(resSEXP);
    rcpp_result_gen = Rcpp::wrap(result_rows_affected(res));
    return rcpp_result_gen;
END_RCPP
}
// result_column_info
List result_column_info(DbResult* res);
RcppExport SEXP _RPostgres_result_column_info(SEXP resSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< DbResult* >::type res(resSEXP);
    rcpp_result_gen = Rcpp::wrap(result_column_info(res));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_RPostgres_connection_create", (DL_FUNC) &_RPostgres_connection_create, 2},
    {"_RPostgres_connection_is_valid", (DL_FUNC) &_RPostgres_connection_is_valid, 1},
    {"_RPostgres_connection_release", (DL_FUNC) &_RPostgres_connection_release, 1},
    {"_RPostgres_connection_info", (DL_FUNC) &_RPostgres_connection_info, 1},
    {"_RPostgres_connection_escape_string", (DL_FUNC) &_RPostgres_connection_escape_string, 2},
    {"_RPostgres_connection_escape_identifier", (DL_FUNC) &_RPostgres_connection_escape_identifier, 2},
    {"_RPostgres_connection_copy_data", (DL_FUNC) &_RPostgres_connection_copy_data, 3},
    {"_RPostgres_connection_is_transacting", (DL_FUNC) &_RPostgres_connection_is_transacting, 1},
    {"_RPostgres_connection_set_transacting", (DL_FUNC) &_RPostgres_connection_set_transacting, 2},
    {"_RPostgres_encode_vector", (DL_FUNC) &_RPostgres_encode_vector, 1},
    {"_RPostgres_encode_data_frame", (DL_FUNC) &_RPostgres_encode_data_frame, 1},
    {"_RPostgres_encrypt_password", (DL_FUNC) &_RPostgres_encrypt_password, 2},
    {"_RPostgres_init_logging", (DL_FUNC) &_RPostgres_init_logging, 1},
    {"_RPostgres_result_create", (DL_FUNC) &_RPostgres_result_create, 2},
    {"_RPostgres_result_release", (DL_FUNC) &_RPostgres_result_release, 1},
    {"_RPostgres_result_fetch", (DL_FUNC) &_RPostgres_result_fetch, 2},
    {"_RPostgres_result_bind", (DL_FUNC) &_RPostgres_result_bind, 2},
    {"_RPostgres_result_has_completed", (DL_FUNC) &_RPostgres_result_has_completed, 1},
    {"_RPostgres_result_valid", (DL_FUNC) &_RPostgres_result_valid, 1},
    {"_RPostgres_result_rows_fetched", (DL_FUNC) &_RPostgres_result_rows_fetched, 1},
    {"_RPostgres_result_rows_affected", (DL_FUNC) &_RPostgres_result_rows_affected, 1},
    {"_RPostgres_result_column_info", (DL_FUNC) &_RPostgres_result_column_info, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_RPostgres(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
