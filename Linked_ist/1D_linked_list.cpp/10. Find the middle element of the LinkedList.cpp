class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;

        while(temp) {
            cnt++;
            temp = temp->next;
        }
        int k=cnt/2;
        
        int cnt1=0;
        while(cnt1!=k){
            head=head->next;
            cnt1++;
        }

        return head;
    }
};
//-2
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};