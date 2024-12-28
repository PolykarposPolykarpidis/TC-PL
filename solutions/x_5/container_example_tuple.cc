#include<iostream>
#include<tuple>

int main(int argc, char* argv[]){
    std::tuple<int,std::string, double> example {
        std::stoi(argv[1]),
        argv[2],
        std::stod(argv[3])
    };

    std::cout
            <<"arg0: "<<std::get<0>(example)<<'\n'
            <<"arg1: "<<std::get<1>(example)<<'\n'
            <<"arg2: "<<std::get<2>(example)<<'\n';

    return 0;
}