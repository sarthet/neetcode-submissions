class Solution {
private:
    static constexpr char SUM = '+';
    static constexpr char DOUBLE = 'D';
    static constexpr char CANCEL = 'C';
public:
    int calPoints(vector<string>& operations)
    {
        vector<int> seq;
        for (auto& operation : operations)
        {
            switch (operation[0])
            {
                case SUM:
                    {
                        int val1 = seq[seq.size() - 1];
                        int val2 = seq[seq.size() - 2];
                        seq.push_back(val1 + val2);
                    }
                    break;
                case DOUBLE:
                    {
                        int val = seq.back();
                        seq.push_back(val * 2);
                    }
                    break;
                case CANCEL:
                    seq.pop_back();
                    break;
                default:
                    {
                        int value = std::stoi(operation);
                        seq.push_back(value);
                    }
                    break;
            }
        }

        return seq.empty() ? 0 : std::accumulate(seq.begin(), seq.end(), 0);
    }
};