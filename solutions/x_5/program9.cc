/* Open a file for writing (as an ofstream) 
 * and write a few hundred integers to it.*/

#include<iostream>
#include<fstream>

int main(){
    
    std::ofstream outputFile("temp.txt");
    
    if(outputFile.is_open()){
    
        for(size_t i=0;i!=100;++i)
            outputFile << std::rand() <<" ";

        outputFile.close();
    }
    else { std::cerr<< "error"; }

    return 0;
}
