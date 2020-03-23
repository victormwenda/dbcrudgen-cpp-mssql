//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELCONTROLLERMETHODDESTORYTEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELCONTROLLERMETHODDESTORYTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../../../codegen/Languages.h"
#include "LaravelTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelControllerMethodDestoryTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelTemplateFiles::METHOD_CONTROLLER_DESTROY};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELCONTROLLERMETHODDESTORYTEMPLATE_H
