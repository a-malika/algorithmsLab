// ListNode.h

#ifndef LISTNODE_H
#define LISTNODE_H

template <class T>
class ListNode
{
public:
	T val;
	ListNode *next;
	// Инициализация конструктора без параметров
	ListNode();
	// Конструктор с параметром данных
	ListNode(T);
	// Конструктор с параметром данных и указателем на следующий элемент списка
	ListNode(T, ListNode *);
};

#endif // LISTNODE_H