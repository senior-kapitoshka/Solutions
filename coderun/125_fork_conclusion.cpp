#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <algorithm>
#include <iterator>

struct Node{
    Node(int n,std::unique_ptr<Node> lf=nullptr, std::unique_ptr<Node> rh=nullptr)
    :val(n),l(std::move(lf)),r(std::move(rh)){}
    int val;
    std::unique_ptr<Node> l;
    std::unique_ptr<Node> r;
};

std::unique_ptr<Node> add(std::unique_ptr<Node>root,int n){
    if(!root){
        return std::make_unique<Node>(n);
    }
    if(root->val>n){
        root->l=add(std::move(root->l),n);
    }else if(root->val<n){
        root->r=add(std::move(root->r),n);
    }
    return root;
}

void trav(std::unique_ptr<Node> root,std::set<int>&vis){
    if(!root) return;
    if(root->l && root->r) vis.insert(root->val);
    if(root->l)trav(std::move(root->l),vis);
    if(root->r) trav(std::move(root->r),vis);
}

int main() 
{
    int x;
    std::cin>>x;
    auto root=std::make_unique<Node>(x,nullptr,nullptr);
	while(x!=0){
        std::cin>>x;
        if(x==0) break;
        root =add(std::move(root),x);
    }
    std::set<int>vis;
    trav(std::move(root),vis);

    std::copy(vis.begin(),vis.end(),
        std::ostream_iterator<int>(std::cout,"\n"));
	return 0;
}
///////////////