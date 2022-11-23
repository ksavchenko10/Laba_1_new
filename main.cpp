#include <QCoreApplication>

#include <iostream>
#include <fstream>
#include <string>

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

class PersonKeeper //класс для работы со стеком
{

public:
    static PersonKeeper* instance(); //создаем либо возвращаем экземпляр нашего класса-синглтон
    STACK <Person>* readPersons(std::istream& stream); //метод чтения данных из файла и возвращения стека
    void writePersons(STACK <Person> a, std::ostream& stream); //запись данных в файл

private:
    static PersonKeeper* singleton; //переменная которая хранит наш экземпляр класса-синглтона
};

PersonKeeper* PersonKeeper::singleton = NULL; //изначально экземпляр класса равен NULL, пока не будет объявлен

PersonKeeper* PersonKeeper::instance()  //Реализация паттерна Singleton
{
    if (singleton == NULL) //если экземпляра этого класса еще нет, то создаем его
    {
        singleton = new PersonKeeper;
    }

    return singleton; //если экземпляр этого класса уже есть, отдаем его же... т.е. не возможно создать другой экземпляр этого класса, если мы попытаеся создать еще объект этого класса он вернет уже существующий
}

STACK <Person>* PersonKeeper::readPersons(std::istream& stream) //чтение из файла
{
    std::string name, surname, patronymic;
    STACK <Person>* st; //создаем стек из экземпляров класса Person
    st = new STACK <Person>(); //создаем экземпляр класса Person
    while (stream >> name >> surname >> patronymic) //пока в потоке stream будут данные для чтения (3 строковых: имя фамилия отчество) то продолжаем считывать из файла данные, как только не будет 3 записей больше выйдет из цикла
    {
        Person pers; //создаем экземпляр класса Person
        pers.setFirstName(name); //Задаем имя
        pers.setLastName(surname); //Задаем фамилию
        std::cout << surname << " "; //выводим в консоль фамилию
        std::cout << name << "\n"; //выводим в консоль имя
        st->push(pers); //Добавляем экземляр класса Person в наш стек st
    }

    return st; //Возвращаем наш стек со всеми ФИО
}

void PersonKeeper::writePersons(STACK <Person> a, std::ostream& stream) //запись стека с именами и фамилиями в файл, передаем стек с данными и поток вывода
{
    while (!(a.IsEmpty())) //если стек еще не пуст, проходим дальше
    {
        Person p = a.pop(); //берем из стека верхний элемент
        stream << p.getFirstName() <<  p.getLastName(); //выводим в поток имя и фамилию
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PersonKeeper personKeeperInstance;	//создаем экземпляр класса personKeeperInstance

        std::fstream file_in; //создаем объект file_in типа fstream, для работы с файлами. fstream - стандартная библиотека для работы с файлами
        file_in.open("vvod.txt"); // открываем файл для чтения (или записи, но в данном случае мы будем считывать), используя стандартный метод библиотеки open

        STACK <Person> st;	//создаем стэк из элементов стека класса Person.
        st = *personKeeperInstance.readPersons(file_in); // метод readPersons возвращает стек с объектами класса Person. При этом мы используем экземпляр класса personKeeperInstance, который мы создали для нашей задачи и сделали там нужные методы... т.е. сделали что-то вроде библиотеки с готовыми методами

        file_in.close(); //закрывает поток file_in чтения из файла

        std::fstream file_out; //создаем объект file_out типа fstream, для работы с файлами
        file_out.open("vyvod.txt"); //открываем файл для записи

        personKeeperInstance.writePersons(st, file_out); //записываем в файл данные из стека st в файл file_out, при этом используем наш экземпляр класса personKeeperInstance с нужным методом для записи

        file_out.close(); ////закрывает поток file_out

    return a.exec();
}
