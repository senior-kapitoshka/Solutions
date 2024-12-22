#include <set>
#include <vector>
#include <cstdint>

class Stock{
private:
    struct Weight{
        uint64_t id;
        int w_;
        bool operator<(const Weight& w)const{
            if(w_==w.w_){
                return id > w.id;
            }
            return w_< w.w_;
        }
    };
    struct Value{
        uint64_t id;
        int v_;
        bool operator<(const Value& w)const{
            if(v_==w.v_){
                return id > w.id;
            }
            return v_< w.v_;
        }
    };
    struct It{
        std::set<Weight>::iterator wt;
        std::set<Value>::iterator vl;
    };
    std::vector<It>vc;
    std::set<Weight>sw;
    std::set<Value>sv;
    size_t cnt=0;
public:
     void Add(int w, int v){
        vc.push_back({sw.insert(Weight{cnt,w}).first,sv.insert(Value{cnt,v}).first});
        ++cnt;
     } 
     int GetByW(int min_w){
       int res=-1;
       auto it=sw.lower_bound({cnt,min_w});
       if(it==sw.end()) return res;
       else{
           res=it->id;
           sw.erase(it);
           sv.erase(vc[res].vl);
       }
       return res;
     }  
     int GetByV(int min_v){
         int res=-1;
       auto it=sv.lower_bound({cnt,min_v});
       if(it==sv.end()) return res;
       else{
           res=it->id;
           sv.erase(it);
           sw.erase(vc[res].wt);
       }
       return res;
     }
};

