#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include "stack.h"
#include "Person.h"

class PersonKeeper //класс для работы со стеком
{

public:
    static PersonKeeper* instance(); //создаем либо возвращаем экземпляр нашего класса-синглтон
    Stack <Person>* readPersons(std::istream& stream); //метод чтения данных из файла и возвращения стека
    void writePersons(Stack <Person> value, std::ostream& stream); //запись данных в файл

private:
    static PersonKeeper* singleton; //переменная которая хранит наш экземпляр класса-синглтона
};

#endif // PERSONKEEPER_H
