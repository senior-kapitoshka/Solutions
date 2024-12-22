#include <string>
#include <sstream>
#include <iostream>

class Serializer{
protected:
    std::stringstream ss;
    bool flag=true;
public:
    virtual void BeginArray()=0;
    virtual void AddArrayItem(const std::string &)=0;
    virtual void EndArray()=0;
    virtual ~Serializer(){
        std::cout<<ss.str()<<"\n";
    }
};

class JsonSerializer:public Serializer{
public:
    void BeginArray() override {
        if(!flag) ss<<",[";
        else{
            ss<<"[";  
        }
        flag=true;
    }
    void AddArrayItem(const std::string & s)override {
        if (!flag) {
            ss << ",";
        }
        ss<< "\"" << s << "\"";
        flag = false;
    }
    void EndArray()override {
        ss << "]";
        flag = false;
    }
};