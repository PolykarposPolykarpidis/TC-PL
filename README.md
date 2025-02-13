# TC-PL
My solutions for the exercise and examples from Bjarne Stroustrup's book "The C++ Programming Language" (4th edition).

# I wand to read

## If you want to add values of different types in a container whose the types you know in run time (not in compile time) you have to use one of the following two techiques
- (Dionysis 1) Abstract base class and inheritance, and pointer from the abstract class to the container
- (Dionysis 2) std::variant to the container  with different types

## from ChatGPT, Dionysis 1 solution
```cpp
#include <iostream>
#include <tuple>
#include <memory>
#include <string>
#include <vector>




// Base class for dynamic types
class DynamicBase {
public:
    virtual void print() const = 0;       // Pure virtual function to print
    virtual ~DynamicBase() = default;     // Virtual destructor
};



class DynamicInt : public DynamicBase {
public:
    explicit DynamicInt(int value) : value(value) {}
    void print() const override {
        std::cout << "DynamicInt: " << value << std::endl;
    }
private:
    int value;
};

class DynamicDouble : public DynamicBase {
public:
    explicit DynamicDouble(double value) : value(value) {}
    void print() const override {
        std::cout << "DynamicDouble: " << value << std::endl;
    }
private:
    double value;
};

class DynamicString : public DynamicBase {
public:
    explicit DynamicString(const std::string& value) : value(value) {}
    void print() const override {
        std::cout << "DynamicString: " << value << std::endl;
    }
private:
    std::string value;
};

class DynamicUserType : public DynamicBase {
public:
    DynamicUserType(const std::string& name, int id) : name(name), id(id) {}
    void print() const override {
        std::cout << "DynamicUserType{name: " << name << ", id: " << id << "}" << std::endl;
    }
private:
    std::string name;
    int id;
};

int main() {
    // Step 1: Create a tuple with smart pointers to the base class
    std::tuple<
        std::unique_ptr<DynamicBase>, 
        std::unique_ptr<DynamicBase>, 
        std::unique_ptr<DynamicBase>, 
        std::unique_ptr<DynamicBase>
    > myTuple;

    // Step 2: Populate the tuple with various dynamic types
    myTuple = std::make_tuple(
        std::make_unique<DynamicInt>(42),                      // int
        std::make_unique<DynamicDouble>(3.14159),              // double
        std::make_unique<DynamicString>("Hello, Tuple!"),      // std::string
        std::make_unique<DynamicUserType>("Alice", 101)        // User-defined type
    );

    // Step 3: Access and use the elements dynamically
    std::get<0>(myTuple)->print(); // Prints "DynamicInt: 42"
    std::get<1>(myTuple)->print(); // Prints "DynamicDouble: 3.14159"
    std::get<2>(myTuple)->print(); // Prints "DynamicString: Hello, Tuple!"
    std::get<3>(myTuple)->print(); // Prints "DynamicUserType{name: Alice, id: 101}"

    return 0;
}
```

When to Use Each Approach
- std::variant in std::tuple:
 - Use when you know the set of possible types at compile time and want type-safe access.
- std::any in std::tuple:
 - Use when you don't know the types at compile time or need maximum flexibility.
- Smart pointers in std::tuple:
 - Use when working with polymorphic custom types or when dynamic memory allocation is required.


## This is something else
- [Curiously Recurring Template Pattern](https://en.cppreference.com/w/cpp/language/crtp)
