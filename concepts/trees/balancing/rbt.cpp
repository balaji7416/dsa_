#include <bits/stdc++.h>
using namespace std;

enum color
{
    red,
    black
};

struct TreeNode
{
    int val;
    color color;
    TreeNode *left, *right, *parent;
    TreeNode(int val) : val(val), color(red), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBT
{
private:
    TreeNode *root;

    void leftRotate(TreeNode *&x)
    {
        TreeNode *y = x->right;
        x->right = y->left;

        if (y->left)
            y->left->parent = x;

        y->parent = x->parent;
        if (!x->parent)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rightRotate(TreeNode *&x)
    {
        TreeNode *y = x->left;
        x->left = y->right;
        if (y->right)
            y->right->parent = x;

        y->parent = x->parent;
        if (!x->parent)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;

        y->right = x;
        x->parent = y;
    }

    void fixBalance(TreeNode *&x)
    {
        while (x != root and x->parent and x->parent->color == red)
        {
            TreeNode *parent = x->parent;
            TreeNode *grandParent = parent->parent;

            if (!grandParent)
                break;
            if (parent == grandParent->left)
            {
                TreeNode *uncle = grandParent->right;

                if (uncle and uncle->color == red)
                {
                    // case 1: uncle red
                    parent->color = black;
                    uncle->color = black;
                    grandParent->color = red;
                    x = grandParent;
                }
                else
                { // case 2: triangle
                    if (x == parent->right)
                    {
                        x = parent;
                        leftRotate(x);
                    }

                    // case 3: line
                    parent->color = black;
                    grandParent->color = red;
                    rightRotate(grandParent);
                }
            }
            else
            {
                // mirror cases
                TreeNode *uncle = grandParent->left;
                if (uncle and uncle->color == red)
                {
                    parent->color = black;
                    uncle->color = black;
                    grandParent->color = red;
                    x = grandParent;
                }
                else
                {
                    if (x == parent->left)
                    {
                        x = parent;
                        rightRotate(x);
                    }
                    parent->color = black;
                    grandParent->color = red;
                    leftRotate(grandParent);
                }
            }
        }
        root->color = black;
    }
    bool insert(TreeNode *node, TreeNode *&root)
    {
        if (root == nullptr)
        {
            root = node;
            return true;
        }

        if (node->val < root->val)
        {
            bool inserted = insert(node, root->left);
            if (inserted)
                root->left->parent = root;
            return inserted;
        }

        else if (node->val > root->val)
        {
            bool inserted = insert(node, root->right);
            if (inserted)
                root->right->parent = root;
            return inserted;
        }

        else
        {
            delete node;
            return false;
        }
    }

    void inorder_traversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder_traversal(root->left);
        cout << root->val << " ";
        inorder_traversal(root->right);
    }

    void freeTree(TreeNode *&root)
    {
        if (root == nullptr)
        {
            return;
        }
        freeTree(root->left);
        freeTree(root->right);
        delete root;
        root = nullptr;
    }

public:
    RBT() : root(nullptr) {}

    void insert(int val)
    {
        TreeNode *node = new TreeNode(val);
        if (insert(node, root))
            fixBalance(node);
    }

    void inorder_traversal()
    {
        inorder_traversal(root);
    }

    ~RBT()
    {
        freeTree(root);
    }
};

int main()
{
    RBT rbt;
    for (int i = 0; i < 10; i++)
    {
        rbt.insert(i + 1);
    }
    rbt.inorder_traversal();
    cout << endl;
    return 0;
}