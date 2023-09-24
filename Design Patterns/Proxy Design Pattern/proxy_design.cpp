/*                           ask
                    client---------->Subject  +request()
                                        ^
                                   inheritance
                                        |    
         +request() RealSubject ________|_________ Proxy +request()
                        ^                               |
                        |___________Implement___________|

 the client don't connect the realSubject(server) direct but it need's the permission of the proxy first and after that the proxy implement the server 
 ** server will be killed when the proxy is killed (composite)
 ** proxy and server must inherit the Parent class functions that when the client ask the parent class we create a proxy class for it in the main

CreatedBy: Mustafa Hussam Eldin
**/
#include <iostream>

class IBox {

public:
    virtual void Open() = 0;
};

class SimpleBox : public IBox{

public: 
        virtual void Open (){
            std::cout<<"Open the Box"<<std::endl;
        }

};
class ProxyBox : public IBox{

public:
        ProxyBox(std::string user_name, int password): m_user_name(user_name), m_password(password){

          }

        virtual void Open (){

                if (auth()){
                    std::cout<<"Authentication Success"<<std::endl;
                    m_box.Open();
                    std::cout<<"Open is called"<<std::endl;
                }
                else {
                    std::cout<<"Authentication is Failed"<<std::endl;
                }

          }

private: 
    bool auth(){

        bool bAuth = true;
        return bAuth;

    }

    std::string m_user_name;
    int         m_password; 
    SimpleBox   m_box;

};

int main(){

    IBox *box = new ProxyBox("MustafaHussam", 1234);
    box->Open();
    delete box; 

return 0;
}