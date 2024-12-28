#include<iostream>
#include<string>
#include<tuple>

struct characteristics{
    bool has_char = false;
    bool has_dot = false;
    bool has_digit = false;
};

characteristics find_the_type(char* obj){
    characteristics character;
    char* c = obj;
    while(*c != '\0'){
        if(isdigit(*c)) character.has_digit = true;
        else if(*c == '.') character.has_dot = true;
        else if(isalpha(*c)) character.has_char = true;
        else throw;
        c++;
    }

    return character;
}



int main(int argc, char* argv[]){

    std::cout<<argv[2]<<'\n';
    characteristics temp = find_the_type(argv[2]);
    std::cout
            <<"has_char "<< temp.has_char <<'\n'
            <<"has_dot "<< temp.has_dot <<'\n'
            <<"has_digit "<< temp.has_digit <<"\n\n";



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