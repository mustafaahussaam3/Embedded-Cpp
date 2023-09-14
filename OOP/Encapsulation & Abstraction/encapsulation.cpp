/*
                                                     **Encapsulation**

-->Encapsulation Properties:

    1. Data Protection: Encapsulation protects the internal state of an object by keeping its data members private.
         Access to and modification of these data members is restricted to the class’s public methods, ensuring controlled and secure data manipulation.
    2. Information Hiding: Encapsulation hides the internal implementation details of a class from external code. 
         Only the public interface of the class is accessible, providing abstraction and simplifying the usage of the class while allowing the internal
         implementation to be modified without impacting external code.

-->Encapsulation Features:

    1. We can not access any function from the class directly. We need an object to access that function that is using the member variables of that class. 
    2. The function which we are making inside the class must use only member variables, only then it is called encapsulation.
    3. If we don’t make a function inside the class which is using the member variable of the class then we don’t call it encapsulation.
    4. Encapsulation improves readability, maintainability, and security by grouping data and methods together.
    5. It helps to control the modification of our data members.

Editedby: Mustafa Hussam Eldin 

*/

#include <iostream>
#include <string>

class Person{

private:
    std::string name;
    int age;

public:
    Person (std::string name, int age){
        this-> name = name; 
        this-> age = age;
    }

    void setName(std::string name){
        this-> name = name; 
    }   
    std::string getName(){

        return name; 
    } 

    void setAge(int age){
        this-> age = age; 
    }

    int getAge(){
        return age;
    }



};



int main(){

    Person person("Mustafa",26);
    std::cout<<"Name: "<<person.getName()<<std::endl;
    std::cout<<"age: "<<person.getAge()<<std::endl;

    person.setName("Hussam");
    person.setAge(62);
    std::cout<<"Name: "<<person.getName()<<std::endl;
    std::cout<<"age: "<<person.getAge()<<std::endl;
    

 return 0;
}