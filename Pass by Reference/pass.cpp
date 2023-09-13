#include <iostream>

int f1(int x) {
    //pass by variable and function make a copy from it 
    x = x + 1; 
    return x;
}
void f2(int& x) {
    //pass by reference
    //work on the original variable
    x = x + 1;
}
void f3(const int& x) {
    //function work on the original variable but cannot modify it 
    //pass by constant refernece
    // x = x + 1 ;error 
    // std::cout<< x <<std::endl; //6
}
void f4(int *x) {
    //pass by pointer 
    //work on the original variable
    *x = *x + 1;
}

int main(){
    int y = 5;
    f1(y);
    std::cout<<y<<std::endl; //5
    f2(y);
    std::cout<<y<<std::endl; //6
    f3(y);                  
    f4(&y);
    std::cout<<y<<std::endl; //7


return 0 ;

}