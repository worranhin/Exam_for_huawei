//使用迭代法遍历
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    //结构体的构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode *> qe;
        TreeNode *leftnode;
        TreeNode *rightnode;
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL)
            return true;
        else if (root->left == NULL && root->right != NULL)
            return false;
        else if (root->left != NULL && root->right == NULL)
            return false;
        else
        {
            qe.push(root->left);
            qe.push(root->right);
        }

        while (!qe.empty())
        {
            //统一后序迭代法,先压进去再比较，一次必须把左右一起压进去了，因为这个节点只有这个点出来
            leftnode = qe.front();
            qe.pop();
            rightnode = qe.front();
            qe.pop();

            //判断了不全为空
            if (leftnode == NULL && rightnode == NULL)
            {
                continue;
            }
            //如果一个为空说明另一个一定为空
            if (leftnode == NULL || rightnode == NULL || (leftnode->val != rightnode->val))
            {
                return false;
            }
            qe.push(leftnode->left);
            qe.push(rightnode->right);
            qe.push(leftnode->right);
            qe.push(rightnode->left);
        }
        return true;
    }
};