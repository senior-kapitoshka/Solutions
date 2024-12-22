class Solution {
public:
    string reverseWords(string s) {
        std::stringstream ss(s);
        std::stringstream res;
        for(std::string w;std::getline(ss,w,' ');){
            res<<std::string(w.rbegin(),w.rend())<<" ";
        }
        std::string r=res.str();
        r.pop_back();
        return r;
    }
};

////////////////////
class Solution {
public:
   void reverse(string &s , int  i , int j)
   {
         while(i < j)
         {
            swap(s[i],s[j]);
            i++;
            j--;
         }
   }
    string reverseWords(string s) {
        int n = s.length();
        int i = 0 , j = 0;
        while(j <= n)
        {
            if(j<n && s[j] != ' ' )
            {
                j++;
            }
            else
            {
                reverse(s,i,j-1);
                j++;
                i = j;
            }
        }
        return s;
    }
};  