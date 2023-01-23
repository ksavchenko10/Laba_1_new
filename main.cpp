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

  PersonKeeper& instance = PersonKeeper::Instance(); //создаем экземпляр класса personKeeperInstance

        std::fstream file_in; //создаем объект file_in типа fstream, для работы с файлами. fstream - стандартная библиотека для работы с файлами
        file_in.open("vvod.txt"); // открываем файл для чтения (или записи, но в данном случае мы будем считывать), используя стандартный метод библиотеки open

        if (file_in) //если файл существует и открылся
        {
            std::cout << "File has been opened!" << '\n'; //вывод в консоль об успешности открытия

            Stack <Person> st;	//создаем стэк из элементов стека класса Person.
            st = *PersonKeeper::Instance().readPersons(file_in); // метод readPersons возвращает стек с объектами класса Person. При этом мы используем экземпляр класса personKeeperInstance, который мы создали для нашей задачи и сделали там нужные методы... т.е. сделали что-то вроде библиотеки с готовыми методами

            file_in.close(); //закрывает поток file_in чтения из файла

            std::ofstream file_out; //создаем объект file_out типа fstream, для работы с файлами
            file_out.open("vyvod.txt"); //открываем файл для записи

            if (file_out)
            {
                 PersonKeeper::Instance().writePersons(st, file_out); //записываем в файл данные из стека st в файл file_out, при этом используем наш экземпляр класса personKeeperInstance с нужным методом для записи

                 file_out.close(); //закрывает поток file_out
            }
            else
            {
                  std::cout << "Error creating output file!" << '\n'; // ошибка создания выходного файла
            }

        }
        else
        {
            std::cout << "Input file not found!" << '\n'; // входной файл не найден
        }
 /*
Stack <int> st;
    st.push(5);
    st.push(7);
    st.push(13);
    st.push(27);

int top = st.pop();
    std::cout << top  << '\n';

top = st.pop();
    std::cout << top  << '\n';

std::cout << st.countNode()  << '\n';
*/

    return a.exec();
}
