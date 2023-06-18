#include <QString>
#include <iostream>
#include "iocc.h"

enum class ProcessorType {
    x86,
    x64
};

QString getProcessorType(ProcessorType type) {
    switch (type)
    {
    case ProcessorType::x64:
        return "x64";
        break;

    case ProcessorType::x86:
        return "x86";
        break;
    }
    return "";
};

struct IProcessor  {
    virtual ~IProcessor(){}
    virtual QString getProcessorInfo() = 0;
};

struct IntelCPU : IProcessor {
    IntelCPU(ProcessorType m_type, double m_speed, QString m_version)
    {
        type = m_type;
        speed = m_speed;
        version = m_version;
    }

    QString getProcessorInfo() override
    {
        return "Intel " + getProcessorType(type) + " processor "
               + version + " speed " + QString::number(speed) + " GHz";
    }

private:
    double speed;
    ProcessorType type;
    QString version;
};

struct AMDCPU : IProcessor {
    AMDCPU(ProcessorType m_type, double m_speed, QString m_version)
    {
        type = m_type;
        speed = m_speed;
        version = m_version;
    }

    QString getProcessorInfo() override
    {
        return "AMD " + getProcessorType(type) + " processor "
               + version + " speed " + QString::number(speed) + " GHz";
    }

private:
    double speed;
    ProcessorType type;
    QString version;
};


struct PC {

    PC(std::shared_ptr<IProcessor> m_cpu) { cpu = m_cpu; }

    std::shared_ptr<IProcessor> getCPU() { return cpu; }

    void setCPU(std::shared_ptr<IProcessor> m_cpu) { this->cpu = m_cpu; }

    QString getInfo()
    {
        if (cpu != nullptr) { return cpu->getProcessorInfo(); }
        else { return "No processor"; }
    }

private:
    std::shared_ptr<IProcessor> cpu;
};

IoCContainer gIoCContainer;

void clientCode() {
    auto pc = PC {gIoCContainer.getService<IProcessor>()};
    std::cout << pc.getInfo().toStdString() << std::endl;
}

int main()
{
    gIoCContainer.registerService<IProcessor, IntelCPU>(ProcessorType::x64, 3.5, "i7");
    clientCode();

    gIoCContainer.registerService<IProcessor, AMDCPU>(ProcessorType::x86, 3.0, "ryzen5");
    clientCode();
}
