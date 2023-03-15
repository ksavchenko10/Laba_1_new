#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <windows.h>

class EStackException: public std::exception {};

class EStackEmpty: public EStackException {};

template<typename T>
class Stack
{
private:
    class Node // используем композицию для задания элемента стека
    {
    public:
        T value; // значение
        Node* next_node; // указатель на следующий элемент стека

        Node(T val, Node* node) //конструктор
        {
            value = val; //задаем значение элемента стека
            next_node = node; //задаем указатель на следующий элементе стека
        }
    };
    Node* top_node; // указатель на вершину стека
    int count; // размер стека

public:
    Stack<T>(); //конструктор
    Stack<T>(const Stack<T>& stack); //конструктор копирвания
    void push(T value); //добавить элемент в стек
    T pop(); // изъять элемент из стека
    int countNode(); //возвращает количество элементов в стеке
};

template<typename T>
Stack<T>::Stack()//конструктора
{
    top_node = nullptr; // указатель на вершину стека
    count = 0; // размер стека
}

template<typename T>
Stack<T>::Stack(const Stack<T>& stack)
{
    top_node = nullptr;
    count = 0;
    Node* currNode = stack.top_node; //
    while (currNode != nullptr) {
        push(currNode->value);
        currNode = currNode->next_node;
    }
}

template<typename T>
void Stack<T>::push(T value) //добавляем новый элемент в стек
{
    top_node = new Node(value, top_node); //создаём новую вершину
    count++; //увеличивается размер стека
}

template<typename T>
T Stack<T>::pop() //удаление вершины стека, возвращаем при этом удаляемую вершину
{
    if (top_node == nullptr)
    {
        throw EStackEmpty();
    }
    else
    {
        Node* new_top_node = top_node->next_node; //запоминается следующий элемент после вершины
        T result = top_node->value; //запоминаем значение текущей вершины стека
        delete top_node; //удаляем память текущей вершины стека
        top_node = new_top_node; //задаем новой вершиной следующий элемент стека
        count--; //уменьшаем размер стек
        return result; //возвращаем значение которое было в вершине стека
    }
}

template<typename T>
int Stack<T>::countNode() //возвращает количество элементов в стеке
{
    return count; //  размер стека
}

#endif // STACK_H
