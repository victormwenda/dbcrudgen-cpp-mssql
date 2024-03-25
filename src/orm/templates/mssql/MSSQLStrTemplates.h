//
// Created by victor on 12/26/20.
//

#ifndef DBCRUDGEN_CPP_MSSQLSTRTEMPLATES_H
#define DBCRUDGEN_CPP_MSSQLSTRTEMPLATES_H

namespace dbcrudgen {
    namespace orm {
        namespace mssql {
            class MSSQLStrTemplates {
            public:
                struct CONN_STR {
                    static constexpr const char *TEMPLATE_SQL_SERVER =
                            "DRIVER={ODBC Driver 17 for SQL Server};SERVER=${HOST},${PORT};DATABASE=${DATABASE};UID=${USER};PWD=${PASSWORD};Trusted_Connection=No;";
                    static constexpr const char *TEMPLATE_AZURE_AD =
                            "DRIVER={ODBC Driver 18 for SQL Server};Server=${HOST},${PORT};DATABASE=${DATABASE};UID=${USER};PWD=${PASSWORD};Authentication=SqlPassword;Encrypt=No;Trusted_Connection=No;";
                };
            };
        }
    }
}


#endif //DBCRUDGEN_CPP_MSSQLSTRTEMPLATES_H
