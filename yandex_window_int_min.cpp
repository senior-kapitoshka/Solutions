#include <iostream>
#include <queue>
#include <vector>
#include <cstdint>
#include <set>


int main(){
    uint32_t n,k;
    std::cin>>n>>k;
    std::queue<int64_t>q;
    std::multiset<int64_t>s;
    for(uint32_t i=1;i<=n;++i){
        int64_t x;
        std::cin>>x;
        q.push(x);
        s.insert(x);
        if(i>=k){
            std::cout<<*s.begin()<<"\n";
            auto it=s.find(q.front());
            s.erase(it);
            q.pop();
        } 
    }
}

#if 0

int main(){
    uint32_t n,k;
    std::cin>>n>>k;
    std::deque<int64_t>q;
    for(uint32_t i=0;i<n;++i){
        int64_t x;
        std::cin>>x;
        q.push_back(x);
        if(q.size()==k){
            std::priority_queue<int64_t,std::vector<int64_t>,std::greater<int64_t>>pq(q.begin(),q.end());
            std::cout<<pq.top()<<"\n";
            q.pop_front();
        }
    }
}

#endif