class Solution {
public:
    int mySqrt(int x)
    {
        if (x == 0) return 0;
        long res = 1;
        while (res * res <= x) res++;

        return res - 1;
    }
};

// 10 / 3