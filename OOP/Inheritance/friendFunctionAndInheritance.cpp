/*
Difference between Inheritance and Friendship in C++: In C++, friendship is not inherited. If a base class has a friend function, then the function doesn’t become a
friend of the derived class(es). 

summary: using derived class instance with friend function give you access to all Parent class members that the friend function implented in but,
          you cannot access private and protected members in the derived class 
       class     parent + friend = all access
       function  child  + parent friend = all access to parent and no access to child 
EditedBy: Mustafa Hussam Eldin 
*/


#include <iostream>

class A {

public:
    A(){
        x = 0;
    }
    friend void show();

protected:
    int x; 

};

class B : public A{

public:
    B(){
        y = 0;
    }

private:
    int y = 0;

};

void show(){

    B b;
    std::cout<<"the default of value A::x = "<< b.x << std::endl;
    std::cout<<"the default of value B::y = "<< b.y << std::endl; //error 
}

int main(){
    show();
    getchar();
    return 0;
}