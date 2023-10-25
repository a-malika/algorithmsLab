#include <iostream>
#include <string>

char search_max(std::string str, int n, char &k);

int main(){
    char max_number = 0;
    std::string str;
    getline(std::cin, str);
    std::cout << search_max(str, str.size(), max_number);
    return 0;
}

char search_max(std::string str, int n, char &k){
    if(n >= 1){
        if(k < str[n - 1]){k = str[n - 1];}
        return search_max(str, n - 1, k);
    }
    else{
        return k;
    }
}