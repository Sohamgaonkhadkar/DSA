class Solution {
public:

    // Insert element at bottom
    void insertAtBottom(stack<int>& st, int x){

        // Base case
        if(st.empty()){
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(temp);
    }

    // Reverse stack
    void reverseStack(stack<int>& st){

        // Base case
        if(st.empty())
            return;

        int x = st.top();
        st.pop();

        reverseStack(st);

        insertAtBottom(st, x);
    }
};