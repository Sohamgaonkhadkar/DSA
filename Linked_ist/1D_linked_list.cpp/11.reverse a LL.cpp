class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = NULL;
        ListNode* e = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=e;
            e=curr;
            curr=temp;

        }
        return e;
    }
};