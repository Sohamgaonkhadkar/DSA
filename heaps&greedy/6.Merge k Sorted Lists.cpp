class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min Heap
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        // Push first node of every list
        for(int i = 0; i < lists.size(); i++) {

            if(lists[i] != NULL) {

                pq.push({
                    lists[i]->val,
                    lists[i]
                });
            }
        }

        // Dummy node
        ListNode* dummy = new ListNode(-1);

        ListNode* temp = dummy;

        // Process heap
        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            ListNode* curr = it.second;

            // Attach node
            temp->next = curr;
            temp = temp->next;

            // Push next node
            if(curr->next != NULL) {

                pq.push({
                    curr->next->val,
                    curr->next
                });
            }
        }

        return dummy->next;
    }
};