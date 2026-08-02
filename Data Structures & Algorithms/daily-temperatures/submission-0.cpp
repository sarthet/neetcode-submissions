class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        stack<int> st;
        int size = temperatures.size();
        vector<int> result(size, 0);
        
        for (int i = 0; i < size; i++)
        {
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};

// 0 0 0 10 9
// 3 2 1 0  0