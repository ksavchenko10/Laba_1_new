#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include "stack.h"
#include "Person.h"

class PersonKeeper //класс для работы со стеком
{

public:
    static PersonKeeper& Instance() //синглтон
        {
            static PersonKeeper s;
            return s;
        }

        void writePersons(Stack <Person> value, std::ostream& stream); //запись данных в файл
        Stack <Person>* readPersons(std::istream& stream); //метод чтения данных из файла и возвращения стека

    private:
        PersonKeeper() {}; //конструктор
        ~PersonKeeper() {}; //деструктор
        PersonKeeper(PersonKeeper const&); //запрещено копирование
        PersonKeeper& operator= (PersonKeeper const&); //запрещено копирование
};

#endif // PERSONKEEPER_H
