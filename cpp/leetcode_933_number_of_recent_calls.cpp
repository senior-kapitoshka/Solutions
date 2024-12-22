class RecentCounter {
   unsigned cnt; 
   std::vector<int>calls;
public:
    RecentCounter(): cnt(0){}
    int ping(int t) {
        calls.push_back(t);
        if(calls[cnt]<t-3000) ++cnt;
        return static_cast<int>(calls.size()-cnt);
    }
};