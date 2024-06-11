#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

struct Node{
    int cnt;
    int x,y;
};
bool operator<(const Node& l,const Node& r){
    return l.cnt<r.cnt;
}

bool operator==(const Node& l,const Node& r){
    return l.cnt==r.cnt;
}
std::ostream& operator<<(std::ostream& os,const Node& n){
     os<<n.cnt<<"-{"<<n.x<<","<<n.y<<"}";
     return os;
}

struct hasher{
    size_t operator()(const Node& n)const{
        return n.cnt^n.x^n.y^(n.cnt>>1)^(n.x>>1)^(n.y>>1);
    }
};

#if 1
void make_graph(std::pair<int,int>& cd,
std::unordered_map<Node,std::vector<Node>,hasher>&gr,std::set<std::pair<int,int>>& st, int& cnt){

    if(st.count(cd)) return;
    st.insert(cd);
    if(cd.first-2>=1 && cd.second-1>=1){
        int c=cnt+1;
        std::pair<int,int> pr={cd.first-2,cd.second-1};
        make_graph(pr,gr,st,c);
        gr[{cnt,cd.first,cd.second}].push_back(Node{c,cd.first-2,cd.second-1});
    }
    if(cd.first-1>=1 && cd.second-2>=1){
        int c=cnt+1;
         std::pair<int,int> pr={cd.first-1,cd.second-2};
        make_graph(pr,gr,st,c);
        gr[{cnt,cd.first,cd.second}].push_back(Node{c,cd.first-1,cd.second-2});
    }
    if(cd.first-2>=1 && cd.second+1<=8){
        int c=cnt+1;
        std::pair<int,int> pr={cd.first-2,cd.second+1};
        make_graph(pr,gr,st,c);
        gr[{cnt,cd.first,cd.second}].push_back(Node{c,cd.first-2,cd.second+1});
    }
    if(cd.first-1>=1 && cd.second-2>=1){
        int c=cnt+1;
        std::pair<int,int> pr={cd.first-1,cd.second-2};
        make_graph(pr,gr,st,c);
        gr[Node{cnt,cd.first,cd.second}].push_back(Node{c,cd.first-1,cd.second-2});
    }
    if(cd.first-1>=1 && cd.second+2<=8){
        int c=cnt+1;
        std::pair<int,int> pr={cd.first-1,cd.second+2};
        make_graph(pr,gr,st,c);
        gr[Node{cnt,cd.first,cd.second}].push_back(Node{c,cd.first-1,cd.second+2});
    }
    if(cd.first+1<=8 && cd.second+2<=8){
        int c=cnt+1;
        std::pair<int,int> pr={cd.first+1,cd.second+2};
        make_graph(pr,gr,st,c);
        gr[{cnt,cd.first,cd.second}].push_back(Node{c,cd.first+1,cd.second+2});
    }
    if(cd.first+2<=8 && cd.second+1<=8){
        int c=cnt+1;
        std::pair<int,int> pr={cd.first+2,cd.second+1};
        make_graph(pr,gr,st,c);
        gr[{cnt,cd.first,cd.second}].push_back(Node{c,cd.first+2,cd.second+1});
    }
    if(cd.first+2<=8 && cd.second-1>=1){
        int c=cnt+1;
        std::pair<int,int> pr={cd.first+2,cd.second-1};
        make_graph(pr,gr,st,c);
        gr[{cnt,cd.first,cd.second}].push_back(Node{c,cd.first+2,cd.second-1});
    }
}
#endif

int main() 
{
    std::string r,g;
	std::cin>>r>>g;
    std::pair<int,int>red={98-r.front(),std::stoi(r.substr(1))};
    std::pair<int,int>grn={98-g.front(),std::stoi(g.substr(1))};

    std::unordered_map<Node,std::vector<Node>,hasher>gr_red,gr_grn;
    int cnt=1;
    std::set<std::pair<int,int>>st;
    make_graph(red,gr_red,st,cnt);
    make_graph(grn,gr_grn,st,cnt);

    std::cout<<gr_red.size();

    for(auto n:gr_red){
        std::cout<<n.first<<":";
        for(auto i:n.second){
            std::cout<<i<<",";
        }
        std::cout<<"\n";
    }
    
	return 0;
}
