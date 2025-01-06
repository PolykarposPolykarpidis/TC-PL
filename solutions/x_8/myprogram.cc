#include<iostream>
#include<string>
#include<memory>

struct Cargo{
public:
    Cargo(int i, double d, std::string s)
        :an_integer{i}, a_double{d}, a_string{s} {}
    
    int get_integer() const { return an_integer; }
    double get_double() const { return a_double; }
    std::string get_string() const { return a_string; } 

private:
    int an_integer;
    double a_double;
    std::string a_string;
};



std::ostream& operator<<(std::ostream& os, const Cargo& c){
    return os 
            << "int="<<c.get_integer()
            <<" double="<<c.get_double()
            <<" string="<<c.get_string();
}





class Node{
public:
    Node(Cargo c, std::unique_ptr<Node> r = nullptr, std::unique_ptr<Node> l = nullptr)
        :cargo{c}, right{std::move(r)}, left{std::move(l)} {}

    
    
private:
    Cargo cargo;
    std::unique_ptr<Node> right;
    std::unique_ptr<Node> left;
};





int main(){

    Cargo c_cargo{1, 1.1, "1"};
    Cargo r_cargo{2, 2.2, "2r"};
    Cargo l_cargo{3, 3.3, "3l"}; 
    
    auto r_node = std::make_unique<Node>(r_cargo);
    auto l_node = std::make_unique<Node>(l_cargo);
    auto c_node = std::make_unique<Node>(c_cargo, std::move(r_node), std::move(l_node));
    
    
    return 0;
}
