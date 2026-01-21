#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;
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

    void inorder_traversal(TreeNode *&root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder_traversal(root->left);
        cout << root->val << " ";
        inorder_traversal(root->right);
    }
    TreeNode *findMin(TreeNode *root)
    {
        while (root->left)
        {
            root = root->left;
        }
        return root;
    }
    void delete_node(int val, TreeNode *&root)
    {
        if (!root)
            return;

        if (val < root->val)
            delete_node(val, root->left);
        else if (val > root->val)
            delete_node(val, root->right);
        else
        {
            // case 1 -> leaf node
            if (!root->left and !root->right)
            {
                delete root;
                root = nullptr;
                return;
            }

            // case 2 -> one child
            if (!root->left or !root->right)
            {
                TreeNode *old = root;
                TreeNode *temp = root->left ? root->left : root->right;
                root = temp;
                delete old;
                return;
            }

            // case 3 -> two child
            auto succ = findMin(root->right);
            root->val = succ->val;
            delete_node(succ->val, root->right);
        }

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = get_balance(root);

        // LL rotation
        if (balance > 1 and get_balance(root->left) >= 0)
        {
            rotate_right(root);
            return;
        }

        // LR rotation
        if (balance > 1 and get_balance(root->left) < 0)
        {
            rotate_left(root->left);
            rotate_right(root);
            return;
        }

        // RR rotation
        if (balance < -1 and get_balance(root->right) <= 0)
        {
            rotate_left(root);
            return;
        }

        // RL rotation
        if (balance < -1 and get_balance(root->right) > 0)
        {
            rotate_right(root->right);
            rotate_left(root);
            return;
        }
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
    void delete_node(int val)
    {
        delete_node(val, root);
    }
};

int main()
{
    Tree t;
    for (int i = 1; i < 11; i++)
    {
        t.insert(i);
    }
    t.inorder_traversal();
    cout << endl;
    t.delete_node(1);
    t.delete_node(5);
    t.inorder_traversal();
    return 0;
}