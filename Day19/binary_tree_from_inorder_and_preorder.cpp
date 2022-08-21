class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        map<int, int> mp;
        for(int i = 0; i< pre.size(); i++){
            mp[in[i]]=i;
        }
        TreeNode *root = BuildaTwee(pre, 0, pre.size()-1, in, 0, in.size()-1, mp);
        return root;
    }
    
    TreeNode* BuildaTwee(vector<int> & pre, int prestart, int preend, vector<int> & in, int instart, int inend, map<int, int> &mp){
        
        if(prestart>preend || instart>inend)return NULL;
        
        //the root of the tree will be the first element of preorder traversal
        TreeNode* root = new TreeNode(pre[prestart]);
        
        int inroot = mp[root->val]; //this will provide where the inorder's root lies
        int numsleft = inroot-instart;
        
        root->left = BuildaTwee(pre, prestart+1, prestart+numsleft, in , instart, inroot-1, mp);
        root->right = BuildaTwee(pre, prestart+numsleft+1, preend, in , inroot+1, inend, mp);
        return root;
    }
};