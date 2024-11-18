class Solution {
public:
    int timeRequiredToBuy(vector<int>& ts, int k) {
        int i=0;
        int cnt=0;
         while(ts[k]>0){
            if(ts[i]>0){
                --ts[i];
                i=(i==ts.size()-1)?0:(i+1);
                ++cnt;
            }else{
                i=(i==ts.size()-1)?0:(i+1);
            }
        }
        return cnt;
    }
};

//////////////
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       

            int n = tickets.size(), time = 0;

            for (int i = 0; i <= k; i++) {
                time += min(tickets[i], tickets[k]);
            }
            for (int i = k + 1; i < n; i++) {
                time += min(tickets[i], tickets[k] - 1);
            }

            return time;
    }
};

/////////////
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int n=tickets.size();
        for(int i=0; i<n; i++){
            q.push(i);
        }
        int Time=0;
        while(tickets[k]!=0){
            tickets[q.front()]--;
            if(tickets[q.front()]){
            q.push(q.front());
            q.pop();
            }
            else{
                q.pop();
            }
            Time++;
        }
        return  Time++;
        
    }
};