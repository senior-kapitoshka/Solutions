bool valid_braces(std::string bs) 
{
  if(bs.size()%2!=0) return false;
  if(bs.empty()) return true;
  std::vector<char> pr;
  for(auto c:bs){
    if(c=='(' || c=='[' || c=='{'){
      pr.push_back(c);
    }else if((c==')' || c==']' || c=='}') && pr.empty())return false; 
    else if(c==')' && pr.back()=='('){
      pr.pop_back();
    }else if(c==']' && pr.back()=='['){
      pr.pop_back();
    }else if(c=='}' && pr.back()=='{'){
      pr.pop_back(); 
    }else return false;
  }
  return  pr.empty();
}
////////////////////////
bool valid_braces(std::string braces, std::stack<char> s = {}) 
{
  for(auto x : braces)
    if(!s.empty() && ((x=='}' && s.top() == '{') || (x==']' && s.top() == '[') || (x==')' && s.top() == '('))) s.pop();
    else s.push(x);
  return s.empty();
}


///////////////////
#include <stack>
#include <map>
bool valid_braces(std::string braces, std::stack<char> s = {}, std::map<char, char> dict = {{'(',')'}, {'[',']'}, {'{','}'}})
{
    std::for_each(braces.begin(), braces.end(), [&](int x){(!s.empty() && dict[s.top()]==x)?(s.pop()):(s.push(x));});
    return s.empty();
}

//////////
