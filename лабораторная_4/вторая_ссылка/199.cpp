#include <iostream>

int nod(int a, int b);

int main(){
    int a, b;
    std::cin >> a >> b;
    std::cout << nod(a, b); 
    return 0;
}

int nod(int a, int b){
    if(b == 0){
        return a;
    }
    else {return nod(b, a % b);}
}