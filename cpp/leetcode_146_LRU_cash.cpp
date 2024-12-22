class LRUCache {
private:
    struct Info{
        Info(int k,int v):key(k),val(v){}
        int key,val;
    };
    int cap;
    std::unordered_map<int,std::list<Info>::iterator>mp;
    std::list<Info> ls;

public:
    LRUCache(int capacity):cap(capacity) { 
    }
    int get(int key) {
        const auto it=mp.find(key);
        int res=-1;
        if(it!=mp.end()){
            res=it->second->val;
            ls.splice(ls.begin(),  ls,  it->second);
            //        |   to   |from list|   what   |  
            it->second=ls.begin();
        }
        return res;
    }    
    void put(int key, int value) {
        auto it=mp.find(key);
        if(it==mp.end()){
            ls.push_front({key,value});
            mp[key]=ls.begin();
        }else{
            it->second->val=value;
            ls.splice(ls.begin(),ls,it->second);
            it->second=ls.begin();
        }
        while(ls.size()>cap){
            mp.erase(ls.rbegin()->key);
            ls.pop_back();
        }
    }
};
///////////////////////////////
class LRUCache {
public:
    int capacity;
    set<pair<int,int>> st;
    unordered_map<int,pair<int,int>> hashtable;
    int time = 0;
    LRUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
    }
    
    int get(int key) {
        if(hashtable.count(key)){
            st.erase({hashtable[key].second, key});
            st.insert({time,key});
            hashtable[key].second = time;
            time++;
            return hashtable[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {

        if(hashtable.size() == capacity && hashtable.count(key) == 0){
            int lru_key = st.begin()->second;
            st.erase(st.begin());
            hashtable.erase(lru_key);

        }
            if(hashtable.count(key)){
                st.erase({hashtable[key].second, key});
            }
            hashtable[key] = {value, time};
            st.insert({time, key});
            time++;
    }
};



////////////////////////////
struct Node{
    int data;
    int value;
    Node* before;
    Node* after;
    Node(int val,int valu){
        data = val;
        value = valu;
        before = NULL;
        after = NULL;
    }
};
class LRUCache {
    unordered_map<int,Node*> lookup;
    Node* head;
    Node* tail;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = head;
    }
    
    int get(int key) {
        if(lookup.find(key)==lookup.end()) return -1;
        Node* ptr = lookup[key];
        if(tail == ptr) {
            tail = tail->before;
            tail->after = NULL;
        }
        ptr->before->after = ptr->after;
        if(ptr->after) ptr->after->before = ptr->before;
        ptr->after = head->after;
        ptr->before= head;
        if(head->after) head->after->before = ptr;
        head->after = ptr;
        if(head==tail) tail = head->after;
        return ptr->value;
    }
    
    void put(int key, int value) {
        if(lookup.find(key)==lookup.end()&&lookup.size()==cap){
            lookup.erase(tail->data);
            tail = tail->before;
            
            tail->after = NULL;
        }
        if(lookup.find(key)==lookup.end()) lookup[key] = new Node(key,value);
        lookup[key]->value = value;
        Node* ptr = lookup[key];
        if(tail == ptr) {
            tail = tail->before;
            tail->after = NULL;
        }
        if(ptr->before) ptr->before->after = ptr->after;
        if(ptr->after) ptr->after->before = ptr->before;
        ptr->after = head->after;
        ptr->before= head;
        if(head->after) head->after->before = ptr;
        head->after = ptr;
        if(lookup.size()==1) tail = ptr;
    }
};

/////////////////////////////

class LRUCache {
public:
    
    const int VALUES = 100'005;
    
    vector<int> cnt;
    vector<int> t;
    
    deque< pair<int, int> > q;
    
    int cap;
    int timestamp = 0;
    
    LRUCache(int capacity) {
        cnt.clear(); cnt.resize(VALUES); fill(cnt.begin(), cnt.end(), -1);
        t.clear(); t.resize(VALUES); fill(t.begin(), t.end(), -1);
        cap = capacity;    
    }
    
    int get(int key) {
        if (cnt[key] == -1) return -1;
        ++timestamp;
        t[key] = timestamp;
        q.push_back({key, timestamp});
        ++cap;
        return cnt[key];
    }
    
    void put(int key, int value) {
        
        if (cnt[key] != -1) {
            ++timestamp;
            t[key] = timestamp;
            q.push_back({key, timestamp});
            ++cap;
            cnt[key] = value;
            return;
        }
        
        if (q.size() < cap) {
            ++timestamp;
            t[key] = timestamp;
            q.push_back({key, timestamp});
            cnt[key] = value;
        } else {
            
            while (!q.empty() && t[q.front().first] != q.front().second) {
                q.pop_front();
                --cap;
            }
            assert(t[q.front().first] == q.front().second);
            cnt[ q.front().first ] = -1;
            q.pop_front();
            put(key, value);
            
        }
    }
};

///////////////////

