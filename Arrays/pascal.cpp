#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> pascal(int r)
{
    vector<vector<int>>v;


    for (int i = 0; i < r; i++)
    {
        vector<int>sub(i+1);
        for (int j = 0; j <= i; j++)
        {
            
            if (j == 0 || j == i)
            {
                sub[j]=1;
            }

            else{
                sub[j] = v[i-1][j-1] + v[i-1][j];
            }
        }

        v.push_back(sub);
    }

    return v;
}

int main()
{
    int row;
    cin >> row;

    vector<vector<int>> ans = pascal(row);

    for(int i = 0 ; i<row ; i++){
        for(int j = 0 ; j<=i ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}