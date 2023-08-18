
#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "unit.h"
#include "cpp.h"
#include "c_sharp.h"

class CodeFactory
{
public:
    virtual ~CodeFactory() = default;
    using Flags = unsigned int;

    virtual std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Flags flags) const = 0;
    virtual std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) const = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) const = 0;
};


#endif // ABSTRACTFACTORY_H
