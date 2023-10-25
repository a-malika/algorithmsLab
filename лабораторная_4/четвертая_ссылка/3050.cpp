#include <iostream>

void hanoi(int n, int a, int b, int c);

int main(){
    int n, a = 1, b = 2, c = 3;
    std::cin >> n;
    hanoi(n, a, b, c);
    return 0;
}

void hanoi(int n, int a, int b, int c){
    if(n == 1){std::cout << n << " " << a << " " << c << std::endl;}
    else{
        hanoi(n - 1, a, c, b);
        std::cout << n << " " << a << " " << c << std::endl;
        hanoi(n - 1, b, a, c);
    }
}