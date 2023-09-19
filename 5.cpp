#include <iostream>
#include <cstdlib>

void func(int *&mas, int &size, int *block, int razmer, int index);
int main()
{
    // инициализация генератора рандомных чисел
    srand(time(0));

    // создание массива и выведение его на экран
    int m = rand() % 10;
    int *a{new int[m]};
    std::cout << "Изначальный массив: ";
    for (int i = 0; i < m; i++)
    {
        a[i] = rand() % 10;
        std::cout << a[i] << " ";
    }

    // создание блока и определение его размера
    int b[] = {1, 2, 3};
    int n = sizeof(b) / sizeof(b[0]);

    // выведение блока на экран
    std::cout << std::endl
              << "Блок элементов: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << b[i] << " ";
    }

    // получаем рандомный индекс, начиная с
    // которого будем вставлять блок в массив
    int x = rand() % (m + 1);
    std::cout << std::endl
              << "Индекс: " << x;

    // выполнение функции
    func(a, m, b, n, x);

    // выведение результата на экран
    std::cout << std::endl
              << "Результат присоединения: ";
    for (int i = 0; i < m; i++)
    {
        std::cout << a[i] << " ";
    }

    // освобождение памяти
    delete[] a;
    a = nullptr;
    return 0;
}
// функция вставляющая блок элементов,
// начиная с произвольного индекса массива
void func(int *&mas, int &size, int *block, int razmer, int index)
{
    // создаем новвый массив
    int k = size + razmer;
    int *newmas{new int[k]};

    // заполняем новый массив сначала старым массивом
    // а потом элементами блока
    for (int i = 0; i < index; i++)
    {
        newmas[i] = mas[i];
    }
    for (int i = 0; i < razmer; i++)
    {
        newmas[index + i] = block[i];
    }
    for (int i = 0; i < size - index; i++)
    {
        newmas[index + razmer + i] = mas[index + i];
    }

    // освобождаем память старого массива
    // и даем адрес на новый массив
    delete[] mas;
    mas = newmas;
    newmas = nullptr;

    // с адресом делаем похожую штуку
    size = k;
}