/*
                                                     **this Pointer**

    To understand ‘this’ pointer, it is important to know how objects look at functions and data members of a class.

    *Each object gets its own copy of the data member.
    *All-access the same function definition as present in the code segment.

Meaning each object gets its own copy of data members and all objects share a single copy of member functions.
Then now question is that if only one copy of each member function exists and is used by multiple objects, how are the proper data members are accessed and updated?
The compiler supplies an implicit pointer along with the names of the functions as ‘this’.
The ‘this’ pointer is passed as a hidden argument to all nonstatic member function calls and is available as a local variable within the body of all nonstatic functions.
‘this’ pointer is not available in static member functions as static member functions can be called without any object (with class name).
    

it's used when :
`   1) When local variable’s name is same as member’s name
    2) To return reference to the calling object
    




*/

#include<iostream>
using namespace std;

/* local variable is same as a member's name */
class Test{

private:
int x;

public:
void setX (int x){
	// The 'this' pointer is used to retrieve the object's x
	// hidden by the local variable 'x'
	//x = x; //garbage value
    //x = z; // the exact value so, the concept is work
    this->x = x;

}

void print() { cout << "x = " << x << endl; }
};

int main(){

    Test obj;
    int x = 20;
    obj.setX(x);
    obj.print();

return 0;
}
