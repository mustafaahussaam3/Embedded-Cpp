/*  
                                                                  **Inheritance**
    The capability of a class to derive properties and characteristics from another class is called Inheritance. 
    Inheritance is one of the most important features of Object-Oriented Programming. 

    Inheritance is a feature or a process in which, new classes are created from the existing classes.
    The new class created is called “derived class” or “child class” and the existing class is known as the “base class” or “parent class”. 
    The derived class now is said to be inherited from the base class.

    When we say derived class inherits the base class, it means, the derived class inherits all the properties of the base class, 
    without changing the properties of base class and may add new features to its own. These new features in the derived class will not affect the base class.
     The derived class is the specialized class for the base class.

    Sub Class: The class that inherits properties from another class is called Subclass or Derived Class. 
    Super Class: The class whose properties are inherited by a subclass is called Base Class or Superclass. 

    Derived Classes: A Derived class is defined as the class derived from the base class.
    class  <derived_class_name> : <access-specifier> <base_class_name>
    {
        //body
    }
   ** class      — keyword to create a new class
   ** derived_class_name   — name of the new class, which will inherit the base class
   ** access-specifier  — either of private, public or protected. If neither is specified, PRIVATE is taken as default
   ** base-class-name  — name of the base class

Note: 1- A derived class doesn’t inherit access to private data members. 
        However, it does inherit a full parent object, which contains any private members which that class declares.
      2- private inheritance::: Public members in Parent become Private in Child so, when we make instance from the child we cannot access the members of the parent class.
      3- public inheritance:::: Public members in Parent become Public in Child so, when we make instance from the child we can access the members of the parent class.

Summary: 

base class 
access specifier              type of inheritance
______________________________________________________________      
               |   Public     |   Protected   |   Private     
_______________|______________|_______________|_______________
     Public   :     Public        Protected        Private
     Protected:   Protected       Protected        Private 
     Private  :   No Access       No Access       No Access
_______________________________________________________________    

CreatedBy: Mustafa Hussam Eldin

*/
#include <iostream>

class A {
public:
	int x = 1;

    void setParentz(int x){
        this -> z = x;
    }
    int getParentz(){
        return z;
    }
    
protected:
	int y = 2;

private:
	int z = 3;
};

class B : public A {
	// x is public
	// y is protected
	// z is not accessible from B
//    public: 
//         int x = 1;
//    protected: 
//         int y = 2; 
   public:
    void setX(int x){
        this -> x = x ;
    }
    void setY(int x){
        this -> y = x ;
        std::cout<< this -> y <<std::endl;
    }
    int getPublicChildParenty(){
        return y;
    }
    void setPublicChildParenty(int y){
        this -> y = y; 
    }
};

class C : protected A {
    // protected: 
    //     int x = 1;
    //     int y = 2;
    // void setParentz(int x){
    //     this -> z = x;
    // }
    // int getParentz(){
    //     return z;
    // }
    
	// x is protected
	// y is protected
	// z is not accessible from C
};

class D : private A // 'private' is default for classes
{   
// private: 
//     int x = 1;
//     int y = 2;
	// x is private
	// y is private
	// z is not accessible from D

};

class F : public C {
    //x is protected
    //y is protected
    public:
    void setChildFChildCParenty(int x){
        this -> y = x;
    }
    int getChildFChildCParenty(){
        return y;
    }
};

class G : public D{

    public: 
    void setChildGChildDparentx(int x){
        //error 
    }


};


int main (){

    B b; 
    std::cout<< b.x << std::endl; 
    b.setX(4);
    b.setY(5);
    std::cout<< b.x <<std::endl;
    b.setPublicChildParenty(30);
    std::cout<< b.getPublicChildParenty()<<std::endl;

    A a ;
    a.setParentz(20);
    std::cout<< a.getParentz()<<std::endl;

    F f;
    f.setChildFChildCParenty(50);
    std::cout<<f.getChildFChildCParenty()<<std::endl;

    
}