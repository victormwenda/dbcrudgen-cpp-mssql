//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELCONTROLLERMETHODSHOWTEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELCONTROLLERMETHODSHOWTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "../../../codegen/Languages.h"
#include "LaravelTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelControllerMethodShowTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelTemplateFiles::METHOD_CONTROLLER_SHOW};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELCONTROLLERMETHODSHOWTEMPLATE_H
