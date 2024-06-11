//проходит 22 из 59 

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <cmath>

struct Node{
    Node(int d,int i,int h,std::unique_ptr<Node> l=nullptr,std::unique_ptr<Node>r=nullptr)
    :data(d),id(i),ht(h),lf(std::move(l)),rh(std::move(r)){}
    int data;
    int id;
    int ht;
    std::unique_ptr<Node>lf;
    std::unique_ptr<Node>rh;
};

std::unique_ptr<Node> add(std::unique_ptr<Node>root,int val,int i, int&& h){
    if(!root) return std::make_unique<Node>(val,i,h);
    if(root->data<val){
        root->lf=add(std::move(root->lf),val,i,h+1);
    }else if(root->data>val){
        root->rh=add(std::move(root->rh),val,i,h+1);
    }
    return root;
}


int depth(std::unique_ptr<Node>root){
    if(!root) return 0;
    
    int left_depth = depth(std::move(root->lf));
    int right_depth = depth(std::move(root->rh));

    if( left_depth > right_depth)
        return left_depth+1;
    else
        return right_depth+1;
    
}

void check(std::unique_ptr<Node>root){

    std::abs(depth(std::move(root->lf))-depth(std::move(root->rh)))<=1?std::cout<<"YES":std::cout<<"NO";
}

int main() 
{
	int x;
    std::cin>>x;
    auto root=std::make_unique<Node>(x,0,1);
    int i=1;
    while(true){
        std::cin>>x;
        if(x==0) break;

        root=add(std::move(root),x,i,1);
        ++i;
    }
    check(std::move(root));

	return 0;
}

//////////////////////////////////
//проходит все тесты
////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <cmath>

struct Node{
    Node(int d,int i,int h,std::unique_ptr<Node> l=nullptr,std::unique_ptr<Node>r=nullptr)
    :data(d),id(i),ht(h),lf(std::move(l)),rh(std::move(r)){}
    int data;
    int id;
    int ht;
    std::unique_ptr<Node>lf;
    std::unique_ptr<Node>rh;
};

std::unique_ptr<Node> add(std::unique_ptr<Node>root,int val,int i, int&& h){
    if(!root) return std::make_unique<Node>(val,i,h);
    if(root->data<val){
        root->lf=add(std::move(root->lf),val,i,h+1);
    }else if(root->data>val){
        root->rh=add(std::move(root->rh),val,i,h+1);
    }
    return root;
}


int depth(std::unique_ptr<Node>root){
    if(!root) return 1;
    
    int h1 = depth(std::move(root->lf));
    int h2 = depth(std::move(root->rh));

    if (h1 == 0 || h2 == 0 || abs(h1 - h2) > 1)
            return 0;
    else
            return std::max(h1, h2) + 1;
    
}

void check(std::unique_ptr<Node>root){

    depth(std::move(root))?std::cout<<"YES":std::cout<<"NO";
}

int main() 
{
	int x;
    std::cin>>x;
    auto root=std::make_unique<Node>(x,0,1);
    int i=1;
    while(true){
        std::cin>>x;
        if(x==0) break;

        root=add(std::move(root),x,i,1);
        ++i;
    }
    check(std::move(root));

	return 0;
}

