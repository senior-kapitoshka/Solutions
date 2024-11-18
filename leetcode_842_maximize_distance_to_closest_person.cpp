class Solution {
public:
    int maxDistToClosest(vector<int>& s) {
        auto b=std::find(s.begin(),s.end(),1);
        auto e=std::find(s.rbegin(),s.rend(),1);
        int mx=std::max(std::distance(s.begin(),b),
        std::distance(e.base(),s.end()));
        std::for_each(b,e.base(),[&mx,cnt=0](auto& i)mutable{
            if(i==0)++cnt;
            else if(i==1){
                int x=cnt%2==0?(cnt/2):(cnt/2+1);
                mx=std::max(x,mx);
                cnt=0;
            }
        });
        return mx;
    }
};

/////////////////////
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int res = 0;
        if(seats[0] == 0){
            for(int i = 1; i < n; i++){
                if(seats[i] == 1) {res = max(i, res); break;}
            }
        }
        if(seats[n-1] == 0){
            for(int i = n-1; i >= 0; i--){
                if(seats[i] == 1) {res = max(n-i-1, res); break;}
            }
        }
        
        int zeros = 0;
        int total = 0;
        for(int i = 0 ; i < n; i++){
            if(seats[i] == 0) zeros++;
            else zeros = 0;
            total = max(zeros, total);
        }
        
        return max(res, (total+1)/2);
        
    }
};

////////////////
class Solution {
public:
    int maxDistToClosest(vector<int>& nums) {
        stack <int> st;
        int i=0,ans=INT_MIN;
        while(i<nums.size())
        {
            if(st.empty())
            {
                while(nums[i]!=1)
                i++;
                ans=max(ans,i);
                st.push(i);
            }
            else{
                if(nums[i]==1)
                {
                    int c=(i-st.top())/2;
                    ans=max(ans,c);
                    st.push(i);
                }
                else if(nums[i]==0 && i==nums.size()-1)
                ans=max(ans,i-st.top());
                i++;
            }
        }
        return ans;
    }
};

///////////////
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prev = -1 ; 
        int dist = 0 ; 
        for (int i = 0 ; i<seats.size() ; i++) {
if (seats[i]==1) {
    if (prev==-1) {
        dist = max(dist,i) ;
    }
    else {
        dist = max(dist,(i-prev)/2) ; 
    }
    prev = i ; 
}
        }
        int n = seats.size() ;
        dist = max(dist,n-1-prev) ;
        return dist ;
    }
};