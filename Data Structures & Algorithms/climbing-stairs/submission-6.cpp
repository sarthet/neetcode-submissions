class Solution {
    vector<int> memory;
    int steps(int n)
    {
        if (n <= 1)
        {
            return 1;
        }

        if (memory[n] != -1) return memory[n];

        memory[n] = steps(n - 1) + steps(n - 2);
        return memory[n];
    }
public:
    int climbStairs(int n)
    {
        memory.assign(n + 1, -1);
        return steps(n);
    }
};

// 5
// 1 + 4                     || 2 + 3
// 1 + 1 + 3; 1 + 1 + 2 + 2  || 2 + 1 + 2
// 1 + 1 + 1 + 2
