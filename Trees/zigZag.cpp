#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<vector<int>> zigzagLevelOrder(node *root)
{

    vector<vector<int>> ans;

    if (root == NULL)
    {
        return ans;
    }

    queue<node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();

        vector<int> result(size);

        for (int i = 0; i < size; i++)
        {
            node *frontnode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            result[index] = frontnode->data;

            if (frontnode->left)
            {
                q.push(frontnode->left);
            }
            if (frontnode->right)
            {
                q.push(frontnode->right);
            }
        }

        leftToRight = !leftToRight;

        ans.push_back(result);
    }
    return ans;
}

node *buildtree(node *root)
{
    int val;
    cout << "Enter the data: ";
    cin >> val;
    root = new node(val);

    if (val == -1)
    {
        return NULL;
    }

    cout << "Enter the data to be inserted in left of " << val << endl;
    root->left = buildtree(root->left);
    cout << "Enter the data to be inserted in right of " << val << endl;
    root->right = buildtree(root->right);

    return root;
}



int main()
{
    node *root = NULL;
    root = buildtree(root);
    vector<vector<int>> v = zigzagLevelOrder(root);   

    for (auto row : v) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    } 
    
    return 0;
}