#include <iostream>
#include <memory>

class A {


public:
    A(){
        std::cout <<"constructor"<< std::endl;

    }

    ~A(){
        std::cout <<"destructor"<< std::endl;

    }
    // std::shared_ptr<A>val;
    std::weak_ptr<A> val;

    // void setValue(std::shared_ptr<A>ptr){
    void setValue(std::weak_ptr<A> ptr){ //here the reference count will not inc it will be 1 only for the shared in main 
        std::cout<<"ptr local before init = "<<ptr.use_count()<<std::endl;
        std::cout<<"val before used = "<<val.use_count()<<std::endl;
        this -> val = ptr;
        std::cout<<"ptr local after init = "<<ptr.use_count()<<std::endl;
        std::cout<<"val after used = "<<val.use_count()<<std::endl;
    }

    void print(){
        std::cout<<"print"<<std::endl;
    }
};



int main(){

    std::shared_ptr<A> p1 (new A); // A* p1 = new A; //A1 
    std::shared_ptr<A> p2 (new A); //A2 
    std::cout<<"val in main before p1 = "<<p1->val.use_count()<<std::endl;
    std::weak_ptr<A> wp = p1;
    wp.lock()->print(); //if not expired print 
    p1 ->setValue(p2); //val -> p2  p2 -> A2
    // std::cout<<"val in main after p2 = "<<p1->val.use_count()<<std::endl;
    p2 ->setValue(p1); //val -> p1  p1 -> A1    therefore:: A1 -> A2 
    std::cout<<"val in main after p1 = "<<p1->val.use_count()<<std::endl;
    std::cout<<"val in main after p2 = "<<p2->val.use_count()<<std::endl;

    std::cout<<"p1 count = "<<p1.use_count()<<std::endl; //use_count() tells you the value of the counter **2 -> A1
    std::cout<<"p2 count = "<<p2.use_count()<<std::endl; // **2 -> A2
    //to solve that we need to add weak pointer in the class to check whether if the class is alive it will used and if not it will destroy 
    /*
            weak pointer lock function 
            if (expired()) //place memory used 
            {
                shared_ptr<A> ptr; //return null
            }
            else 

            p1;
    */
    return 0;
}