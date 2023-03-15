#include "Person.h"

Person::Person() //конструкток без параметров
{
    first_name = "";
    last_name = "";
    patronymic = "";
}

Person::Person(const Person& value) //конструтор копирования экземпляра Person
{
    first_name = value.getFirstName(); //При создании экземпляра класса копируем переданные значения ФИО экземпляра этого же класса
    last_name = value.getLastName();
    patronymic = value.getPatronymic();
}

void Person::setLastName(std::string value)
{
    last_name = value; //задаем фамилию
}

void Person::setFirstName(std::string value)
{
    first_name = value; //задаем имя
}

void Person::setPatronymic(std::string value)
{
    patronymic = value; //задаем отчество
}

const std::string &Person::getLastName() const//Получить фамилию
{
    return last_name;
}

const std::string &Person::getFirstName() const //Получить имя
{
    return first_name;
}

const std::string &Person::getPatronymic() const //Получить отчество
{
    return patronymic;
}

