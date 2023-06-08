#include <iostream>
#include <queue>

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

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        { // Level complete
            cout << endl;
            if (!q.empty()) // to check if more elements are still there
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
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

pair<int,int> diameter (node* root){

    if(root==NULL){
        pair<int,int>p = make_pair(0,0);
        return p;
    }

    pair<int,int>left = diameter(root->left);
    pair<int,int>right = diameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second+1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second)+1;

    return ans;

}


int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    cout << endl;
    cout<<"Diameter is: "<<diameter(root).first;
    
    return 0;
}

