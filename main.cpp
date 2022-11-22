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
        tmp = stack;
        stack = new T[count + 1]; //выделить больше памяти в стеке чем было
        count++; //количество элементов в стеке увеличиваем
        for (int i = 0; i < count - 1; i++)
        {
            stack[i] = tmp[i]; //копируем данные из tmp (куда он указывает) в наш стек
        }
        stack[count - 1] = item; //добавляем последний элемент
        if (count > 1)
        {
            delete[] tmp; //освобождаем память
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
        return stack[count]; //возвращаем  элемент стека
    }
    bool IsEmpty() //если наш стек пуст
    {
        return count == 0; //если количество элементов в стеке равна 0
    }
};
