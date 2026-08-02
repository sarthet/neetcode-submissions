class Solution {
    int m_size;
    vector<string> result;
    void backtrack(int openCount, int closedCount, string current)
    {
        if (openCount == m_size && closedCount == m_size)
        {
            result.push_back(current);
            return;
        }

        if (openCount < m_size)
        {
            backtrack(openCount + 1, closedCount, current + "(");
        }

        if (closedCount < openCount)
        {
            backtrack(openCount, closedCount + 1, current + ")");
        }
    }
public:
    vector<string> generateParenthesis(int n)
    {
        m_size = n;

        string current;
        int openCount = 0;
        int closedCount = 0;

        backtrack(openCount, closedCount, current);

        return result;
    }
};
