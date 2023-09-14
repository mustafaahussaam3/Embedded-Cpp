/*
Private: Private access specifier means that the member function or data member can only be accessed by other member functions of the same class.
Protected: A protected access specifier means that the member function or data member can be accessed by other member functions of the same class or by derived classes.
Public: Public access specifier means that the member function or data member can be accessed by any code. 

 we can say that here, the variable x and the functions get() and set() are bound together which is nothing but encapsulation.

edited by: Mustafa Hussam ELdin 
*/
#include <iostream>

class Encapsulation{
private:
    int x;

public:
    void set(int a){
        x =a;
    }

    int get(){
        return x;
    }

};

int main(){

    Encapsulation obj;
    obj.set(10);
    std::cout<<obj.get()<<std::endl;

    return 0;
}