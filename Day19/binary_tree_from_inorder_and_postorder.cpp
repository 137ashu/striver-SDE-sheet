class Solution {
public:

//My code is EXACT same with the striver's explanation, still I am getting an overflow error.
//In the comments , is the code of a guy , which runs, and is exact same as mine, idk where I've made a slight mistake.
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size()!=postorder.size()) return NULL;
        
        map<int, int> mp;
        for(int i = 0; i< inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return BuildaTwee(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1,  mp);
        
    }
    
    TreeNode* BuildaTwee(vector<int> &inorder, int instart, int inend,vector<int> &postorder, int poststart, int postend,  map<int, int> &mp){
        
        if(instart>inend || poststart>postend) return NULL;
        
        TreeNode  *root = new TreeNode(postorder[postend]);
        
        int inroot = mp[root->val];
        int numleft = inroot - instart;
        
        root->left = BuildaTwee( inorder, instart, inroot-1,postorder, poststart, postend+numleft-1, mp);
        root->right = BuildaTwee( inorder, inroot+1, inend, postorder, poststart+numleft, postend-1,mp);
        
        
        return root;
    }
    
    
    
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
// {
//     if(inorder.size()!=postorder.size())
//         return NULL;
//     map<int,int> m;
    
//     for(int i=0;i<inorder.size();i++)
//     {
//         m[inorder[i]]=i;
//     }
    
//     return BuildsTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
// }
// TreeNode *BuildsTree(vector<int> &inorder,int instart,int inend,vector<int> &postorder,int poststart,int postend,map<int,int> &m)
// {
//     if(instart>inend || poststart>postend)
//         return NULL;
    
//     TreeNode *curr=new TreeNode(postorder[postend]);
    
//     int inroot=m[curr->val];
//     int numleft=inroot-instart;
    
//     curr->left=BuildsTree(inorder,instart,inroot-1,postorder,poststart,poststart+numleft-1,m);
//     curr->right=BuildsTree(inorder,inroot+1,inend,postorder,poststart+numleft,postend-1,m);
    
//     return curr;
// }
};