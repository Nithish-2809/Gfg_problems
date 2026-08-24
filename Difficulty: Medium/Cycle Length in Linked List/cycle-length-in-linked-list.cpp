class Solution {
    public:
      int lengthOfLoop(Node *head) {
          Node *slow = head;
          Node *fast = head;

          while(fast != NULL && fast->next != NULL) {
              slow = slow->next;
              fast = fast->next->next;

              if(slow == fast) {
                  int len = 1;
                  Node *temp = slow->next;

                  while(temp != slow) {
                      temp = temp->next;
                      len++;
                  }

                  return len;
              }
          }

          return 0;
      }
  };