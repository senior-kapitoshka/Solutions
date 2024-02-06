#include <string>
#include <stack>

bool validParentheses(const std::string& str) {
  if(str.empty()) return true;
  if(static_cast<int>(str.size())%2!=0) return false;
  std::stack<char>st;
  for(auto c:str){
            if( c=='(') st.push(c);
            else {
                if(st.empty()|| (st.top()!='('&& c==')')) return false;
            st.pop();
        }
        }
        return st.empty();
}

#include <string>

bool validParentheses(const std::string& str) {
  int open = 0;
  for(char c : str) {
    if((open += c == '(' ? 1 : -1) < 0) {
      return false;
    }
  }
  return !open;
}