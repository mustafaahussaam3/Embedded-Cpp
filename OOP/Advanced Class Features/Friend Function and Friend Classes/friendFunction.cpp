/*
                                                **  Friend Function **
Like a friend class, a friend function can be granted special access to private and protected members of a class in C++.
They are the non-member functions that can access and manipulate the private and protected members of the class for they are declared as friends.

A friend function can be:
    1. A global function
    2. A member function of another class


friend return_type function_name (arguments);    // for a global function
            or
friend return_type class_name::function_name (arguments);    // for a member function of another class

*/
#include <iostream>

class base {
    private:
        int private_variable ;
    protected:
        int protected_variable ;
    public: 

         base(){
            private_variable = 10;
            protected_variable = 20;
         }

      friend void friendFunction (base& b) ;
};

      void friendFunction (base& b){
        b.private_variable = 20;
        std::cout << "Private Variable = " << b.private_variable <<std::endl;
        std::cout << "Protected Variable = "<< b.protected_variable <<std::endl;
        }



int main(){

    base obj;
    friendFunction(obj);

return 0;
}