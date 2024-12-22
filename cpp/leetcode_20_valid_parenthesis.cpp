class Solution {
public:
    bool isValid(string s) {
       std::vector<char>st;
       for(auto c:s){
        if(st.empty() || c=='(' || c=='[' || c=='{'){
                st.push_back(c);
        }else{
            switch(c){
                case ')': 
                if(st.back()=='(') st.pop_back();
                else st.push_back(c);
                break;
                case ']': 
                if(st.back()=='[') st.pop_back();
                else st.push_back(c);
                break;
                case '}': 
                if(st.back()=='{') st.pop_back();
                else st.push_back(c);
                break;
            }
        }
    } 
        return st.empty();
    }
};

/////////////////////
class Solution {
private:
    std::string s_,p_;    
public:
    bool check(size_t i,size_t j,const std::vector<int>& vc1){
        std::vector<int>vc2(26,0);
        for(size_t x=i;x<=j;++x){
            ++vc2[s_[x]-97];
        }
        return vc1==vc2;
    }
    vector<int> findAnagrams(string s, string p) {
        s_=s;
        p_=p;
        int hs1=0,hs2=0;
        std::vector<int>vc1(26,0);
        for(size_t i=0;i<p.size();++i){
            hs2+=s[i]-97;// hash += sum of alph
            hs1+=p[i]-97;
            ++vc1[p[i]-97];
        }
        int i=0;
        std::vector<int>res;
        res.reserve(s.size());
        if(hs1==hs2 && check(i,p.size()-1,vc1))
            res.push_back(0);
        for(size_t j=p.size();j<s.size();++j){
            hs2+=s[j]-s[i++];//хеш предположительно не меняется
            //индекс i увеличивается после доьавления разности к хешу 
            if(hs2!=hs1) continue;
            else{
                if(check(i,j,vc1)) res.push_back(i);
            }
        }
        return res;
    }
};