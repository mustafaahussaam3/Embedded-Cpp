/*
                                                             **Static Member**

    *Only one copy of that member is created for the entire class and is shared by all the objects of that class, no matter how many objects are created.
    *It is initialized before any object of this class is created, even before the main starts.
    *Static members are only declared in a class declaration, not defined. They must be explicitly defined outside the class using the scope resolution operator.
    *Static data members can only be defined globally in C++. 
        The only exception to this are static const data members of integral type which can be initialized in the class declaration.
    *We can access any static member without any object by using the scope resolution operator directly with the class name.
    *In C++, we cannot declare static data members in local classes.

                                                        **Static Member Function**
    *A static member function is independent of any object of the class. 
    *A static member function can be called even if no objects of the class exist.
    *A static member function can also be accessed using the class name through the scope resolution operator.
    ****A static member function can access static data members and static member functions inside or outside of the class.
    *Static member functions have a scope inside the class and cannot access the current object pointer.
    *You can also use a static member function to determine how many objects of the class have been created.


 static members is created in memory even if we don't make instance of the class so, we can use it without using the class.
*/

#include <iostream>


class Complex{

public:
    Complex(int re = 0, int img = 0){
        this -> re = re;
        this -> img = img; 
        ++ num_complex;
    }
    static int getNumComplex (){
        return num_complex;
    }
    //  static int zeros();
    // int num_complex = 0;  //Error 

private:

    static int num_complex; //counter to count instance made 
    double re,img;

};

    int Complex::num_complex = 0;

// int Complex::getNumComplex(){

//     return Complex::num_complex;
//  }

//  int Complex::zeros(){
//     Complex::num_complex = 0;
//     return 1;
// }



int main(){

Complex z1(1,2);
Complex z2(2,3);
Complex z3;
Complex z4;

//Complex::num_complex = 0;
std::cout<<"Number of Complexes(elegant): "<< Complex::getNumComplex()<<std::endl; //static make the function be accessed without object 
std::cout<<"Number of Complexes(non-elegant): "<< z1.getNumComplex()<<std::endl;


    return 0;
}