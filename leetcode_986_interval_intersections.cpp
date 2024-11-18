class Solution {
    enum Stat{
        begin=0,
        end=1
    };
    struct Node{
        Node(int n,Stat t): val(n),s(t){}
        int val;
        Stat s;
    };
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        std::vector<Node>vn;
        vn.reserve(f.size()+s.size());
        for(auto p:f){
            vn.emplace_back(p.front(),Stat::begin);
            vn.emplace_back(p.back(),Stat::end);
        }
        for(auto p:s){
            vn.emplace_back(p.front(),Stat::begin);
            vn.emplace_back(p.back(),Stat::end);
        }
        std::sort(vn.begin(),vn.end(),[]
        (auto& lhs,auto& rhs){
            return lhs.val<rhs.val || (lhs.val==rhs.val && lhs.s<rhs.s);
        });
        std::vector<std::vector<int>>res;
        int start=-1;
        int act=0;
        for(auto& n:vn){
            if(n.s==Stat::begin ){
                if(act==1)start=n.val;
                ++act;
            }else if(n.s==Stat::end ){
                --act;
                if(act==1){
                    res.push_back({start,n.val});
                }
                /*
                    or:
                    if(act==2){
                        res.push_back({start,n.val});
                    }
                    --act;
                */
            }
        }
        return res;
    }
};