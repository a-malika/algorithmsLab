#include <iostream>
#include <cstdlib>

void func(int *&mas, int &size, int *block, int razmer);
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

    // выполнение функции
    func(a, m, b, n);

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
// функция добавляющая блок элементов в конец массива
void func(int *&mas, int &size, int *block, int razmer)
{
    // создаем новвый массив
    int k = size + razmer;
    int *newmas{new int[k]};

    // заполняем новый массив сначала старым массивом
    // а потом элементами блока
    for (int i = 0; i < size; i++)
    {
        newmas[i] = mas[i];
    }
    for (int i = 0; i < razmer; i++)
    {
        newmas[size + i] = block[i];
    }

    // освобождаем память старого массива
    // и даем адрес на новый массив
    delete[] mas;
    mas = newmas;
    newmas = nullptr;

    // с адресом делаем похожую штуку
    size = k;
}