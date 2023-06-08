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

int height(node* root){

    if(root==NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left,right)+1;

}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    cout << endl;

    cout<<"Height of tree is: "<<height(root);
    
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1