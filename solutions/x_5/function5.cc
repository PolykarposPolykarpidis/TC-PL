#include <iostream>
#include <vector>
#include <algorithm> // For std::transform


int foo(int x) { return x*x; }

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<int> example(numbers.size());

    std::transform(numbers.begin(), numbers.end(), example.begin(), &foo);

    for (int num : example) std::cout << num << " ";
    
    return 0;
}

