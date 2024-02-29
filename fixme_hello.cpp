#include <utility>
#include <string_view>
using namespace std::literals;

enum Info{
  AGE,
  SEX,
  NAME
};
class Dinglemouse
{
    std::optional<std::string> name_;
    std::optional<int> age_;
    std::optional<char> sex_;

    std::string answer="Hello. "s;
    std::vector<Info> que;
    
public:

    Dinglemouse()
    {
    }
  

    Dinglemouse &setAge(int age)
    {
      if(!age_.has_value()){
        this->age_ = age;
        que.push_back(Info::AGE);
      }else{
        this->age_ = age;
      }
      return *this;
    }

    Dinglemouse &setSex(char sex)
    {
      if(!sex_.has_value()){
        this->sex_ = sex;
        que.push_back(Info::SEX);
      }else{
        this->sex_ = sex;
      }
      return *this;
    }

    Dinglemouse &setName(const std::string &name)
    {
      if(!name_.has_value()){
        this->name_ = name;
        que.push_back(Info::NAME);
      }else{
        this->name_ = name;
      }
      return *this;
    }

    std::string hello()
    {
      if(que.empty()){
        answer.pop_back();
      }else{
        std::for_each(que.begin(),que.end(),[this](auto& i){
        
            if(i==Info::AGE){
              answer+="I am "+ std::to_string(*age_) +". "; 
            }
            else if(i==Info::SEX){
              answer+="I am ";
              if(*sex_=='M')answer+= "male. ";
                else answer+="female. ";
            }
            else if(i==Info::NAME){
              answer+="My name is " + *name_+". ";  
            }
        });
        answer.pop_back();
      }
      return answer;
    }
};