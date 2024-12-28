#include<iostream>

std::pair<int, int>& argv_to_pair(int argc, char* argv[]){
    int first, second;
    switch (argc)
    {
    case 1:
        first = std::rand();
        second = std::rand();
        break;
    case 2:
        first = std::stoi(argv[1]);
        second = 0;
        break;
    case 3:
        first = std::stoi(argv[1]);
        second = std::stoi(argv[2]);
        break;
    default:
        std::cout << "too many arguments";
        break;
    }
    static std::pair<int,int> arguments {first,second};
    return arguments;
}



int main(int argc, char* argv[]){

    std::pair<int, int>& args = argv_to_pair(argc, argv);

    std::cout
            <<"arg.first: "<<args.first<<'\n'
            <<"arg.second: "<<args.second<<'\n';

    return 0;
}