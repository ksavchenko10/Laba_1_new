#include "PersonKeeper.h"
#include "stack.h"
#include "Person.h"
#include <iostream>
#include <string>


Stack <Person>* PersonKeeper::readPersons(std::istream& stream) //чтение из файла
{
    std::string name, surname, patronymic;
    Stack <Person>* st; //создаем стек из экземпляров класса Person
    st = new Stack <Person>();
    while (stream >> name >> surname >> patronymic) //пока в потоке stream будут данные для чтения (3 строковых: имя фамилия отчество)
    {
        Person pers; //создаем экземпляр класса Person
        pers.setFirstName(name); //Задаем имя
        pers.setLastName(surname); //Задаем фамилию
        pers.setPatronymic(patronymic); //Задаем фамилию
        std::cout << surname << " " << name << " " << patronymic << '\n';
        st->push(pers); //Добавляем экземляр класса Person в наш стек st
    }

    return st; //Возвращаем наш стек
}

void PersonKeeper::writePersons(Stack <Person> value, std::ostream& stream) //запись стека с именами и фамилиями в файл, передаем стек с данными и поток вывода
{
    Stack <Person> st(value); //создаем стек их входящего стека (копируем стек)
    while (!(st.IsEmpty())) //если стек еще не пуст, проходим дальше
    {
        Person p = st.pop(); //берем из стека верхний элемент
        stream << p.getFirstName() << " " << p.getLastName() << " " << p.getPatronymic() << '\n'; //выводим в поток имя и фамилию
    }
}
