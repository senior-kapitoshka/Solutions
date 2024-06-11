#include <iostream>
#include <string>
#include <vector>
#include <set>

struct Node{
    Node(int d,Node* lf=nullptr,Node* rh=nullptr)
    :data(d),l(lf),r(rh) {}
    int data;
    Node* l;
    Node* r;
};

Node* add(Node* root,int val){
    if(!root) return new Node(val);
    if(root->data>val){
        root->l=add(root->l,val);
    }else if(root->data<val){
        root->r=add(root->r,val);
    }
    return root;
}
void trav(std::set<int>&vis, Node* root){
    if(!root) return;
    if((root->l && !root->r) || (root->r && !root->l)){
        vis.insert(root->data);
    }
    if(root->l)trav(vis,root->l);
    if(root->r)trav(vis,root->r);
}

int main() 
{
	int x;
    std::cin>>x;
    Node *root=new Node(x);
    while(true){
        
        std::cin>>x;
        if(x==0) break;
        root=add(root,x);
    }
    std::set<int>vis;
    trav(vis,root);
    for(auto i:vis){
        std::cout<<i<<"\n";
    }

	return 0;
}