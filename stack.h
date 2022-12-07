#ifndef STACK_H
#define STACK_H

template<typename T>

class Stack
{
private:
    class Node // используем композицию для задания элемента стека
    {
    public:
        T value; // значение
        Node* next_node; // указатель на следующий элемент стека

        Node(T val, Node* next_node) //конструктор
        {
            this->value = val; //задаем значение элемента стека
            this->next_node = next_node; //задаем указатель на следующий элементе стека
        }
    };
    Node* top_node = nullptr; // указатель на вершину стека
    int count = 0; // размер стека

public:
    Stack<T>(); //конструктор
    Stack<T>(const Stack<T>& stack); //конструктора копирования
    void push(T value); //добавить элемент в стек
    T pop(); // изъять элемент из стека
    bool IsEmpty(); //проверяет пуст ли стек
};

template<typename T>

Stack<T>::Stack() //конструктора
{
}

template<typename T>
Stack<T>::Stack(const Stack<T> &stack) //конструктора копирования
{
    if (stack.count == 0) //если стек для копирования пустой
    {
        return; //выходим
    }

    Node *node = stack.top_node; //выбираем вершину стека
    for (int i = 0; i < stack.count; i++) //обход стека
    {
        this->push(node->value); //добавляем элемент стека в наш новый стек
        node = node->next_node; //переходим к следующему элементу в стеке
    }
}

template<typename T>

void Stack<T>::push(T value) //добавляем новый элемент в стек
{
    if (top_node == nullptr) // если вершина не существует
    {
        top_node = new Node(value, nullptr); // то создаём новую вершину
    }
    else
    {
        Node* last_top_node = top_node; // если вершина существует то запоминаем ее
        top_node = new Node(value, last_top_node); // создаем новый элемент стека
        //и передаем в конструктор значение нового элемента и ссылку на следующий элемент стека
    }

    count++; //увеличивается размер стека, т.к. добавился новый элемент
}

template<typename T>

T Stack<T>::pop() //удаление вершины стека, возвращаем при этом удаляемую вершину
{
    Node* new_top_node = top_node->next_node; // запоминается следующий элемент после вершины
    T result = top_node->value; // запоминаем значение текущей вершины стека
    delete top_node; //удаляем память текущей вершины стека
    top_node = new_top_node; //задаем новой вершиной следующий элемент стека
    count--; // уменьшаем размер стека, т.к. один элемент был удален
    return result; // возвращаем значение которое было в вершине стека
}

template<typename T>

bool Stack<T>::IsEmpty() //пусть ли стек
{
    return count == 0; // если размер стека пуст
}


#endif // STACK_H
