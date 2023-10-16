#include "ListNode.h"

template <class T>
ListNode<T>::ListNode() : val(0), next(nullptr) {}

// Конструктор с параметром данных
template <class T>
ListNode<T>::ListNode(T x) : val(x), next(nullptr) {}

// Конструктор с параметром данных и указателем на следующий элемент списка
template <class T>
ListNode<T>::ListNode(T x, ListNode *next) : val(x), next(next) {}
