#include<iostream>
#include<vector>
#include<algorithm>

int main(){

    std::vector<int> v1 = {4,5,2,-23,1};

    std::sort(v1.begin(), v1.end());

    for(int& i: v1){
        std::cout<<i<<'\n';
    }    

    return 0;
}
