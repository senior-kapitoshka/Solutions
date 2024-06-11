
//проходит 8 тестов 

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

struct Node{
    Node(int d,std::unique_ptr<Node> l=nullptr,std::unique_ptr<Node>r=nullptr)
    :data(d),lf(std::move(l)),rh(std::move(r)){}
    int data;
    std::unique_ptr<Node>lf;
    std::unique_ptr<Node>rh;
};

std::unique_ptr<Node> add(std::unique_ptr<Node>root,int val){
    if(!root) return std::make_unique<Node>(val);
    if(root->data<val){
        root->lf=add(std::move(root->lf),val);
    }else if(root->data>val){
        root->rh=add(std::move(root->rh),val);
    }
    return root;
}

void travs(std::unique_ptr<Node>root,std::unordered_map<int,int>& vis,int&& h){
    if(!root) return;
    vis[root->data]=h;
    if(root->lf) travs(std::move(root->lf),vis,h+1);
    if(root->rh) travs(std::move(root->rh),vis,h+1);
    
}

int main() 
{
	int x;
    std::cin>>x;
    std::vector<int>vc;
    vc.push_back(x);
    auto root=std::make_unique<Node>(x);
    while(true){
        std::cin>>x;
        if(x==0) break;
        vc.push_back(x);
        root=add(std::move(root),x);
    }
    std::unordered_map<int,int>vis;
    travs(std::move(root),vis,1);
    for(auto i:vc){
        std::cout<<vis[i]<<' ';
    }

	return 0;
}

/////////////////////////////////
//проходит все тесты
//////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>

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

void travs(std::unique_ptr<Node>root,std::map<int,int>& vis){
    if(!root) return;
    vis[root->id]=root->ht;
    if(root->lf) travs(std::move(root->lf),vis);
    if(root->rh) travs(std::move(root->rh),vis);
    
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
    std::map<int,int>vis;
    travs(std::move(root),vis);
    for(auto i:vis){
        std::cout<<i.second<<' ';
    }

	return 0;
}


///////////////////////////////
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <vector>

using namespace std;

struct BST {
private:
    struct Node {
        Node(int64_t value_): value(value_) {}
        int64_t value;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* root = nullptr;
    vector<size_t> depths;

    Node* find(int64_t value, Node* leaf) const {
        if (leaf != nullptr) {
            if (value == leaf -> value) {
                return leaf;
            } else if (value < leaf -> value) {
                return find(value, leaf->left);
            } else {
                return find(value, leaf->right);
            }
        } else {
            return nullptr;
        }
    }

    void insert(int64_t key, Node* leaf) {
        if (key < leaf -> value) {
            if (leaf -> left != nullptr) {
                return insert(key, leaf -> left);
            } else {
                leaf -> left = new Node(key);
            }
        } else {
            if (leaf -> right != nullptr) {
                return insert(key, leaf -> right);
            } else {
                leaf -> right = new Node(key);
            }
        }
    }

    size_t getDepth (int64_t value, Node* leaf) const {
        if (leaf != nullptr) {
            if (value == leaf -> value) {
                return 1;
            } else if (value < leaf -> value) {
                return getDepth(value, leaf->left) + 1;
            } else {
                return getDepth(value, leaf->right) + 1;
            }
        } else {
            return 0;
        }
    }

public:
    BST& insert(int64_t value) {
        if (root != nullptr) {
            if(find(value, root) == nullptr) {
                insert(value, root);
            	depths.push_back(getDepth(value, root));
            }
        } else {
            root = new Node(value);
        	depths.push_back(getDepth(value, root));
        }
        
        return *this;
    }

    const vector<size_t>& getDepths () const {
        return depths;
    }

};

int main() {
    BST tree;
    int64_t element;
    while ((cin >> element) && (element != 0)) {
        tree.insert(element);
    }

    for (auto i : tree.getDepths()){
        cout << i << ' ';
    }

    return 0;
}