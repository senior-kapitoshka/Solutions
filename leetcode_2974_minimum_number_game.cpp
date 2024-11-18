class Solution {
public:
    vector<int> numberGame(vector<int>& n) {
        std::sort(n.begin(),n.end());
        std::vector<int>res;
        res.reserve(n.size());
        int b=0;
        for(size_t i=0;i<n.size();++i){
            if(i%2==0){
                b=n[i];
            }else{
                res.push_back(n[i]);
                res.push_back(b);
            }
        }
        return res;
    }
};

/////////////////
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>>pq(nums.begin(), nums.end());
        vector<int>result;
        
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            int secondTop = pq.top();
            pq.pop();

            result.push_back(secondTop);
            result.push_back(top);
        }
        return result;
    }
};