#include <iostream>

int** fun( int* x){

    static int *z = x;
    std::cout<<"x = "<<x<<std::endl;
    std::cout<<"*x = "<<*x <<std::endl;
    std::cout<<"&x = "<< &x <<std::endl;
    return &z;
}

void fun2(int **x){

    **x = 3;    

}


int main (){

int y = 0;
std::cout<<"y = "<<&y<<std::endl;
fun2(fun(&y));
std::cout<<y<<std::endl;


return 0;
}