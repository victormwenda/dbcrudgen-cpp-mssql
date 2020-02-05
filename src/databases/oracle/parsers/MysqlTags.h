//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 4/14/18.
// C/C++ Laptop
//



#ifndef DBCRUDGEN_CPP_MYSQLTAGS_H
#define DBCRUDGEN_CPP_MYSQLTAGS_H


//
// MysqlTags
// //
class MysqlTags {
public:
    constexpr static char *TABLE_TYPE = "${TABLE_TYPE}";
    constexpr static char *TABLE_TYPE_VIEW = "${TABLE_TYPE_VIEW}";
    constexpr static char *TABLE_TYPE_BASE_TABLE = "${TABLE_TYPE_BASE_TABLE}";
};


#endif //DBCRUDGEN_CPP_MYSQLTAGS_H
