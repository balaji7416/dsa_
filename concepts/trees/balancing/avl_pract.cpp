#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    int height;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), height(1), left(nullptr), right(nullptr) {}
};

class Tree
{
private:
    TreeNode *root;

    int height(TreeNode *root)
    {
        return root ? root->height : 0;
    }
    int get_balance(TreeNode *root)
    {
        return root ? height(root->left) - height(root->right) : 0;
    }
    void rotate_right(TreeNode *&root)
    {
        TreeNode *left = root->left;
        TreeNode *left_r = left->right;
        left->right = root;
        root->left = left_r;

        root->height = 1 + max(height(root->left), height(root->right));
        left->height = 1 + max(height(left->left), height(left->right));

        root = left;
    }
    void rotate_left(TreeNode *&root)
    {
        TreeNode *right = root->right;
        TreeNode *right_l = right->left;
        right->left = root;
        root->right = right_l;

        root->height = 1 + max(height(root->left), height(root->right));
        right->height = 1 + max(height(right->left), height(right->right));

        root = right;
    }

    void insert(int val, TreeNode *&root)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            return;
        }
        if (val < root->val)
            insert(val, root->left);
        else if (val > root->val)
            insert(val, root->right);
        else
            return;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = get_balance(root);

        // LL rotation
        if (balance > 1 and val < root->left->val)
        {
            rotate_right(root);
            return;
        }

        // LR rotation
        if (balance > 1 and val > root->left->val)
        {
            rotate_left(root->left);
            rotate_right(root);
            return;
        }

        // RR rotation
        if (balance < -1 and val > root->right->val)
        {
            rotate_left(root);
            return;
        }

        // RL rotation
        if (balance < -1 and val < root->right->val)
        {
            rotate_right(root->right);
            rotate_left(root);
            return;
        }
    }
    void inorder_traversal(TreeNode *root)
    {
        if (root == nullptr)
            return;

        inorder_traversal(root->left);
        cout << root->val << " ";
        inorder_traversal(root->right);
    }
    void print(TreeNode *root, string indent = "", bool last = true)
    {
        if (!root)
            return;
        cout << indent;
        if (last)
        {
            cout << "R----";
            indent += "     ";
        }
        else
        {
            cout << "L----";
            indent += "|    ";
        }
        cout << root->val << "(h=" << root->height << ")\n";
        print(root->left, indent, false);
        print(root->right, indent, true);
    }

public:
    Tree() : root(nullptr) {}
    void insert(int val)
    {
        insert(val, root);
    }
    void inorder_traversal()
    {
        inorder_traversal(root);
    }
    void print()
    {
        print(root);
    }
};

int main()
{
    Tree t;
    for (int i = 0; i < 10; i++)
    {
        t.insert(i + 1);
    }
    t.inorder_traversal();
    cout << endl;
    t.print();
    return 0;
}