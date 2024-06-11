#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Node{
    Node(int x,Node* lf=nullptr,Node* rh=nullptr):
    data(x),l(lf),r(rh){} 
    int data;
    Node* l=nullptr;
    Node* r=nullptr;
};

Node* rotr(Node* n){
    Node* x=n->l;
    n->l=x->r;
    x->r=n;
    return x;
}
Node* rotl(Node* n){
    Node* x=n->r;
    n->r=x->l;
    x->l=n;
    return x;
}

Node* Add(Node* root,int d){
    if(!root){
        return new Node(d);
    }
    if(d>root->data){
        
            root->r=Add(root->r,d);
            //rotl(root); ???? doesnt work 
        
    }else if(d<root->data){
        
            root->l=Add(root->l,d);
            //rotr(root); ???? doesnt work
    }
    return root;
}

void travs(Node* root,std::vector<int>&vis){
    if(!root) return;
    if(!root->l && !root->r){
        vis.push_back(root->data);
    }
    if(root->l) travs(root->l,vis);
    if(root->r) travs(root->r,vis);
}        


int main() 
{
	int x;
    std::cin>>x;
    Node* root=new Node(x);
    
    while(true){
        
        std::cin>>x;
        if(x==0) break;
        root=Add(root,x);
    }
    std::vector<int>res;
    travs(root,res);
    for(auto i:res){
        std::cout<<i<<"\n";
    }

	return 0;
}