class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        Node* curr = head;
        vector<vector<int>> result;

        while (curr != NULL) {
            Node* curr1 = curr->next;

            while (curr1 != NULL) {
                int sum = curr->data + curr1->data;

                if (sum == target) {
                    result.push_back({curr->data, curr1->data});
                }
                else if (sum > target) {
                    break;
                }

                curr1 = curr1->next;
            }

            curr = curr->next;
        }

    }
};

//-2
class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(Node* head, int target) {
        vector<vector<int>> result;

        if (!head) return result;

        Node* left = head;
        Node* right = head;

        // Move right to last node
        while (right->next != NULL) {
            right = right->next;
        }

        // Two-pointer traversal
        while (left != right && left->prev != right) {
            int sum = left->data + right->data;

            if (sum == target) {
                result.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return result;
    }
};