class MyQueue {
private:
    std::deque<int>fs;
    std::deque<int>ss;
public:
    MyQueue()=default;
    
    void push(int x) {
        fs.push_back(x);
        ss.push_front(x);
    }
    
    int pop() {
        int res=fs.front();
        fs.pop_front();
        ss.pop_back();
        return res;
    }
    
    int peek() {
        int res=fs.front();
        return res;
    }
    
    bool empty() {
        return fs.empty() && ss.empty();
    }
};

//////////////////
