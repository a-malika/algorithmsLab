#include <iostream>

#include <iostream>

int fibonachi(int number, int a, int b);

int main(){
    int n, a = 0, b = 1;
    std::cin >> n;
    std::cout << fibonachi(n, a, b); 
    return 0;
}

int fibonachi(int number, int a, int b){
    if(number != 0){
        return fibonachi(number - 1, b, a + b);
    }
    else{
        return a;
    }
}