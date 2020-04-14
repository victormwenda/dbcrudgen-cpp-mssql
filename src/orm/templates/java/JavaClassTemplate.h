//
// Created by victor on 4/14/20.
//

#ifndef DBCRUDGEN_CPP_JAVACLASSTEMPLATE_H
#define DBCRUDGEN_CPP_JAVACLASSTEMPLATE_H

#include "../FileSourceCodeTemplate.h"
#include "JavaTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class JavaClassTemplate : public FileSourceCodeTemplate {

        protected:
            std::string getSourceFile() override {
                return std::string{JavaTemplateFiles::DEFAULT_CLASS_TEMPLATE};
            }

            std::string getLanguage() override {
                return std::string{Languages::JAVA};
            }
        };

    }
}
#endif //DBCRUDGEN_CPP_JAVACLASSTEMPLATE_H
