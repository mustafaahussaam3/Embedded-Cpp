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


CreatedBy: Mustafa Hussam Eldin 
*/                                                      


#include <iostream>
#include <algorithm>
#include <vector>


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
    DigitalClock(CounterClock& s) : sub(s) {
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
     AnalogClock(CounterClock& s) : sub(s) {
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

    timer.setTimer(12,30,59);

    return 0;
}



