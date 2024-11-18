class Solution {
public:
    vector<int> sortedSquares(vector<int>& n) {
       std::vector<int>res;
       res.reserve(n.size());
       int i=0,j=n.size()-1;
       while(i<=j){
        if(std::abs(n[i])>=std::abs(n[j])){
            res.push_back(n[i]*n[i]);
            ++i;
        }else{
            res.push_back(n[j]*n[j]);
            --j;
        }
       }
       return std::vector<int>(res.rbegin(),res.rend());
    }
};

