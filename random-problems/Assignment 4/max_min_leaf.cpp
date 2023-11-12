#include <bits/stdc++.h>

using namespace std;

int mn = INT_MAX;
int mx = INT_MIN;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }
    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }
    while (!q.empty())
    {
        Node *parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *nLeft, *nRight;
        if (l == -1)
        {
            nLeft = NULL;
        }
        else
        {
            nLeft = new Node(l);
        }
        if (r == -1)
        {
            nRight = NULL;
        }
        else
        {
            nRight = new Node(r);
        }

        parent->left = nLeft;
        parent->right = nRight;

        if (parent->left)
            q.push(parent->left);
        if (parent->right)
            q.push(parent->right);
    }
    return root;
};

void find_mx_mn_leaf(Node *root)
{
    if (root == NULL)
    {
        cout << "No Tree Found" << endl;
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        if (!f->left && !f->right)
        {
            if (f->val < mn)
            {
                mn = f->val;
            }
            if (f->val > mx)
            {
                mx = f->val;
            }
        }
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    cout << mx << " " << mn << endl;
}

int main()
{
    // Write your code here
    Node *root = input_tree();
    find_mx_mn_leaf(root);
    return 0;
}
