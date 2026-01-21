#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Tree
{
private:
    TreeNode *root;

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
    }
    void inorder_tranversal(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder_tranversal(root->left);
        cout << root->val << " ";
        inorder_tranversal(root->right);
    }
    void preorder_traversal(TreeNode *root)
    {
        if (root == nullptr)
            return;
        cout << root->val << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
    void postorder_traversal(TreeNode *root)
    {
        if (root == nullptr)
            return;
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->val << " ";
    }
    int height(TreeNode *root)
    {
        // in terms of number of edges
        if (root == nullptr)
            return -1;

        int left = height(root->left);
        int right = height(root->right);
        return 1 + max(left, right);
    }
    int nodeDepth(TreeNode *root, int target, int currDepth = 0)
    {
        if (root == nullptr)
            return -1; // target not found
        if (root->val == target)
            return currDepth;

        int left = nodeDepth(root->left, target, currDepth + 1);
        int right = nodeDepth(root->right, target, currDepth + 1);

        if (left != -1)
            return left;
        if (right != -1)
            return right;
        else
            return -1;
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr and q == nullptr)
            return true;
        if (p == nullptr or q == nullptr)
            return false;
        if (p->val != q->val)
            return false;

        bool isSameLeft = isSameTree(p->left, q->left);
        bool isSameRight = isSameTree(p->right, q->right);

        return isSameLeft and isSameRight;
    }
    TreeNode *invertTree(TreeNode *&root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        root->left = right;
        root->right = left;
        return root;
    }
    int diameterHelper(TreeNode *root, int &diameter)
    {
        // logic is stander height calculation with maintaining a diameter variable to track max diameter across the tree
        if (root == nullptr)
            return -1; // height of a empty tree

        int leftHeight = diameterHelper(root->left, diameter);
        int rightHeight = diameterHelper(root->right, diameter);

        int candidate = leftHeight + rightHeight + 2;
        diameter = max(diameter, candidate);

        return 1 + max(leftHeight, rightHeight);
    }
    void getAllRootToLeafPaths(TreeNode *root, vector<int> &path, vector<vector<int>> &paths)
    {
        if (root == nullptr)
        {
            return;
        }
        path.push_back(root->val);
        if (root->left == nullptr and root->right == nullptr)
        {
            paths.push_back(path);
        }

        getAllRootToLeafPaths(root->left, path, paths);
        getAllRootToLeafPaths(root->right, path, paths);

        path.pop_back();
    }
    void levelOrderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *u = q.front();
            q.pop();
            cout << u->val << " ";
            if (u->left)
                q.push(u->left);
            if (u->right)
                q.push(u->right);
        }
    }
    vector<vector<int>> levelOrderByLevels(TreeNode *root)
    {
        if (root == nullptr)
            return {{}};
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> levels;
        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> currLevel;
            for (int i = 0; i < levelSize; i++)
            {
                auto curr = q.front();
                q.pop();
                currLevel.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            levels.push_back(currLevel);
        }
        return levels;
    }
    bool isValidBST(TreeNode *root, long long minVal, long long maxVal)
    {
        if (root == nullptr)
            return true;
        if (root->val <= minVal or root->val >= maxVal)
            return false;
        bool isBSTLeft = isValidBST(root->left, minVal, root->val);
        bool isBSTRight = isValidBST(root->right, root->val, maxVal);
        return isBSTLeft && isBSTRight;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, int p, int q)
    {
        if (root == nullptr or root->val == p or root->val == q)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left and right)
        {
            return root;
        }
        return left ? left : right;
    }
    TreeNode *findMin(TreeNode *root)
    {
        while (root->left)
        {
            root = root->left;
        }
        return root;
    }
    void deleteNode(int val, TreeNode *&root)
    {
        if (root == nullptr)
        {
            return;
        }
        if (val < root->val)
            deleteNode(val, root->left);
        else if (val > root->val)
            deleteNode(val, root->right);
        else
        {
            // case 1 -> leaf node
            if (root->left == nullptr and root->right == nullptr)
            {
                delete root;
                root = nullptr;
                return;
            }

            // case 2 -> node with one child
            if (root->left == nullptr or root->right == nullptr)
            {
                TreeNode *old = root;
                TreeNode *temp = root->left ? root->left : root->right;
                root = temp;
                delete old;
                return;
            }

            // case 3 -> node with both childs
            else
            {
                TreeNode *succ = findMin(root->right);
                root->val = succ->val;
                deleteNode(succ->val, root->right);
            }
        }
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
    Tree() : root(nullptr) {}

    void insert(int val)
    {
        insert(val, root);
    }
    void inorder_tranversal()
    {
        inorder_tranversal(root);
    }
    void preorder_traversal()
    {
        preorder_traversal(root);
    }
    void postorder_traversal()
    {
        postorder_traversal(root);
    }
    int height()
    {
        return height(root);
    }
    int nodeDepth(int target)
    {
        return nodeDepth(root, target, 0);
    }
    bool isSameTree(Tree &other)
    {
        return isSameTree(this->root, other.root);
    }
    void invertTree()
    {
        root = invertTree(root);
    }
    int diameter()
    {
        int maxDiameter = 0;
        diameterHelper(root, maxDiameter);
        return maxDiameter;
    }
    vector<vector<int>> getAllRootToLeafPaths()
    {
        vector<vector<int>> paths;
        vector<int> path;
        getAllRootToLeafPaths(root, path, paths);
        return paths;
    }
    void levelOrderTraversal()
    {
        levelOrderTraversal(root);
    }
    vector<vector<int>> levelOrderByLevels()
    {
        return levelOrderByLevels(root);
    }
    bool isValidBST()
    {
        return isValidBST(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
    int lowestCommonAncestor(int p, int q)
    {
        TreeNode *lca = lowestCommonAncestor(root, p, q);
        if (!lca)
            throw runtime_error("LCA not found");
        return lca->val;
    }
    void deleteNode(int val)
    {
        deleteNode(val, root);
    }
    ~Tree()
    {
        freeTree(root);
    }
};

int main()
{
    Tree t;
    Tree s;
    for (int i = 1; i < 11; i++)
    {
        t.insert(i);
        s.insert(i);
    }

    t.inorder_tranversal();
    cout << endl;

    t.deleteNode(1);
    t.deleteNode(4);

    t.inorder_tranversal();
    // t.levelOrderTraversal();
    // vector<vector<int>> levels = t.levelOrderByLevels();
    // cout << endl;
    // for (auto level : levels)
    // {
    //     cout << "[ ";
    //     for (auto val : level)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << "]";
    // }
    // cout << endl;
    // if (t.isValidBST())
    //     cout << "BST" << endl;
    // else
    //     cout << "Not a BST" << endl;
    // cout << "lowest common ancestor of 2,4: " << t.lowestCommonAncestor(2, 4) << endl;
    // t.inorder_tranversal();
    // cout << endl;
    // t.postorder_traversal();
    // cout << endl;
    // t.preorder_traversal();
    // cout << endl;
    // cout << "height of tree: " << t.height() << endl;
    // t.isSameTree(s) ? cout << "same" << endl : cout << "not same" << endl;
    // s.insert(30);
    // s.inorder_tranversal();
    // cout << endl;
    // t.isSameTree(s) ? cout << "same" << endl : cout << "not same" << endl;
    // t.invertTree();
    // t.inorder_tranversal();
    // cout << endl;
    // cout << "depth of node 10: " << t.nodeDepth(10) << endl;
    // cout << "diameter of tree: " << t.diameter() << endl;
    // vector<vector<int>> rootToLeafPaths = t.getAllRootToLeafPaths();
    // for (auto path : rootToLeafPaths)
    // {
    //     cout << "[ ";
    //     for (auto val : path)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << "], ";
    // }
    // cout << endl;
    return 0;
}