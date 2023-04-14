#include <QCoreApplication>

#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
#include "Person.cpp"
#include "PersonKeeper.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::fstream file_in; //создаем объект file_in типа fstream, для работы с файлами. fstream - стандартная библиотека для работы с файлами
    file_in.open("vvod.txt"); // открываем файл для чтения, используя стандартный метод библиотеки open

    if (file_in.is_open()) //если файл существует и открылся
    {
        std::cout << "File has been opened!" << '\n'; //вывод в консоль об успешности открытия

        Stack<Person> st;	//создаем стэк из элементов стека класса Person.
        st = *PersonKeeper::Instance().readPersons(file_in); // метод readPersons возвращает стек с объектами класса Person.

        std::cout << "File has been readed!" << '\n';

        file_in.close(); //закрывает поток file_in чтения из файла

        std::ofstream file_out; //создаем объект file_out типа fstream, для работы с файлами
        file_out.open("vyvod.txt"); //открываем файл для записи

        if (file_out.is_open())
        {
             PersonKeeper::Instance().writePersons(st, file_out); //записываем в файл данные из стека st в файл file_out, используя метод writePersons класса-синглтона PersonKeeper


             file_out.close(); //закрывает поток file_out
        }
        else
        {
              std::cout << "Error creating output file!" << '\n'; // ошибка создания выходного файла
        }

        std::cout << "Finished!" << '\n';

    }
    else
    {
        std::cout << "Input file not found!" << '\n'; // входной файл не найден
    }

    //std::cout << "demo" << std::endl;
    Stack<std::string> tmpStack;
    std::string newVal;
    std::cin >> newVal;
    tmpStack.push("test");
    tmpStack.push("kolbasa");
    std::cout << tmpStack.pop() << std::endl;
    std::cout << tmpStack.pop() << std::endl;
    std::cout << newVal << std::endl;


    return a.exec();
}
