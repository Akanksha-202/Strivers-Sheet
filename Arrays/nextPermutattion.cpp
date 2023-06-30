#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permutation(vector<int> &nums)
{
    int size = nums.size();
    int index = -1;

    for (int i = size - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        sort(nums.begin(), nums.end());
    }

    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }
        sort(nums.begin() + index + 1, nums.end());
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    permutation(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}