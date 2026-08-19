/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/



int helper(Node *node) {
    if(node==NULL) return 1;
    
    int carry = helper(node->next);
    node->data += carry;
    
    if(node->data==10) {
        node->data = 0;
        return 1;
    };
    
    return 0;
}


class Solution {
  public:
    Node* addOne(Node* head) {
        // code here
        
        int carry = helper(head);
        if(carry==1) {
            Node *newNode = new Node(1);
            newNode->next = head;
            head = newNode;
            return head;
        }
        
        return head;
    }
};