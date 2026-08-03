class Solution {
    std::queue<int> q_students;
    std::stack<int> s_sandwiches;
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int wantCountCirculSand = 0;
        int wantCountSquareSand = 0;
        for (int i = 0; i < students.size(); i++)
        {
            if (!students[i]) wantCountCirculSand++;
            else wantCountSquareSand++;
        }

        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (!wantCountCirculSand && !sandwiches[i]) break;

            if (!wantCountSquareSand && sandwiches[i]) break;

            if (!sandwiches[i]) wantCountCirculSand--;
            else wantCountSquareSand--;           
        }

        return wantCountCirculSand + wantCountSquareSand;
    }
};

// [1,1,1,0,0,1]
// [1,0,0,0,1,1]


// [1,1,0,0,1]
// [0,0,0,1,1]


// [1,0,0,1,1]
// [0,0,0,1,1]

// [0,0,1,1,1]
// [0,0,0,1,1]

// [0,1,1,1]
// [0,0,1,1]

// [1,1,1]
// [0,1,1]