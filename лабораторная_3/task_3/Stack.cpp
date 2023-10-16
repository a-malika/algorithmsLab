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

bool is_right(const std::string &s);
int main()
{
    std::string s;
    std::cout << "Введите скобочную последовательность:" << std::endl;
    std::cin >> s;

    if(is_right(s)){
        std::cout << "YES";
    }
    else{
        std::cout << "NO";
    }

    return 0;
}

bool is_right(const std::string &stroka){
    Stack<char> stack;

    for(char i : stroka){
        if(i == '(' || i == '{' || i == '['){
            stack.push(i);
        }
        else{
            if (stack.empty())
                return false;
            char elem = stack.pop();
            if ((i == ')' && elem != '(') ||
                (i == '}' && elem != '{') ||
                (i == ']' && elem != '['))
            {
                return false;
            }
        }
    }

    return stack.empty();
}