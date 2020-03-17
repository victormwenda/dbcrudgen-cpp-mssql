//
// Created by victor on 3/17/20.
//

#ifndef DBCRUDGEN_CPP_CPPMYSQLTABLEQUERYRECORDWITHMODELTEMPLATE_H
#define DBCRUDGEN_CPP_CPPMYSQLTABLEQUERYRECORDWITHMODELTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "CppTemplateFiles.h"
#include "../../codegen/Languages.h"

namespace dbcrudgen {
    namespace orm {
        class CppMYSQLTableQueryRecordWithModelTemplate : public FileSourceCodeTemplate {
            std::string getSourceFile() override {
                return std::string{CppTemplateFiles::MYSQL::METHOD_SCRUD_QUERY_RECORD_WITH_MODEL};
            }

            std::string getLanguage() override {
                return std::string{Languages::CPP};
            }
        };
    }
}

#endif //DBCRUDGEN_CPP_CPPMYSQLTABLEQUERYRECORDWITHMODELTEMPLATE_H
