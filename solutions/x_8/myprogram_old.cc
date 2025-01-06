#include<iostream>
#include<string>

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
    return os << "int="<<c.get_integer()<<" double="<<c.get_double()<<" string="<<c.get_string();
}





class Node{
public:
    Node(Cargo c, Node* r = nullptr, Node* l = nullptr, bool own_r = false, bool own_l = false)
        :cargo{c}, right{r}, left{l}, owns_right{own_r}, owns_left{own_l} {}


    ~Node(){
        if(owns_right) delete right;
        if(owns_left) delete left;
    }

    Node* get_right_child(){ return right; }
    Node* get_left_child(){ return left; }
    Cargo get_cargo() { return cargo; }


private:
    Cargo cargo;
    Node* right;
    Node* left;
    bool owns_right;
    bool owns_left;
};





int main(){

    Cargo c_cargo{1, 1.1, "1"};
    Cargo r_cargo{2, 2.2, "2r"};
    Cargo l_cargo{3, 3.3, "3l"};
    
    Node* r_node = new Node(r_cargo);
    Node* l_node = new Node(l_cargo);
    Node* c_node = new Node(c_cargo, r_node, l_node, true, true);
    
        
    std::cout<<c_node->get_right_child()->get_cargo()<<'\n';

    delete c_node;

    //std::cout<<r_node->get_cargo()<<'\n';

    return 0;
}
