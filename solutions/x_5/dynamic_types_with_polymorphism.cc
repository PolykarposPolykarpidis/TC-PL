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
