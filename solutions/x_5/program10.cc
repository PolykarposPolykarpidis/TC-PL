/* Open the file of integers from §X.5[9] 
 * for reading (as an ifstream) and read it.
 */

#include<iostream>
#include<fstream>

int main(){
    std::string str;

    std::ifstream myfile;
    myfile.open("temp.txt");
    if(myfile.is_open()){
        while(myfile){
            std::getline(myfile,str);
            std::cout<<str<<' ';
        }
        std::cout<<str<<'\n';
    }
    else{
        std::cerr<<"error!\n";
    }
    
    
    return 0;
}
