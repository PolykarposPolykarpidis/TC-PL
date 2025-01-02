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
    size_t sum = 0;
    for(int i=0;i!=1000000;++i){
        sum += i;
    }
    
    const auto end = std::chrono::steady_clock::now();
   
    std::cout
            << "time spand: "
            <<  std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count()
            <<  " milliseconds\n";
 
    return 0;
}
