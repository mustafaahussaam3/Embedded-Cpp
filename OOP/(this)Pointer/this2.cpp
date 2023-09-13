#include <iostream>

class Test {

private:
    int x;
    int y;

public:
    Test(int x = 0, int y = 0){
        this->x = x; 
        this->y = y;
    }

    Test& setX(int a){
         x = a;
        return *this;
    }

    Test& setY(int b){
        y = b;
        return *this;
    }

    // void setX(int a){
    //       x = a;
    // }

    // void setY(int b){
    //       y = b;
    // }
    void print(){
        std::cout<<"x = "<< x << " y = "<< y << std::endl;
    }

};

int main(){

    Test obj(5,5);
    obj.setX(10).setY(20); //chain function call. all calls modify the same object as the same object is returned by reference 

    obj.print();

return 0;
}