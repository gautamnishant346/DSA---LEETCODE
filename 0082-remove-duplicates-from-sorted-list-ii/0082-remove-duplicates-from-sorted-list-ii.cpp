
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* temp = head;

        while(temp != nullptr) {
            if(temp->next != nullptr &&
               temp->val == temp->next->val) {

                int duplicate = temp->val;

                while(temp != nullptr &&
                      temp->val == duplicate) {
                    temp = temp->next;
                }

                prev->next = temp;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }

        return dummy.next;
    }
};
