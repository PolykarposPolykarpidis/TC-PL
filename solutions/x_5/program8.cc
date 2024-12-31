/*
 * Repeat §X.5[7] with a vector<string> initialized with 
 * "Kant", "Plato", "Aristotle", "Kierkegard", and "Hume".
 */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    std::vector<std::string> vs {"Kant", "Plato", "Aristotle", "Kierkegard","Hume"};
    
    std::sort(vs.begin(),vs.end());

    for(std::string str: vs)
        std::cout<<str<<'\t';

    std::cout<<std::endl;

    return 0;
}
