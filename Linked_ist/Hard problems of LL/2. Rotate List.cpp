
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int cnt=1,cnt1 = 0;
     
        if(head == NULL || head->next == NULL || k == 0)
            return head;

        ListNode* temp = head;

        while(temp->next != NULL){
            cnt++;
            temp = temp->next;
        }
         k = k % cnt;

        if(k == 0)
            return head;
        int m=cnt-k-1;
        ListNode* curr=head;
        while(cnt1!=m){
            curr=curr->next;
            cnt1++;
        }
        temp->next=head;
        head=curr->next;
        curr->next=NULL;
        return head;
    }
};