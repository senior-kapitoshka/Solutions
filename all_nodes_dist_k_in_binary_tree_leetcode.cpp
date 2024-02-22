class Solution {
public:
    void traverse(TreeNode* n, std::unordered_map<int,std::set<int>>&mp){
        if(!n) return;
        if(n->left) {
            mp[n->val].insert(n->left->val);
            mp[n->left->val].insert(n->val);
        }
        if(n->right){
            mp[n->val].insert(n->right->val);
            mp[n->right->val].insert(n->val);
        }
        traverse(n->left,mp);
        traverse(n->right,mp);
    }

    void collecting(int x,int k,std::vector<int>&res,std::set<int>&vis,std::unordered_map<int,std::set<int>>&mp,int c=0){
        if(vis.count(x)) return;
        vis.insert(x);
        if(!mp.count(x)) return;
        if(c==k){
            res.push_back(x);
            return;
        }
        for(auto& i:mp.at(x)){
            collecting(i,k,res,vis,mp,c+1);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k){
        if(k==0) return {t->val};
        std::unordered_map<int,std::set<int>>mp;
        if(root->left){
            mp[root->left->val].insert(root->val);
            mp[root->val].insert(root->left->val); 
        }
        if(root->right){
            mp[root->right->val].insert(root->val);
            mp[root->val].insert(root->right->val);
        }
        traverse(root,mp);
        std::vector<int> res;    
        std::set<int>vis;
        collecting(t->val,k,res,vis,mp);
        return res;
    }


};