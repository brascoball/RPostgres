#ifndef __RPOSTGRES_PQ_CONNECTION__
#define __RPOSTGRES_PQ_CONNECTION__

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

class DbResult;

// convenience typedef for shared_ptr to DbConnection
class DbConnection;
typedef boost::shared_ptr<DbConnection> DbConnectionPtr;

// DbConnection ----------------------------------------------------------------

class DbConnection : boost::noncopyable {
  PGconn* pConn_;
  const DbResult* pCurrentResult_;
  bool transacting_;

public:
  DbConnection(std::vector<std::string> keys, std::vector<std::string> values);
  virtual ~DbConnection();

public:
  void disconnect();

  PGconn* conn();

  void set_current_result(const DbResult* pResult);
  bool is_current_result(const DbResult* pResult);
  bool has_query();

  void copy_data(std::string sql, List df);

  void check_connection();
  List info();

  SEXP quote_string(const String& x);
  SEXP quote_identifier(const String& x);
  static SEXP get_null_string();

  bool is_transacting() const;
  void set_transacting(bool transacting);

  void conn_stop(const char* msg);
  static void conn_stop(PGconn* conn, const char* msg);

  void cleanup_query();
  void finish_query() const;

private:
  void cancel_query();
};

#endif
