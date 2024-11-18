class Solution {
public:
    struct Pair{
        long b,e;
    };
    vector<string> summaryRanges(vector<int>& n) {
        if(n.empty()) return {};
        else if(n.size()==1) return {std::to_string(n.front())};
        Pair p{n.front(),n.front()};
        std::vector<Pair>vp;
        for(size_t i=1;i<n.size();++i){
            if(n[i]==n[i-1]+1){
                p.e=n[i];
            }else{
                vp.push_back(p);
                p={n[i],n[i]};
            }
        }
        p.e=n.back();
        vp.push_back(p);
       std::vector<std::string>res; 
       std::transform(vp.begin(),vp.end(),
       std::back_inserter(res),[](auto& p){
            std::string res;
            if(p.b==p.e) res=std::to_string(p.b);
            else{
                res=std::to_string(p.b)+"->"+std::to_string(p.e);
            }
            return res;
       }); 
       return res;
    }
};

//////////////////////////
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>out;
        if(nums.size()==0) return out;
        
        int l = 1;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]+1!=nums[i+1]){
                string x = to_string(nums[i-l+1]);
                if(l!=1)
                    x += "->" + to_string(nums[i]);
                out.push_back(x);
                l = 1;
            }
            else l++;
        }

        string x = to_string(nums[nums.size()-l]);
        if(l!=1)
            x += "->" + to_string(nums[nums.size()-1]);
        out.push_back(x);

        return out;
    }
};