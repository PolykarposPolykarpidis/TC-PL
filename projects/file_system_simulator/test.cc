#include<iostream>
#include"file.h"

//using namespace fs;

int main(){
    
    fs::File f1 {"name1", 16};
    
    std::cout<< f1<<'\n'; 
    std::cout<< f1.get_info()<<'\n';

    return 0;
}
