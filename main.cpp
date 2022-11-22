#include <QCoreApplication>


template <typename T>

class STACK //класс для реализации стека
{
private:
    T* stack; //стек
    int count; //количество элементов в стеке

public:
    void push(T item) //добавить элемент в стек
    {
        T* tmp; //временная переменная указатель
        tmp = stack; //временный указатель на наш текущий стек
        stack = new T[count + 1]; //создаем новый пустой стек, при этом выделяем больше памяти в стеке чем было для новой записи

        count++; //количество элементов в стеке увеличиваем

        for (int i = 0; i < count - 1; i++)
        {
            stack[i] = tmp[i]; //копируем данные из tmp (куда он указывает, т.е. наши данные старые которые были) в наш новый стек
        }

        stack[count - 1] = item; //добавляем нашу новую запись в стек

        if (count > 1) //если у нас есть записи, значит мы что-то добавляли и tmp не пустой
        {
            delete[] tmp; //освобождаем память, т.к. переменная tmp нам больше не нужна
        }
    }

    T pop() //изъять элемент из стека
    {
        T tmp;
        if (count == 0) //если наш стек пуст
        {
            return tmp;
        }

        count--; //уменьшаем количество элементов в стеке
        return stack[count]; //возвращаем  первый элемент из стека
    }

    bool IsEmpty() //если наш стек пуст
    {
        return count == 0; //если количество элементов в стеке равна 0
    }

};


class Person
{
private:
    long key;
    std::string last_name; //Фамилия
    std::string first_name; //Имя
public:
    Person(); //Конструктор
    Person(const Person&); //Конструктор
    const std::string& getLastName() const { return last_name; }; //Получить фамилию, не описываем этот метод отдельно, т.к. достаточно простой
    const std::string& getFirstName() const { return first_name; }; //Получить имя, не описываем этот метод отдельно, т.к. достаточно простой
    void setLastName(const std::string&); //Изменить фамилию
    void setFirstName(const std::string&); //Изменить имя
};

Person::Person()
{
    key = 1;
    first_name = "NAME";
    last_name = "SURNAME";
}

Person::Person(const Person& value)
{
    first_name = value.getFirstName(); //При создании экземпляра ласса копируем переданные значения имени и фамилии экземпляра этого же класса
    last_name = value.getLastName();

}

void Person::setLastName(const std::string& value)
{
    last_name = value;
}

void Person::setFirstName(const std::string& value)
{
    first_name = value;
}
