#include <iostream>
#include <cstdlib>

bool nalichie(int *mas, int razmer, int elem);
int main()
{
    // инициализация генератора рандомных чисел
    srand(time(0));

    // получаем размеры массивов A и B
    int m, n;
    std::cout << "Введите размер массива A:";
    std::cin >> m;
    std::cout << "Введите размер массива B:";
    std::cin >> n;

    // создаем массивы A и B
    int *a{new int[m]};
    int *b{new int[n]};

    // заполняем массивы A и B
    /*
    std::cout << "Введите массив A: ";
    for (int i = 0; i < m; i++)
    {
        std::cin >> a[i];
    }
    std::cout << "Введите массив B: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    */

    std::cout << "Массив A: ";
    for (int i = 0; i < m; i++)
    {
        a[i] = rand() % 10;
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Массив B: ";
    for (int i = 0; i < n; i++)
    {
        b[i] = rand() % 10;
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    // создание массива с элементами массива A,
    // которые не включаются в массив B(без повторов)
    int k = m, j = 0;
    int *c{new int[k]};

    // указатель для нулевого значения
    int y = 0;

    // нахождение элементов массива A,
    // которые не включаются в массив B(без повторов)
    for (int i = 0; i < m; i++)
    {
        if (!nalichie(b, n, a[i]) && !nalichie(c, k, a[i]))
        {
            c[j] = a[i];
            j++;
        }
        else if (!a[i] && !y && !nalichie(b, n, a[i]))
        {
            c[j] = a[i];
            j++;
            y++;
        }
    }

    // уменьшение размера итогового массива
    int *newc{new int[j]};
    for (int i = 0; i < j; i++)
    {
        newc[i] = c[i];
    }
    delete[] c;
    c = newc;
    newc = nullptr;

    // выведение результата на экран
    std::cout << "Массив с элементами массива A, которые не включаются в массив B: ";
    for (int i = 0; i < j; i++)
    {
        std::cout << c[i] << " ";
    }

    // освобождение памяти
    delete[] a;
    a = nullptr;
    delete[] b;
    b = nullptr;
    delete[] c;
    c = nullptr;
    return 0;
}
// функция определяющая есть ли элемент в массиве
bool nalichie(int *mas, int razmer, int elem)
{
    for (int i = 0; i < razmer; i++)
    {
        if (elem == mas[i])
            return true;
    }
    return false;
}