#include<iostream>

class My_class{
public:
    My_class(int v)
        :x{v}{}
    
    operator int(){
        return x;
    }

    int get_x() const {
        return x;
    }
private:
    int x;
};



int main(){
    int i = 7;
    My_class obj1{4};
    int j {obj1};

    std::cout<<i<<'\t'<<j<<'\t'<<obj1.get_x()<<'\n';


    return 0;
}