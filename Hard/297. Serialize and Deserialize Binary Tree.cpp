/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        if(!root) return result;
        queue<TreeNode*> cur;
        //queue<TreeNode*>sub;
        cur.push(root);
        while(!cur.empty()){
            TreeNode* node = cur.front(); cur.pop();
            result.append(node ? to_string(node->val) + "," : ",");
            if(node){
                cur.push(node->left);
                cur.push(node->right);
            }
           // if(cur.empty()) swap(cur, sub);
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data.size() == 0) return NULL;
        string s;
        stringstream ss(data);
        getline(ss, s, ',');
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            getline(ss, s, ',');
            TreeNode* left = s.size() ? new TreeNode(stoi(s)) : NULL;
            getline(ss, s, ',');
            TreeNode* right = s.size() ? new TreeNode(stoi(s)) : NULL;
            node->left = left;
            node->right = right;
            if(left) q.push(left);
            if(right) q.push(right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));