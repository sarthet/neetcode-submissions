class Solution {
    char getOpenByClosed(char c)
    {
        if (c == ')') return '(';
        else if (c == '}') return '{';
        else if (c == ']') return '[';
        else return '0';
    }
public:
    bool isValid(string s)
    {
        /// (([{}]))
        /// ))
        /// ([{)))
        stack<char> st;
        for (auto c : s)
        {
            auto parent = getOpenByClosed(c);
            if (st.empty() && parent != '0')
            {
                return false;
            }
            if (!st.empty() && st.top() == parent)
            {
                st.pop();
                continue;
            }
            st.push(c);
        }
        return st.empty();
    }
};
