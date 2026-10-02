class Solution {
public:

    // Insert element in sorted position
    void insertSorted(stack<int>& st, int x){

        // Correct position found
        if(st.empty() || st.top() <= x){
            st.push(x);
            return;
        }

        int temp = st.top();    
        st.pop();

        insertSorted(st, x);

        st.push(temp);
    }

    // Sort stack recursively
    void sortStack(stack<int>& st){

        // Base case
        if(st.empty())
            return;

        int x = st.top();
        st.pop();
       // Sort remaining stack
        sortStack(st);

        // Insert current element correctly
        insertSorted(st, x);
    }
};