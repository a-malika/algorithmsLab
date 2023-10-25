#include <iostream>
#include <string>

std::string add_stars(std::string &str, int n);

int main(){
    int i = 0;
    std::string str;
    getline(std::cin, str);
    std::cout << add_stars(str, i);
    return 0;
}

std::string add_stars(std::string &str, int n){
    if(n < str.size() - 1){
        str = str.substr(0, n + 1) + '*' + str.substr(n + 1, str.size() + n);
        return add_stars(str, n + 2);
    }
    else{
        return str;
    }
}