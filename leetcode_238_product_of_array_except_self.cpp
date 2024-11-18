class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
        std::vector<int>res;
        res.reserve(n.size());
        int z_cnt=0;
        int p=std::accumulate(n.begin(),n.end(),1,[&z_cnt]
        (auto pr, auto cr){
            if(cr==0) ++z_cnt;
            return pr*=(cr==0)?1:cr;
        });
        if(z_cnt==0){
            std::transform(n.begin(),n.end(),
            std::back_inserter(res),[&p](auto i){
                return p/i;
            });
        }else if(z_cnt==1){
            std::transform(n.begin(),n.end(),
            std::back_inserter(res),[&p](auto i){
                return i==0?p:0;
            });
        }else if(z_cnt>1){
            res.resize(n.size());
            std::fill(res.begin(),res.end(),0);
        }
        return res;
    }
};
//////////////////////////
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size()), right(nums.size());
	exclusive_scan(nums.begin(), nums.end(), left.begin(), 1, multiplies<>{});
	exclusive_scan(nums.rbegin(), nums.rend(), right.rbegin(), 1, multiplies<>{});
	transform(left.begin(), left.end(), right.begin(), left.begin(), multiplies<>{});
	return left;    
    }
};


////////////////////////
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n);
        
        int* res = result.data();
        const int* num = nums.data();
        int left_prod = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = left_prod;
            left_prod *= num[i];
        }
        
        int right_prod = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= right_prod;
            right_prod *= num[i];
        }
        
        return result;
    }
};

////////////////////
