#include <iostream>
#include "ListNode/ListNode.cpp"

#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
private:
    ListNode<T> *first; // указатель на вершину Стека
    int n;              // количество элементов в Стеке
public:
    // Конструктор: инициализация пустого Стека
    Stack();
    // Проверка на пустоту стека
    bool empty() const;
    // Вернуть размер стека
    int size();
    // Добавить элемент в стек
    void push(const T &item);
    // Удалить вершину стека
    T pop();
    // Вернуть значение вершины стека
    T top() const;
    // Перегрузка оператора << для вывода элементов стека через cout
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Stack<U> &st);
}; // Stack

#endif // STACK_H
