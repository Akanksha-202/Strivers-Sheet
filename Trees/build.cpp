#include <iostream>
#include <queue>
#include <stack>

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

void revLevelOrderTraversal(node *root)
{
    queue<node *> q;
    stack<node *> s;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp == NULL)
        {
            if (!q.empty()) // to check if more elements are still there
            {
                q.push(NULL);
            }
        }

        else
        {
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

    s.pop(); // to remove Null at the top

    while (!s.empty())
    {
        node *temp = s.top();
        if (temp == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << temp->data << " ";
            
        }
        s.pop();
    }
}

void inordertraversal(node* root){
    if(root==NULL){
        return;
    }

    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}

void preordertraversal(node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}

void postordertraversal(node* root){
    if(root==NULL){
        return;
    }

    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
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
    levelOrderTraversal(root);
    cout << endl;
    cout << "Reverse Level Order Traversal" << endl;
    revLevelOrderTraversal(root);
    cout<<endl;
    cout<<"Inoder Travesal"<<endl;
    inordertraversal(root);
    cout<<endl;
    cout<<"Preoder Travesal"<<endl;
    preordertraversal(root);
    cout<<endl;
    cout<<"Postoder Travesal"<<endl;
    postordertraversal(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1