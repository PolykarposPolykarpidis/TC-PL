/*
 * Write a program that reads a name (a string) and an age (an int) from the standard
 * input stream cin. Then output a message including the name and age to the standard
 * output stream cout.
*/

#include<string>
#include<iostream>

int main(){

    std::string name, s;
    int age;

    std::cout<<"Type a name: ";
    std::cin>>name;

    std::cout<<"Type an age: ";
    std::cin>>s;
    age = std::stoi(s);


    std::cout<<"Your name is " <<name<<" and you are "<< age << " years old!\n";

    return 0;
}
