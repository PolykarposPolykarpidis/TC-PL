#include<iostream>
#include<string>
#include<tuple>
#include<vector>

struct characteristics{
    bool has_char = false;
    bool has_dot = false;
    bool has_digit = false;
};

struct type_ {
    const char* name;
};


characteristics find_characteristics(char* obj){
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


type_ find_type(characteristics& characteristic){
    type_ type_obj;
    if (characteristic.has_char) {
        type_obj.name = "str";
    }
    else if (characteristic.has_dot) {
        type_obj.name = "double";
    }
    else {
        type_obj.name = "int";
    }
    return type_obj;
}


int main(int argc, char* argv[]){
    std::vector<type_> v_type;
    
    for(int i=1;i!=argc;++i){
        characteristics characteristic = find_characteristics(argv[i]);
        type_ a_type = find_type(characteristic);
        v_type.push_back(a_type);
    }
    

    return 0;
}