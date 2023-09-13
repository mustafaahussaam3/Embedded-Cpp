/*
                                         ***friend function and friend class***

    A friend class can access private and protected members of other classes in which it is declared as a friend. 
    It is sometimes useful to allow a particular class to access private and protected members of other classes. 
    For example, a LinkedList class may be allowed to access private members of Node.

    

*/

#include <iostream>

class base {

private: 
    int private_variable;

protected:
    int protected_variable;
public:
    base(){
        private_variable = 10;
        protected_variable = 20;
    }
    int x = 1;
    friend class F; //We can declare friend class or function anywhere in the base class body whether its private, protected or public block. It works all the same.

};

class F {

public: 
    void display (base& t){ //base& t = b;
        std::cout << "the value of Private Variable = " << t.private_variable << std::endl; //same as protected
        std::cout << "the value of protected Variable = " << t.protected_variable << std::endl;
         //will not work with the protected without telling the base that it has a friend
        std::cout << "the value of the public variable is " << t.x << std::endl;   //will work with public variables 
    }

};


int main(){
    base b;
    F fri;
    fri.display(b);
return 0;
}