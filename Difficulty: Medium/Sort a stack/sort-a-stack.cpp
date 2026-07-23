class Solution {
public:
    void insert(stack<int> &st, int el) {
        // If stack is empty or el should be on top
        if (st.empty() || st.top() <= el) {
            st.push(el);
            return;
        }

        int topEl = st.top();
        st.pop();

        insert(st, el);

        st.push(topEl);
    }

    void sortStack(stack<int> &st) {
        if (st.empty())
            return;

        int el = st.top();
        st.pop();

        sortStack(st);

        insert(st, el);
    }
};