/*

 # Types of Design Pattern: 

        1. Creational (Deals with Class Design and influence in classes)
            ex: Singelaton(return the same object if many are included)

        2. Structural (Deals with System Design)
            * Static Design (relationship between classes in design level)
            * Types of Inheritance - Aggregation - Composition - ...
            * Uses Class Diagram 
            * ex: Adaptive - Composite
        
        3. Behaviour (Deals with System behaviour at Run Time)

            * Dynamic Design 
            * Uses Sequence diagram - Finite machine 
            * Classes interaction at Run Time
            * ex: Observer 
    
# Why Design Pattern 
        Design Pattern Useful in 

        1. Realiable and Reuse code.
        2. Easier to Change 
        3. More maintainable, Extensions, Modifications.
        4. Establish Common Terminology "Give common point of refrence"
        5. Provide Head Start
        6. Avoid Gotcha later "unanticipated things"
        7. No need to reinvent the wheel
        8. Proven Solutions 

# Observer Design Pattern 

                                                  dependency
                    Subject(Observable - news) ----------------> Observer(me)
                            ^                                          ^
                            |                                          |
                            | Inheritance                              | Implementation  
                            |                                          |
                            |                                          |
                        provider                      '       -------------------  
                                                              obs1            obs2          

We need in our example observable (clock Timer) and observers (Analog - Digital), if the observable changes it's timer our observers will get notifed with the new time
and we will do certain activities in response to alerts sent by the subject 

Questons: 
    1. why we can only use sunject in the decleration at the beginning of code ?

    2. why virtual destuctor ?

    *Virtual destructors in C++ are used to avoid memory leaks especially when your class contains unmanaged code, 
     i.e., contains pointers or object handles to files, databases or other external objects. A destructor can be virtual.
     Let's understand why it is needed. Let's consider a scenario in which there are two classes, a base class called Base and a derived class called Derived. 
     Now, constructors are invoked in the order of inheritance and destructors are invoked in the reverse order of inheritance. 
     So, when an instance of the derived class is created, the constructor of the Base class would be invoked first, 
     followed by the Derived class constructor. Similarly, the Derived class destructor would be invoked followed by the 
     Base class destructor at the time when the object goes out of the scope or is destroyed explicitly.
     Now, suppose you create an instance of the Derived class using a Base class pointer.
     When you delete the pointer object using the delete keyword in C++, the destructor of the Base class would be called but the destructor of the Derived class 
     would simply be ignored. The reason is that the destructor is simply another method and so when the delete keyword is used to delete the pointer instance,
     the type of the pointer would be considered and not its context. And, because the type of the pointer is of type Base, the destructor of 
     the Base class would only be invoked. This might create memory leaks as the instance of the derived class would still remain in memory even after
     the pointer instance has been deleted/destroyed from memory. To avoid such potential memory leak issues, virtual destructors are used.
     
    3. why we check about the address of the updated subject with the current subject ?
    
     *Because it can be another Muli Subjects in your system so, you have to check that you take the right subject 

CreatedBy: Mustafa Hussam Eldin 
*/                                                      


#include <iostream>
#include <algorithm>
#include <vector>

class Subject; 

class Observer{

public: 
    virtual ~Observer() = default;
    virtual void update(Subject&) = 0;    

};

class Subject {
  
public:
    virtual ~Subject() = default;

    void add(Observer& o){ // o = *this 
        observers.push_back(&o); //observer* observer = &o; 
    }
        // Observer& o = *this ; 
    void remove(Observer& o){
        observers.erase(std::remove(observers.begin(),observers.end(),&o));
    }

    void notify(){
        for (auto* o : observers){
            o->update(*this); //*this send the object that call notify function (this = *object) so, *this = **object = &object 
        }
    }

private:
    std::vector<Observer*> observers;

};

class CounterClock : public Subject {

public: 

    void setTimer(int hours, int minutes, int seconds){
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;

        notify();
    }
    
     int getHours() const{ 
        return hours;
    }
    
    int getMinutes() const{
        return minutes;
    }

    int getSeconds() const{
        return seconds;
    }


private:
    int hours;
    int minutes;
    int seconds;

};

class DigitalClock : public Observer{

public: 
   explicit DigitalClock(CounterClock& s) : sub(s) {
             sub.add(*this);  //subscribe, send object created pointer to add function
    }

    ~DigitalClock(){
             sub.remove(*this);
    }

    void update(Subject& updated) override { //&updated == *this == &object 
            if (&updated == &sub)
            {
                draw();
            }

    }

    void draw(){
        int hours = sub.getHours();
        int minutes = sub.getMinutes();
        int seconds = sub.getSeconds();

     std::cout<<"Digital Clock = " << hours << ":" << minutes << ":" << seconds <<std::endl;

    }
   

private:
    CounterClock& sub;

};

class AnalogClock : public Observer {

public:
    explicit AnalogClock(CounterClock& s) : sub(s) {
             sub.add(*this);  //subscribe, send object created pointer to add function
    }

    ~AnalogClock(){
             sub.remove(*this);
    }


    void update(Subject& updated) override {
            if (&updated == &sub)
            {
                draw();
            }

    }

    void draw(){
        int hours = sub.getHours();
        int minutes = sub.getMinutes();
        int seconds = sub.getSeconds();

     std::cout<<"Digital Clock = " << hours << ":" << minutes << ":" << seconds <<std::endl;

    }

private: 
    CounterClock& sub;
};


int main (){

    CounterClock timer ; 

    DigitalClock dig(timer); 
    AnalogClock  ana(timer); 

    timer.setTimer(12,50,59);    
    return 0;
}



