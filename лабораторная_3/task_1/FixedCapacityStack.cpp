#include <iostream>
#include "FixedCapacityStack.h"

// Конструктор: создать пустой динамический массив с размером, равным переданному аргументу; проинициализировать число элементов в Стеке
template <typename T>
FixedCapacityStack<T>::FixedCapacityStack(int capacity)
{
    max_size = capacity;
    n = 0;
    a = new T[capacity];
}
// Деструктор: освободить память массива (delete)
template <typename T>
FixedCapacityStack<T>::~FixedCapacityStack()
{
    delete[] a;
    a = nullptr;
}
// Проверка на пустоту стека
template <typename T>
bool FixedCapacityStack<T>::empty() const
{
    return n == 0;
}
// Проверка на полноту стека
template <typename T>
bool FixedCapacityStack<T>::full() const
{
    return n == max_size;
}
// Добавить элемент в стек
template <typename T>
void FixedCapacityStack<T>::push(const T &item)
{
    if (n < max_size)
    {
        a[n++] = item;
    }
    else
    {
        std::cout << "Стек переполнен. Невозможно добавить элемент." << std::endl;
    }
}
// Удалить вершину стека
template <typename T>
T FixedCapacityStack<T>::pop()
{
    if (!empty())
    {
        return a[--n];
    }
    else
    {
        std::cout << "Стек пуст. Невозможно удалить элемент." << std::endl;
        return T();
    }
}
// Вернуть значение вершины стека
template <typename T>
T FixedCapacityStack<T>::top() const
{
    if (!empty())
    {
        return a[n - 1];
    }
    else
    {
        std::cout << "Стек пуст. Нет элементов для возврата." << std::endl;
        return T();
    }
}
// Перегрузка оператора << для вывода элементов стека через cout
template <typename U>
std::ostream &operator<<(std::ostream &os, const FixedCapacityStack<U> &st)
{
    os << "Стек: ";
    for (int i = st.n - 1; i >= 0; --i)
    {
        os << st.a[i] << " ";
    }
    return os;
}

int main()
{
    FixedCapacityStack<int> mystack = FixedCapacityStack<int>(10);

    for (int i = 1; i <= 10; ++i)
    {
        mystack.push(i);
    }

    std::cout << mystack << std::endl;

    mystack.push(11);
    if (mystack.full())
    {
        for (int i = 1; i <= 4; ++i)
        {
            mystack.pop();
        }
    }
    std::cout << mystack << std::endl;
    if (!mystack.empty())
    {
        std::cout << "Вершина стека в итоге: " << mystack.top() << std::endl;
    }
    return 0;
}