#include "PersonKeeper.h"
#include "stack.h"
#include "Person.h"
#include <iostream>
#include <string>


Stack <Person>* PersonKeeper::readPersons(std::istream& stream) //чтение из файла
{
    Stack <Person>* st; //создаем стек из экземпляров класса Person
    st = new Stack <Person>();
    std::string fio;
    size_t firstDel, secondDel; //позиции на пробелы
    while (!stream.eof()) //
    {
        std::getline(stream, fio); //читаем строку с файла
        firstDel = fio.find(" ", 0); //находим позицию первого пробела
        if (firstDel == std::string::npos)// если не нашли пробел, перехродим на следующий шаг
            continue;
        secondDel = fio.find(" ", firstDel + 1); //ищем позицию второго пробела
        if (secondDel == std::string::npos)// если не нашли пробел, перехродим на следующий шаг
            continue;
        Person pers; //создаем экземпляр класса Person
        pers.setLastName(fio.substr(0, firstDel)); //Задаем фамилию: подстрока с 0 символа, длиной до позици первого пробела
        pers.setFirstName(fio.substr(firstDel + 1, secondDel - (firstDel + 1))); //Задаем имя: подстрока от следующего за первым пробелом символа, длиной до позици второго пробела - (позиция первого проблела + 1)
        pers.setPatronymic(fio.substr(secondDel + 1, fio.size() - (secondDel + 1))); //Задаем отчетство: подстрока от следующего за вторым пробелом символа, длинной дл конца строки - (позиция свторого пробела + 1)
        st->push(pers); //Добавляем экземляр класса Person в наш стек st
    }

    return st; //Возвращаем наш стек
}

void PersonKeeper::writePersons(const Stack<Person>& value, std::ostream& stream) //запись стека с ФИО в файл, передаем стек с данными и поток вывода
{
    Stack<Person> st(value); //создаем стек их входящего стека (копируем стек)
    while (st.countNode() != 0) //если стек еще не пуст, проходим дальше
    {
        try {
            Person p = st.pop(); //берем из стека верхний элемент
            stream << p.getLastName() << " " << p.getFirstName() << " " << p.getPatronymic() << '\n'; //выводим в поток ФИО
        } catch (EStackEmpty)  {
            std::cerr << "Error. Stack is empty, it is not posible to remove an element using the pop method." << std::endl;
        }
    }
}
