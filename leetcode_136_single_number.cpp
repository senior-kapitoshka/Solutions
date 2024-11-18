class Solution {
public:
    int singleNumber(vector<int>& n) {
        std::unordered_map<int,int>mp;
        for(auto i:n){
            ++mp[i];
        }
        return std::find_if(mp.begin(),mp.end(),[](auto& p){
            return p.second==1;
        })->first;
    }
};

///////////////////
class Solution {
public:
    int singleNumber(vector<int>& n) {
        int x=0;
        for(auto i:n){
            std::cout<<std::bitset<16>(x).to_string()<<"\n";
            x^=i;// если слева 0 справа 1 => 1 /если слева 1 справа 0 => 0 
            std::cout<<std::bitset<16>(x).to_string()<<"\n\n";
        }
        return x;
    }
};

//////////////////////
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num=0;
        for(int i=0; i<nums.size(); i++){
            num=num^nums[i];
        }
        return num;
    }
};