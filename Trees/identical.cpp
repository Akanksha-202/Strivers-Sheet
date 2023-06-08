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

bool identical(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL && root2 != NULL){
        return false;
    }
    if(root1 != NULL && root2 == NULL){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    }

    int left = identical(root1->left,root2->left);
    int right = identical(root1->right,root2->right);

    if(left && right){
        return true;
    }
    else{
        return false;
    }

}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    cout << endl;

    node* root2 = NULL;
    root2 = buildtree(root2);
    levelOrderTraversal(root2);
    cout<<endl;

    cout<<"Are the trees idetical? "<<identical(root, root2);
  
   
    
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1