class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& n, int k) {
        return std::accumulate(n.begin(),n.end(),0,[i=0,k]
        (auto sum, auto curr)mutable{
            std::string bs=std::bitset<16>(i++).to_string();
            return sum+=(std::count(bs.begin(),bs.end(),'1')==k)?curr:0;
        });
    }
};

////////////////////
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) 
    {
        int result = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = i;
            int numBits = 0;
            while(temp > 0)
            {
                numBits += temp & 0x01;
                temp >>= 1;
            }
            if(numBits == k)
            {
                result += nums[i];
            }
        }
        return result;
    }
};

///////////////////
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sumVals = 0;
        for(int i = 0; i < nums.size(); i++){
            if(__builtin_popcount(i) == k){
                sumVals += nums[i];
            }
        }
        return sumVals;
    }
};

/////////////////
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        // bitset bits;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            bitset<32> bits(i);
            if(bits.count() == k)
                res += nums[i];
        }
        return res;
    }
};