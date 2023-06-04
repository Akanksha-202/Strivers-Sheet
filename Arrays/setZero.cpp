#include <iostream>
#include <vector>

using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    int indexi, indexj;
    int row = matrix.size();
    int column = matrix[0].size();
    vector<vector<int>> set;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (matrix[i][j] == 0)
            {
                set.push_back({i, j});
            }
        }
    }

    for (int k = 0; k < set.size(); k++)
    {
        indexi = set[k][0];
        indexj = set[k][1];
        for (int k = 0; k < column; k++)
        {
            matrix[indexi][k] = 0;
        }
        for (int k = 0; k < row; k++)
        {
            matrix[k][indexj] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{0, 2, 3}, {1, 0, 3}, {1, 2, 0}};

    setZeros(matrix);

    for (const auto& row : matrix) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }


    return 0;
}