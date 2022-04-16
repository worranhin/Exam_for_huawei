//使用递归比较
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    //比较是一个层层返回相与，一旦有一个不满足就return false
    bool compare(TreeNode *leftnode, TreeNode *rightnode)
    {
        //判断节点为空时的情况或者值不等
        if (leftnode == NULL && rightnode != NULL)
            return false;
        else if (leftnode != NULL && rightnode == NULL)
            return false;
        else if (leftnode == NULL && rightnode == NULL)
            return true;
        else if (leftnode->val != rightnode->val)
            return false;
        else //说明比较通过，需要递归比较了
        {
            bool inside = compare(leftnode->right, rightnode->left);
            bool outside = compare(leftnode->left, rightnode->right);
            bool issame = inside && outside;
            return issame;
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return compare(root->left, root->right);
    }
};