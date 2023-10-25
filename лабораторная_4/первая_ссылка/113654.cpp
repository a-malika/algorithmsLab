#include <iostream>
#include <string>

int amount_of_digits(std::string str, int n, int k);
bool is_digit(char simbol);

int main(){
    int kolvo = 0;
    std::string str;
    getline(std::cin, str);
    std::cout << amount_of_digits(str, str.size(), kolvo);
    return 0;
}

int amount_of_digits(std::string str, int n, int k){
    if(n >= 1){
        if(is_digit(str[n-1])){
            k++;
        }
        return amount_of_digits(str, n - 1, k);
    }
    else{
        return k;
    }
}

bool is_digit(char symbol){
    if (symbol >= '0' && symbol <= '9'){ return true;}
    else {return false;}
}