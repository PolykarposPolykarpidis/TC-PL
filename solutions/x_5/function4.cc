#include<iostream>
#include<vector>
#include<numeric>

int main(){
    std::vector<int> v1 = {2,5,2,6,-23,0,1};

    int sum_ = std::accumulate(v1.begin(), v1.end(), 0);

    std::cout<<sum_<<'\n';

    return 0;
}
