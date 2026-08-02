class Solution {
    unordered_map<char, char> closedOpen =
    {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            auto it = closedOpen.find(s[i]);
            if (st.empty() && it != closedOpen.end())
            {
                return false;
            }

            if (it == closedOpen.end())
            {
                st.push(s[i]);
                continue;
            }

            auto top = st.top();
            if (it->second != top) return false;

            st.pop();
        }

        return st.empty();
    }
};
