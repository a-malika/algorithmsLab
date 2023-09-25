#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyLinkedList
{
public:
    MyLinkedList() : head(nullptr), size(0) {}
    size_t get_size() { return size; }
    void add_at_tail(int val);
    void add_at_index(size_t index, int val);
    void delete_at_index(size_t index);
    void add_at_head(int val);
    void print_list();
    void reverse();

private:
    ListNode *head;
    size_t size;
};

void MyLinkedList::add_at_tail(int val)
{
    ListNode *newNode = new ListNode(val, nullptr);
    ListNode *it = head;
    if (head == nullptr)
    {
        head = newNode;
        size++;
        return;
    }
    while (it->next != nullptr)
    {
        it = it->next;
    }
    it->next = newNode;
    size++;
}

void MyLinkedList::delete_at_index(size_t index)
{
    if (index >= size)
    {
        std::cout << "Index cannot be deleted with this size = " << size << std::endl;
        return;
    }
    ListNode *prev = head;
    if (index == 0)
    {
        head = head->next;
        delete prev;
        size--;
        return;
    }
    ListNode *curr = head->next;
    size_t pos = 0;
    while (pos < index - 1)
    {
        prev = prev->next;
        curr = curr->next;
        pos++;
    }
    prev->next = curr->next;
    delete curr;
    size--;
}

void MyLinkedList::add_at_index(size_t index, int val)
{
    if (index > size)
    {
        std::cout << "Index cannot be added with this size = " << size << std::endl;
        return;
    }
    ListNode *prev = head;
    if (index == 0)
    {
        ListNode *NewNode = new ListNode(val, head);
        head = NewNode;
        size++;
        return;
    }
    ListNode *curr = head->next;
    size_t pos = 0;
    while (pos < index - 1)
    {
        prev = prev->next;
        curr = curr->next;
        pos++;
    }
    ListNode *NewNode = new ListNode(val, curr);
    prev->next = NewNode;
    size++;
}

void MyLinkedList::add_at_head(int val)
{
    ListNode *NewNode = new ListNode(val, head);
    head = NewNode;
    size++;
}

void MyLinkedList::print_list()
{
    std::cout << "Linked list: ";
    ListNode *it = head;
    while (it != nullptr)
    {
        std::cout << it->val << " ";
        it = it->next;
    }
    std::cout << "\nSize: " << size << std::endl;
}

void MyLinkedList::reverse()
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main()
{
    // создание массивов
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};

    // создание связного списка(пустого)
    MyLinkedList *obj = new MyLinkedList();

    // добавление в конец связного списка каждый элемент массива
    for (int val : arr1)
    {
        obj->add_at_tail(val);
    }
    // выведение списка на экран
    obj->print_list();

    // добавление в начало связного списка каждый элемент массива
    for (int val : arr2)
    {
        obj->add_at_head(val);
    }
    // выведение списка на экран
    obj->print_list();

    // удаление элемента по индексу
    std::cout << "Deleting the element...\n";
    obj->delete_at_index(4);
    // выведение списка на экран
    obj->print_list();

    // добавление элемента по индексу
    std::cout << "Add element at index...\n";
    obj->add_at_index((size_t)2, 10);
    // выведение списка на экран
    obj->print_list();

    // переворот списка
    std::cout << "Reverse...\n";
    obj->reverse();
    // выведение списка на экран
    obj->print_list();

    return 0;
}