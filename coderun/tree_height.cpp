#include <iostream>
#include <string>
#include <vector>
#include <set>

struct Node{
    Node(int d,Node* l=nullptr,Node* r=nullptr)
    :data(d),lf(l),rh(r){}
    int data=0;
    Node* lf;
    Node* rh;
};

Node* add(Node* root, int val){
    if(!root) return new Node(val);
    if(root->data<val){
        root->lf=add(root->lf,val);
    }else if(root->data>val){
        root->rh=add(root->rh,val);
    }
    return root;
}

int depth(Node *root){
    if(!root) return 0;
    int mr=depth(root->rh);
    int ml=depth(root->lf);
    return std::max(mr,ml)+1;
}

int main() 
{
    int x;
    std::cin>>x;
    Node* root=new Node(x);
    while(true){
        std::cin>>x;
        if(x==0) break;
        root=add(root,x);
    }

    std::cout<<depth(root)<<"\n";
    
	return 0;
}