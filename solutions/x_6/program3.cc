/*
 * Time a loop. Write out the time in milliseconds.
 * Do this for the default setting of your compiler
 * and for a setting using an optimizer (e.g., −O2 or "release").
 * Be careful not to have the optimizer eliminate your whole loop
 * as dead code because you did not use a result.*/

#include<iostream>
#include<chrono>


int main(){

    const std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    
    for(int i=0;i!=100;++i){
        std::cout<<"Hello ";
    }
    std::cout<<std::endl;
    
    const std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
   
    const auto d = std::chrono::duration_cast<std::chrono::milliseconds>(end-start) ;
 
    std::cout<< "time spand: "<< d << " milliseconds\n";
 
    return 0;
}
