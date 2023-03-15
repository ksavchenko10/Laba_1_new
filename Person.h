#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

class Person
{
    std::string last_name; //Фамилия
    std::string first_name; //Имя
    std::string patronymic; //Отчество
public:
    Person(); //Конструктор
    Person(const Person & value); //Конструктор
    const std::string& getLastName() const;//Получить фамилию
    const std::string& getFirstName() const; //Получить имя
    const std::string& getPatronymic() const; //Получить отчество
    void setLastName(std::string); //Присвоить фамилию
    void setFirstName(std::string); //Присвоить имя
    void setPatronymic(std::string); //Присвоить отчество
};

#endif // PERSON_H
