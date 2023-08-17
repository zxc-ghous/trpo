
#ifndef UNIT_H
#define UNIT_H
#include <vector>
#include <string>
#include <iostream>
#include <memory>

class Unit
{
public:
    virtual ~Unit() = default;

    using Flags = unsigned int;  // загуглить юзинг

    //спросит про это, это нужно для того если ты хочешь ты можешь перегружать функцию вирутальную, если не хочешь можешь не перегружать
    virtual void add(const std::shared_ptr<Unit>&) // зачем throw std::runtime_error("Not supported") если это не абстрактный метод?
    {
        throw std::runtime_error("Not supported");
    }
    virtual std::string compile(unsigned int level = 0) const = 0; //для чего нужен этот метод
    virtual Flags getFlags() const
    {
        return Flags(); //почему тут Flags вызывется как функция?
    }

protected: // почему протектед?
    virtual std::string generateShift(unsigned int level) const // зачем нужна эта функция и почему она конст?
    {
        static const auto DEFAULT_SHIFT = "    ";
        std::string result;
        for (unsigned int i = 0; i < level; i++)
        {
            result += DEFAULT_SHIFT;
        }
        return result;
    }

};

class MethodUnit : public Unit
{
public:
    enum Modifier
    {
        STATIC              = 1,
        CONST               = 1 << 1,
        VIRTUAL             = 1 << 2,
        PUBLIC              = 1 << 3,
        PROTECTED           = 1 << 4,
        PRIVATE             = 1 << 5,
        FINAL               = 1 << 6,
        ABSTRACT            = 1 << 7,
        INTERNAL            = 1 << 8,
        PROTECTED_INTERNAL  = 1 << 9,
        PRIVATE_PROTECTED   = 1 << 10
    };

    MethodUnit(const std::string& name, const std::string& returnType, Flags flags)
    {
        m_name = name;
        m_returnType = returnType;
        m_flags = flags;
    }

    void add(const std::shared_ptr<Unit>& unit)
    {
        m_body.push_back(unit);
    }

    std::string compile(unsigned int level = 0) const
    {
        throw std::runtime_error("Not supported");
    }

protected:
    std::string getName() const
    {
        return m_name;
    }

    std::string getReturnType() const
    {
        return m_returnType;
    }

    Flags getFlags() const
    {
        return m_flags;
    }

    std::vector<std::shared_ptr<Unit>> getBody() const
    {
        return m_body;
    }

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};



class ClassUnit : public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED
    };
    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit ClassUnit(const std::string& name) //explicit???
    {
        m_name = name;
        m_fields.resize(ACCESS_MODIFIERS.size());
    }

    void add(const std::shared_ptr<Unit>& unit)
    {
        int accessModifier = PRIVATE;
        Flags flags = unit->getFlags();

        switch (flags)
        {
        case MethodUnit::PUBLIC:
            accessModifier = PUBLIC;
            break;
        case MethodUnit::PROTECTED:
            accessModifier = PROTECTED;
            break;
        case MethodUnit::INTERNAL:
            accessModifier = INTERNAL;
            break;
        case MethodUnit::PROTECTED_INTERNAL:
            accessModifier = PROTECTED_INTERNAL;
            break;
        case MethodUnit::PRIVATE_PROTECTED:
            accessModifier = PRIVATE_PROTECTED;
            break;
        default:
            break;
        }

        m_fields[accessModifier].push_back(unit);
    }

    std::string compile(unsigned int level = 0) const
    {
        throw std::runtime_error("Not supported");
    }

protected:
    using Fields = std::vector<std::shared_ptr<Unit>>;

    std::string getName() const
    {
        return m_name;
    }


    const Fields& getFields(unsigned int accessGroup) const
    {
        if (ACCESS_MODIFIERS.size() <= accessGroup)
        {
            throw std::out_of_range("Invalid access group");
        }
        return m_fields[accessGroup];
    }

private:
    std::string m_name;
    std::vector<Fields> m_fields;

};

class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit(const std::string& text)
    {
        m_text = text;
    }

    std::string compile(unsigned int level = 0) const
    {
        throw std::runtime_error("Not supported");
    }

protected:
    std::string getText() const
    {
        return m_text;
    }

private:
    std::string m_text;
};

#endif // UNIT_H
