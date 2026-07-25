/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
void reverse(ListNode* left,int size){
    ListNode* curr = left;
    ListNode* prev = nullptr;
    while(size--){
        ListNode* nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr)
         return head;
        ListNode* left = head;
        ListNode* right;
        ListNode* res = nullptr;
        ListNode* prevleft = nullptr;
        int size = k;
        while(true){
            right = left;
            for(int i=0; i<size-1; i++){
                if(right == nullptr)
                 break;
                right = right->next;
            }
            if(right){    // left aur right mil chuke hai
                ListNode* nextleft = right->next;
                reverse(left,size);
                if(prevleft)
                 prevleft->next = right;
                prevleft = left;
                if(res == nullptr)
                 res = right;
                left = nextleft;
            }
            else{  // right null ho chuka hai
                if(prevleft)
                 prevleft->next = left;
                if(res == nullptr)
                 res = left;
                break;
            }
        }
        return res;
    }
};