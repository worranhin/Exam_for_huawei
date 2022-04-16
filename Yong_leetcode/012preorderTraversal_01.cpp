//递归实现前中后序遍历完全二叉树
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
    //前序遍历
    void preorderTraversal(TreeNode *cur, vector<int> &res)
    {
        if (cur = NULL)
            return;
        res.push_back(cur->val);
        preorderTraversal(cur->left, res);
        preorderTraversal(cur->right, res);
    }
    //中序遍历
    void inorderTraversal(TreeNode *cur, vector<int> &res)
    {
        if (cur == NULL)
            return;
        inorderTraversal(cur->left, res);
        res.push_back(cur->val);
        inorderTraversal(cur->right, res);
    }
    //后序遍历，本质就是将前序的顺序反了 从（中左右）->（中右左）再逆序一下，变为（左右中）
    void postorderTraversal(TreeNode *cur, vector<int> &res)
    {
        if (cur == NULL)
            return;
        postorderTraversal(cur->left, res);
        postorderTraversal(cur->right, res);
        res.push_back(cur->val);
    }
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        if (root != NULL)
            st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node != NULL)
            {
                st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right)
                    st.push(node->right); // 添加右节点（空节点不入栈）

                st.push(node); // 添加中节点
                st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。(下次看到栈顶为空元素就开始弹出处理节点数据)

                if (node->left)
                    st.push(node->left); // 添加左节点（空节点不入栈）
            }
            else
            {                    // 只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();        // 将空节点弹出
                node = st.top(); // 重新取出栈中元素
                st.pop();
                result.push_back(node->val); // 加入到结果集
            }
        }
        return result;
    }
};