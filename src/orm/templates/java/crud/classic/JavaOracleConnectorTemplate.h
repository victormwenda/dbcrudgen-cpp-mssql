//
// Created by vrwanda on 3/5/20.
//


#ifndef DBCRUDGEN_CPP_JAVAORACLECONNECTORTEMPLATE_H
#define DBCRUDGEN_CPP_JAVAORACLECONNECTORTEMPLATE_H

#include "../../../FileSourceCodeTemplate.h"

namespace dbcrudgen {
    namespace orm {
        class JavaOracleConnectorTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::__cxx11::string();
            }

        private:
            std::string getLanguage() override {
                return std::__cxx11::string();
            }
        };
    }
}


#endif //DBCRUDGEN_CPP_JAVAORACLECONNECTORTEMPLATE_H