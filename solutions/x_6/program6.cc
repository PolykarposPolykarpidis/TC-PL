/* Use a reg ex to find all decimal numbers in a file.*/

#include<iostream>
#include<fstream>
#include<string>
#include<regex>


int main(){
    std::regex const my_pattern {R"(\d+\.\d*)"};
    std::string str;
    std::ifstream myfile;
    myfile.open("find_decimal");
    
     
    if(!myfile.is_open()){
        std::cerr<<"Error: Couldn't open the file!\n";
        return 1;
    }
    
    while(std::getline(myfile, str)){
        
        std::sregex_iterator begin(str.begin(), str.end(), my_pattern);
        std::sregex_iterator end;

        for(auto it=begin; it!=end; it++){
            std::cout<< it->str() <<'\n';
        }
            
    }
    
    myfile.close();    
    
    return 0;
}
