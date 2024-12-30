#include<iostream>
#include<array>


int main(){

    std::array<std::array<int,2>, 3> m2 = {{
                    {1,2}, {3,4},{5,6}
    }};

    for(size_t i=0;i!=3;++i){
        for(size_t j=0;j!=2;++j){
            std::cout<<m2[i][j]<<'\t';
        }
    std::cout<<'\n';
    }
}
