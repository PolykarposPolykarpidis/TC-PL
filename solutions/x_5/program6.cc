/*
 * Redo 5, storing several (name,age) pairs in a class.
 * Doing the reading and writing using your own >> and << operators
 */

#include<string>
#include<iostream>

class Pair{
public:
    Pair(std::string n, int a)
        :name{n}, age{a}{}

    Pair(){}

    std::string getName() const{
        return name;
    }
    int getAge() const{
        return age;
    }

    friend std::istream& operator>>(std::istream& is, Pair& pair_obj){
        std::cout<<"What is your name? ";
        is >> pair_obj.name;
        std::cout<<"How old are you? ";
        is >> pair_obj.s;
        pair_obj.age = std::stoi(pair_obj.s);
        return is;
    }

private:
    std::string name, s;
    int age;
};

std::ostream& operator<<(std::ostream& os, Pair p){
    return os <<"My name is " << p.getName() << " and I am " << p.getAge() << " years old.\n";
}

int main(){
    Pair obj;
    std::cin>>obj;
    
    std::cout<<obj;
    
    return 0;
}
