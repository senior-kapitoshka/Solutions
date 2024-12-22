class Solution {
public:
    bool is_val(std::string_view s){
        int cnt=0;
        for(auto i:s){
            cnt+=(i=='(')?1:(-1);
            if(cnt<0) return false;
        }
        return cnt==0;
    }
    void generate(std::string& s,int n, int o,int c,
    std::vector<std::string>&res){
        if(s.size()==2*n){
            if(is_val(s)){
                res.emplace_back(s);
            }
            return;
        }
        if(o<n){
            s+='(';
            generate(s,n,o+1,c,res);
            s.pop_back();
        }
        if(c<o){
            s+=')';
            generate(s,n,o,c+1,res);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        std::vector<std::string>res;
        res.reserve(2*n-1);
        std::string s;
        generate(s,n,0,0,res);
        return res;
    }
};