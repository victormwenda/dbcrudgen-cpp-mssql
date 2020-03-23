//
// Created by victor on 3/19/20.
//

#ifndef DBCRUDGEN_CPP_LARAVELROUTEAPIPOSTTEMPLATE_H
#define DBCRUDGEN_CPP_LARAVELROUTEAPIPOSTTEMPLATE_H

#include "../../FileSourceCodeTemplate.h"
#include "LaravelTemplateFiles.h"

namespace dbcrudgen {
    namespace orm {
        class LaravelRouteApiPostTemplate : public FileSourceCodeTemplate {
        protected:
            std::string getSourceFile() override {
                return std::string{LaravelTemplateFiles::METHOD_ROUTE_API_POST};
            }

        private:
            std::string getLanguage() override {
                return std::string{Languages::PHP};
            }
        };
    }
}
#endif //DBCRUDGEN_CPP_LARAVELROUTEAPIPOSTTEMPLATE_H
