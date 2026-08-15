/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceilValue = -1;
        
        if(root->data==x) return x;
        
        while(root) {
            if(root->data==x) return x;
            
            if(root->data>x) {
                ceilValue = root->data;
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        
    return ceilValue;
    }
};
