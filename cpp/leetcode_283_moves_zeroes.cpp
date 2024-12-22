class Solution {
public:
    void moveZeroes(vector<int>& n) {
        std::stable_partition(n.begin(),
        n.end(),[](auto& i){
            return i!=0;
        });
    }
};

/////////////////

class Solution {
public:
    void moveZeroes(vector<int>& n) {
       for(size_t j=0,i=1;i<n.size();++i){
        if(n[j]==0 && n[i]!=0){
            std::swap(n[j],n[i]);
            ++j;
        }else if(n[j]!=0){
            ++j;
        }
       }
    }
};
//////////////////////
class Solution {
public:
    void moveZeroes(vector<int>& n) {
       for(size_t j=0,i=0;i<n.size();++i){
            if(n[i]!=0){
                std::swap(n[i],n[j]);
                ++j;
            }
        }
    }
};