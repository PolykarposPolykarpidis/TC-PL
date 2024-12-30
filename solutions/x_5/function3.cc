#include<iostream>
#include<vector>
#include<algorithm>

int main(){

    std::vector<int> v1 = {4,5,2,-23,1};

    auto pos = std::find(v1.begin(),v1.end(), -23);

    std::cout<<std::distance(v1.begin(),pos)<<'\n';


    return 0;
}
