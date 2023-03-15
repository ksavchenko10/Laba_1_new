#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include "stack.h"
#include "Person.h"

class PersonKeeper //класс для работы со стеком
{

public:
    static PersonKeeper& Instance() //статический метод возвращающий наш экземпляр синглтон Майерса
        {
            static PersonKeeper s; //статическая переменная экземпляр класса PersonKeeper.
            return s; //возвращаем наш экземпляр синглтон
        }

        void writePersons(const Stack<Person>& value, std::ostream& stream); //запись данных в файл
        Stack <Person>* readPersons(std::istream& stream); //метод чтения данных из файла и возвращения стека

    private:
        PersonKeeper() {}; //конструктор
        PersonKeeper(PersonKeeper const&); //конструктор копирования
        PersonKeeper& operator= (PersonKeeper const&); //оператор присваивания
};

#endif // PERSONKEEPER_H
