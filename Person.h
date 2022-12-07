#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

class Person
{
    std::string last_name; //Имя
    std::string first_name; //Фамилия
    std::string patronymic; //Фамилия
public:
    Person(); //Конструктор
    Person(const Person & value); //Конструктор
    const std::string& getLastName() const;//Получить фамилию
    const std::string& getFirstName() const; //Получить имя
    const std::string& getPatronymic() const; //Получить отчество
    void setLastName(std::string); //Изменить фамилию
    void setFirstName(std::string); //Изменить имя
    void setPatronymic(std::string); //Изменить отчество
};

#endif // PERSON_H
