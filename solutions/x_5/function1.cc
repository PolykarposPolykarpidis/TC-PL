#include<iostream>
#include<string>




int main(){
    
    std::string s = "5";

    int i = std::stoi(s);
    i++;

    std::cout<< i <<'\n';

    return 0;
}
