class Solution {
public:
    int evalRPN(vector<string>& t) {
        std::vector<std::string>st;
        for(size_t i=0;i<t.size();){
            if(isdigit(t[i].front()) || t[i].size()>1){
                st.push_back(t[i++]);
            }else if(!isdigit(t[i].front()) && t[i].size()==1){
                int y=std::stoi(st.back());
                st.pop_back();
                int x=std::stoi(st.back());
                st.pop_back();
                switch(t[i].front()){
                    case '+': st.push_back(std::to_string(x+y));break;
                    case '*': st.push_back(std::to_string(x*y));break;
                    case '/': st.push_back(std::to_string(x/y));break;
                    case '-': st.push_back(std::to_string(x-y));break;
                }
                ++i;
            }
        }
        return std::stoi(st.back());
    }
};

///////////////////////
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st; int opd1, opd2;
        int n = tokens.size();

        for (int i = 0; i < n; i ++) {
            if (tokens[i] == "+") {
                opd1 = stoi(st.top()); st.pop();
                opd2 = stoi(st.top()); st.pop();
                st.push(to_string(opd1 + opd2));
            } else if (tokens[i] == "-") {
                opd1 = stoi(st.top()); st.pop();
                opd2 = stoi(st.top()); st.pop();
                st.push(to_string(opd2 - opd1));
            } else if (tokens[i] == "*") {
                opd1 = stoi(st.top()); st.pop();
                opd2 = stoi(st.top()); st.pop();
                st.push(to_string(opd1 * opd2));
            } else if (tokens[i] == "/") {
                opd1 = stoi(st.top()); st.pop();
                opd2 = stoi(st.top()); st.pop();
                st.push(to_string(opd2 / opd1));
            } else {
                st.push(tokens[i]);
            }

        }

        return stoi(st.top());
    }
};

///////////////////
