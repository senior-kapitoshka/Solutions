#include <string>

std::string stringify(Node* list)
{
  if(list==nullptr) return "nullptr";
  Node * curr=list->next;
  std::string ans;
  while(list!=nullptr || curr->next!=nullptr){
    if(curr!=nullptr){
      ans+=std::to_string(list->data);
      ans+=" -> ";
      list=list->next;
      curr=curr->next;
      
    }else{
      ans+=std::to_string(list->data);
      
     ans+=" -> nullptr";
      break;
    }
  }
  return ans;
}

///////////////////////////////////////////////////////////////

#include <string>

std::string stringify(Node* list)
{
    std::string result{};
    while(list)
    {
        result += std::to_string(list->data) + " -> ";
        list = list->next;
    }
    result += "nullptr";
    
    return result;
}