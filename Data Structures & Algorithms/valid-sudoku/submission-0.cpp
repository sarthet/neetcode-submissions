class Solution {
    static constexpr int size = 9;

    vector<unordered_set<char>> vertical;
    vector<unordered_set<char>> horizontal;

    bool checkSubBox(const vector<vector<char>>& board, pair<int, int> leftCorner)
    {
        unordered_set<char> subBox;
        for (int i = leftCorner.first; i < leftCorner.first + 3; i++)
        {
            for (int j = leftCorner.second; j < leftCorner.second + 3; j++)
            {
                if (!std::isdigit(board[i][j])) continue;

                auto elem = board[i][j];
                if (vertical[j].count(elem) ||
                    horizontal[i].count(elem) ||
                    subBox.count(elem))
                {
                    return false;
                }
                vertical[j].insert(elem);
                horizontal[i].insert(elem);
                subBox.insert(elem);
            }
        }

        return true;
    }
public:
    Solution() { vertical.resize(size); horizontal.resize(size); }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < size; i = i + 3)
        {
            for (int j = 0; j < size; j = j + 3)
            {
                if (!checkSubBox(board, {i, j}))
                {
                    return false;
                }
            }
        }

        return true;
    }
};
