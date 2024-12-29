# TC-PL
My solutions for the exercise and examples from Bjarne Stroustrup's book "The C++ Programming Language" (4th edition).

# I wand to read

## If you want to add values of different types in a container whose the types you know in run time (not in compile time) you have to use one of the following two techiques
- (Dionysis 1) Abstract base class and inheritance, and pointer from the abstract class to the container
- (Dionysis 2) std::variant to the container  with different types

## Also from ChatGPT
### Option 1: Using std::tuple<std::variant<...>>
If you know the potential types at compile time but want the ability to store different types dynamically, you can use `std::variant` within a `std::tuple`. `std::variant` is a type-safe union that can hold one of several predefined types.

```cpp
#include <iostream>
#include <tuple>
#include <variant>
#include <string>

// Define a tuple with dynamic types using std::variant
using DynamicTuple = std::tuple<std::variant<int, double, std::string>>;

int main() {
    DynamicTuple myTuple = std::make_tuple(std::variant<int, double, std::string>("Hello"));

    // Access the first element
    std::variant<int, double, std::string> value = std::get<0>(myTuple);

    // Determine which type is currently held
    if (std::holds_alternative<std::string>(value)) {
        std::cout << "String: " << std::get<std::string>(value) << std::endl;
    }

    return 0;
}
```
Pros:
- Allows type safety.
- Efficient and straightforward for a known set of possible types.
Cons:
- You must know the set of possible types at compile time.

### Option 2: Using std::tuple<std::any>
If you don't know the types at compile time and need maximum flexibility, you can use `std::any`. `std::any` can hold any type of object, but type checking and retrieval require you to know the exact type at runtime.
```cpp
#include <iostream>
#include <tuple>
#include <any>
#include <string>

// Define a tuple with dynamic types using std::any
using DynamicTuple = std::tuple<std::any, std::any, std::any>;

int main() {
    // Create a tuple with different types of elements
    DynamicTuple myTuple = std::make_tuple(42, 3.14, std::string("Hello"));

    // Access elements with std::get
    try {
        int intValue = std::any_cast<int>(std::get<0>(myTuple));
        double doubleValue = std::any_cast<double>(std::get<1>(myTuple));
        std::string strValue = std::any_cast<std::string>(std::get<2>(myTuple));

        std::cout << "Integer: " << intValue << std::endl;
        std::cout << "Double: " << doubleValue << std::endl;
        std::cout << "String: " << strValue << std::endl;
    } catch (const std::bad_any_cast& e) {
        std::cerr << "Bad any_cast: " << e.what() << std::endl;
    }

    return 0;
}
```

Pros:
- Can hold objects of any type.
- Flexible and does not require a predefined set of types.
Cons:
- Runtime type checking (std::any_cast) is required, which may throw exceptions.
- Less efficient than std::variant because it involves dynamic memory allocation for non-trivially copyable types.

### Option 3: Combining `std::tuple` with `std::unique_ptr` or `std::shared_ptr`
If you need polymorphism or dynamic typing for custom types, you can store `std::unique_ptr` or `std::shared_ptr` to base class objects in the tuple.
```cpp
#include <iostream>
#include <tuple>
#include <memory>

// Base class
struct Base {
    virtual void print() const = 0;
    virtual ~Base() = default;
};

// Derived classes
struct Derived1 : Base {
    void print() const override { std::cout << "Derived1" << std::endl; }
};

struct Derived2 : Base {
    void print() const override { std::cout << "Derived2" << std::endl; }
};

int main() {
    // Create a tuple of pointers to Base
    std::tuple<std::unique_ptr<Base>, std::unique_ptr<Base>> myTuple = {
        std::make_unique<Derived1>(),
        std::make_unique<Derived2>()
    };

    // Access and call the objects
    std::get<0>(myTuple)->print();
    std::get<1>(myTuple)->print();

    return 0;
}
```
Pros:
- Supports polymorphism with custom types.
- Safe and efficient memory management using smart pointers.
Cons:
- Requires a common base class for polymorphic types.
- Slightly more complex to implement.


When to Use Each Approach
- std::variant in std::tuple:
 - Use when you know the set of possible types at compile time and want type-safe access.
- std::any in std::tuple:
 - Use when you don't know the types at compile time or need maximum flexibility.
- Smart pointers in std::tuple:
 - Use when working with polymorphic custom types or when dynamic memory allocation is required.


## This is something else and it's about 
- [Curiously Recurring Template Pattern](https://en.cppreference.com/w/cpp/language/crtp)
