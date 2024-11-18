class RandomizedSet {
private:
    std::unordered_set<int>st;
    std::mt19937 rg;
    int rand(){
        std::uniform_int_distribution<int> range(0, st.size()-1);
        return range(rg);
    }
public:
    RandomizedSet() {
        std::random_device dev;
        rg.seed(dev());
    }
    
    bool insert(int val) {
        if(st.count(val)) return false;
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(!st.count(val)) return false;
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        return *(std::next(st.begin(),rand()));
    }
};

///////////////////////////
class RandomizedSet {
private:
    std::vector<int> set;
public:
    RandomizedSet(){
        
    }
    
    bool insert(int val) {
        for (int i = 0; i < set.size(); i++){
            if (set[i] == val) return false;
        }
        set.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        for (int i = 0; i < set.size(); i++){
            if (set[i] == val){
                std::swap(set[i], set[set.size()-1]);
                set.pop_back();
                return true;
            }
        }
        return false;
    }
    
    int getRandom() {
        int r = rand() % set.size();
        return set[r];
    }
};