/* Write a program with two treads:
 * one that writes hello every second
 * and one that writes world! every second.
 */

#include<iostream>
#include<thread>
#include<chrono>

void foo(){
    for(int i=0;i!=10;++i){
        std::cout<<"Hello";
        std::this_thread::sleep_for(std::chrono::seconds(1)); 
    }
}

void foo2(){
    for(int i=0;i!=10;++i){
        std::cout<<" World!\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(){
    std::thread t1{foo};
    std::thread t2{foo2};
    t1.join();
    t2.join();
    
    return 0;
}
