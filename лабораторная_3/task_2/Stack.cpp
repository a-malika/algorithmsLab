#include <iostream>
#include "Stack.h"

// Конструктор: инициализация пустого Стека
template <typename T>
Stack<T>::Stack()
{
    first = nullptr;
    n = 0;
}
// Проверка на пустоту стека
template <typename T>
bool Stack<T>::empty() const
{
    return n == 0;
}
// Вернуть размер стека
template <typename T>
int Stack<T>::size()
{
    return n;
}
// Добавить элемент в стек
template <typename T>
void Stack<T>::push(const T &item)
{
    ListNode<T> *NewNode = new ListNode(item, first);
    first = NewNode;
    n++;
}
// Удалить вершину стека
template <typename T>
T Stack<T>::pop()
{
    if (!empty())
    {
        ListNode<T> *prev = first;
        first = first->next;
        T value = prev->val;
        delete prev;
        n--;
        return value;
    }
    std::cout << "Невозможно удалить вершину. Стек пустой." << std::endl;
    return T();
}
// Вернуть значение вершины стека
template <typename T>
T Stack<T>::top() const
{
    if (!empty())
    {
        return first->val;
    }
    std::cout << "Стек пустой." << std::endl;
    return T();
}
// Перегрузка оператора << для вывода элементов стека через cout
template <typename U>
std::ostream &operator<<(std::ostream &os, const Stack<U> &st)
{
    // jhriwbrfiwrfi
    os << "Стек: ";
    ListNode<U> *it = st.first;
    while (it != nullptr)
    {
        os << it->val << " ";
        it = it->next;
    }
    os << std::endl
       << "Размер стека: " << st.n << std::endl;
    return os;
}

int main()
{
    Stack<int> mystack = Stack<int>();

    for (int i = 1; i <= 10; ++i)
    {
        mystack.push(i);
    }
    // Вывод элементов стека
    std::cout << mystack << std::endl;

    for (int i = 1; i <= 5; ++i)
    {
        mystack.pop();
    }
    // Вывод элементов стека
    std::cout << mystack << std::endl;

    if (!mystack.empty())
    {
        std::cout << "Размер: " << mystack.size() << std::endl
                  << "Вершина: " << mystack.top() << std::endl;
    }
    std::cout << mystack << std::endl;

    return 0;
}