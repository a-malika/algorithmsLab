#include <iostream>

#ifndef FIXEDCAPACITYSTACK_H
#define FIXEDCAPACITYSTACK_H

template <typename T>
class FixedCapacityStack
{
private:
    T *a;         // массив, содержащий элементы Стека
    int n;        // количество элементов в Стеке
    int max_size; // максимальная вместимость стека
public:
    // Конструктор: создать пустой динамический массив с размером, равным переданному аргументу; проинициализировать число элементов в Стеке
    FixedCapacityStack(int capacity);
    // Деструктор: освободить память массива (delete)
    ~FixedCapacityStack();
    // Проверка на пустоту стека
    bool empty() const;
    // Проверка на полноту стека
    bool full() const;
    // Добавить элемент в стек
    void push(const T &item);
    // Удалить вершину стека
    T pop();
    // Вернуть значение вершины стека
    T top() const;
    // Перегрузка оператора << для вывода элементов стека через cout
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const FixedCapacityStack<U> &st);
}; // FixedCapacityStack

#endif