//черновик
/////////////////////////////

#include <string>
#include <regex>
#include <queue>
#include <string_view>

enum Priority{
  SM,
  PW,
  EX,
  BR
};


struct Opnd{
  size_t id;
  char data;
  Priority pr;
};

bool operator <(const Opnd& lhs,const Opnd& rhs){
  return lhs.id<rhs.id && lhs.pr<rhs.pr;
}

std::ostream& operator<<(std::ostream& os,const Opnd& o){
  return os<<"id: "<<o.id<<"\n"<<"data: "<<o.data<<"\n"<<"priority: "<<o.pr<<"\n";
}

struct Node{
  Priority pr;
  char data;
  Node* l;
  Node* r;
};

bool operator <(const Node& lhs,const Node& rhs){
  return lhs.pr<rhs.pr;
}

void travers(Node* root){
  if(!root) return;
  std::cout<<root->data;
  if(root->l){
    travers(root->l);
  }
  if(root->r){
    travers(root->r);
  }
}

auto ops_cmp=[](auto& lhs,auto& rhs){ return lhs<rhs;};
using ops=std::priority_queue<Opnd,std::vector<Opnd>,decltype(ops_cmp)>;

auto nds_cmp=[](auto& lhs,auto& rhs){ return lhs<rhs;};
using nds=std::priority_queue<Node,std::vector<Node>,decltype(nds_cmp)>;

void prior(const std::string& in,ops& q1){
  for(size_t i=0;i<in.size();++i){
    if(in[i]=='^'){
      q1.push({i,in[i],Priority::EX});
    }else if(i-2>=0 && i+2<=in.size()){
      if(in[i-2]=='(' &&in[i+2]==')'){
        q1.push({i,in[i],Priority::BR});
      }else{
        if(in[i]=='-' || in[i]=='+'){
          q1.push({i,in[i],Priority::SM});
        }else if(in[i]=='*'||in[i]=='/'){
          q1.push({i,in[i],Priority::PW});
        }
      }
    }else if(i-2<0 && i+2>in.size()){
      if(in[i]=='-' || in[i]=='+'){
          q1.push({i,in[i],Priority::SM});
        }else if(in[i]=='*'||in[i]=='/'){
          q1.push({i,in[i],Priority::PW});
        }
  }
}
}


std::string to_postfix(std::string in) {
  ops q1(ops_cmp);
  prior(in,q1);
  while(!q1.empty()){
    std::cout<<q1.top();
    q1.pop();
  }
  return in;
}
//черновик
/////////////////////////////
//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//решение:

#include <string>
#include <vector>
#include <string_view>
#include <regex>
#include <sstream>

enum Type{
  OP_BR,
  CL_BR,
  INT,
  MIN,
  SUM,
  DIV,
  POW,
    EXP
};


struct Lex{
  Lex()=default;
  Lex(int v,Type t,char d):val(v),type(t),data(d){}
  Lex(Type t,char d):type(t),data(d){}
  int val=0;
  Type type;
  char data=' ';
};

void lexer(std::string_view s,std::vector<Lex>& res){
  auto b=s.data();
  auto e=s.data()+s.size();
  for(auto it=b;it!=e;){
    if(*it==' '){
      ++it;
    }else if(*it=='('){
      res.emplace_back(Type::OP_BR,*it);
      ++it;
      
    }else if(*it==')'){
      res.emplace_back(Type::CL_BR,*it);
      ++it;
      
      
    }else if(*it=='^'){
      res.emplace_back(Type::EXP,*it);
      ++it;
      
    }
    else if(*it=='*'){
      res.emplace_back(Type::POW,*it);
      ++it;
      
      
    }else if(*it=='+'){
      res.emplace_back(Type::SUM,*it);
      ++it;
      
      
    }
    else if(*it=='/'){
      res.emplace_back(Type::DIV,*it);
      ++it;
      
      
    }else if(*it=='-'){
      res.emplace_back(Type::MIN,*it);
      ++it;
      
    }else{
      res.emplace_back(*it-'0',Type::INT,*it);
      ++it;
      
    }
    
  }
}

std::ostream& operator<<(std::ostream& os,const Lex& o){
  return os<<"data: "<<o.data<<"\n";
}

void inf_to_post(std::vector<Lex>& parser, std::vector<Lex>& res){
  std::vector<Lex>stack;
  for(auto& e:parser){
    if(e.type==Type::INT){
      res.push_back(e);
    }else if(e.type==Type::OP_BR){
      stack.push_back(e);
    }else if(e.type==Type::CL_BR){
      while(!stack.empty() && stack.back().type!=Type::OP_BR){
        res.push_back(stack.back());
        stack.pop_back();
      }
      stack.pop_back();
    }else{
      while(!stack.empty() && e.type<=stack.back().type){
        res.push_back(stack.back());
        stack.pop_back();
      }
      stack.push_back(e);
    }
  }
  while(!stack.empty()){
    res.push_back(stack.back());
    stack.pop_back();
  }
}

std::string to_postfix(std::string in) {
 std::vector<Lex> parser;
   std::vector<Lex> res;
  std::regex r("([\\d][\\*][\\d])");
  in=std::regex_replace(in,r,"($&)");
  std::cout<<in<<"\n";
  lexer(in,parser);
  /*for(auto i:parser){
    std::cout<<i;
  }*/
  inf_to_post(parser,res);
  std::stringstream ss;
  for(auto& i:res){
    std::cout<<i;
    ss<<i.data;
  }
  return ss.str();
}

///////////////////////////////////////////////
int getp(char c) {
    if(c=='^') return 3; if(c=='*'||c =='/') return 2; if(c=='+'||c =='-') return 1;
    return 0;
}
std::string to_postfix(std::string infix) {
  std::stack<char> stk;
  std::string str;
  for(char c : infix) {
    if(isdigit(c)) str += c;
    else if (c == '(') stk.push(c);
    else if (c == ')') {
      while(stk.top() != '(' && !stk.empty()) {str += stk.top(); stk.pop();}
      if(stk.top() == '(') stk.pop();
    }
    else {
      while(!stk.empty() && getp(c) <= getp(stk.top())) {str += stk.top(); stk.pop();}
      stk.push(c);
    }
  }
  while(!stk.empty()) {str += stk.top(); stk.pop();}
  return str;
}

////////////////
#include <string>
#include <iterator>

// I can write short functions too. But are they really BETTER?
void read_one_argument(std::back_insert_iterator<std::string> out, std::string::const_iterator& in, int cur_pr)
{
  if (*in == '(') read_one_argument(out, ++in, 0); else *out++ = *in;
  static constexpr char a[] = { 0, 0, 2, 1, 0, 1, 3, 2 };
  for (char pr, op = *++in; (pr = a[op & 7]) > cur_pr; *out++ = op, op = *in)
    read_one_argument(out, ++in, pr);
}

std::string to_postfix(std::string infix) {
  std::string result;
  std::string::const_iterator in = infix.begin();
  read_one_argument(std::back_inserter(result), in, 0);
  return result;
}

/// ///////////
struct OperatorInfo {
    int precedence;
    bool isLeftAssociative;
};

// note that operators with the same precedence must also have the same associativity
static const std::map<char, OperatorInfo> operatorInfo = {
    { '+', { 0, true } },
    { '-', { 0, true } },
    { '*', { 1, true } },
    { '/', { 1, true } },
    { '^', { 2, false } },
    // test cases include null characters at the end of the infix
    // string and expect them to also be at the end of the postfix string
    // (this can be accomplished by treating null as the lowest-priority operator)
    { '\0', { -1, true } }
};

static const int maxOperatorPrecedence = std::max_element(operatorInfo.begin(), operatorInfo.end(),
    [](const auto& a, const auto& b) { return a.second.precedence < b.second.precedence; })->second.precedence;

struct StoredOperatorInfo {
    char character;
    int precedence;
};

std::string to_postfix(const std::string& infix) {
    std::stringstream postfixStream;
    std::stack<StoredOperatorInfo> storedOperatorInfo;
    int precedenceOffset = 0;

    for (char character : infix) {
        if (isdigit(character)) {
            postfixStream << character;
        }
        else if (operatorInfo.find(character) != operatorInfo.end()) {
            int precedence = operatorInfo.at(character).precedence + precedenceOffset;
            bool isLeftAssociative = operatorInfo.at(character).isLeftAssociative;

            while (!storedOperatorInfo.empty() && (storedOperatorInfo.top().precedence > precedence ||
                   (storedOperatorInfo.top().precedence == precedence && isLeftAssociative))) {
                postfixStream << storedOperatorInfo.top().character;
                storedOperatorInfo.pop();
            }

            storedOperatorInfo.push({ character, precedence });
        }
        else if (character == '(') {
            precedenceOffset += (maxOperatorPrecedence + 1);
        }
        else if (character == ')') {
            precedenceOffset -= (maxOperatorPrecedence + 1);
        }
        else {
            // ignore the character
        }
    }

    while (!storedOperatorInfo.empty()) {
        postfixStream << storedOperatorInfo.top().character;
        storedOperatorInfo.pop();
    }

    return postfixStream.str();
}
///////////////////////////////////
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>
using namespace std;

vector<char> op = {'+','-','*','/','^','(',')'}; // oprators a.c.t. precedencies

int pre(char ch, string opt){
    vector<int> in_pre = {2,2,4,4,5,0,0};  // precedency if operator is in stack
    vector<int> out_pre = {1,1,3,3,6,7,0}; // precedency if operator is out of stack
    int idx = find(op.begin(), op.end(), ch) - op.begin();    
    if (opt == "out") {return out_pre[idx];} // if the operator is out of stack -> return its precedency
    else {return in_pre[idx];}
}

string to_postfix(string infix) {
    stack<char> st;
    string str;
    for (int i = 0; i < infix.size() ; i++){;
        if (find(op.begin(), op.end(), infix[i]) != op.end() and !op.empty()){
            if (st.empty() or (pre(infix[i], "out") > pre(st.top(), "in"))) st.push(infix[i]); // if st is empty or the element has higher precedency than stacks top element, push the operator into the stack.
            else if(infix[i] == '(') st.push('(');
            else if (infix[i] == ')') {
                while(st.top() != '(') {
                    str+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while(!st.empty() && pre(infix[i], "out") < pre(st.top(), "in")) {
                    str += st.top();
                    st.pop(); 
                }
                st.push(infix[i]);
            }
            
        } 
        else str += infix[i];
    }
    while(!st.empty()){
        str += st.top(); st.pop();
    }
    return str;
}
//////////////////////////
