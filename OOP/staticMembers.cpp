#include <iostream>


class Complex{

public:
    Complex(int re = 0, int img = 0){
        this -> re = re;
        this -> img = img; 
        ++ num_complex;
    }
    static int getNumComplex ();

    // int num_complex = 0; 

private:

    static int num_complex; //counter to count instance made 
    double re,img;

};

    int Complex::num_complex = 0;

    int Complex::getNumComplex(){

        return Complex::num_complex;
     }






int main(){

Complex z1(1,2);
Complex z2(2,3);
Complex z3;
Complex z4;

std::cout<<"Number of Complexes(elegant): "<< Complex::getNumComplex()<<std::endl; //static make the function be accessed without object 
std::cout<<"Number of Complexes(non-elegant): "<< z1.getNumComplex()<<std::endl;


    return 0;
}