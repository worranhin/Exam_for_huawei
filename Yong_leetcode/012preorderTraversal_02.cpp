//一个迭代遍历的统一模板，像递归一样方便改
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
                st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。
                               //(下次看到栈顶为空元素就开始弹出处理节点数据，作为每次看到数据且没有左右节点了之后就会将其处理)

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
    //相比于中序，只需要改压入栈中的顺序
    vector<int> preorderTraversal(TreeNode *root)
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
                st.pop();
                if (node->right)
                    st.push(node->right); // 右
                if (node->left)
                    st.push(node->left); // 左
                st.push(node);           // 中
                st.push(NULL);           //填null证明这是等会要先出的，压在null下面的先出,此处的null很关键
                                         //帮助中序的数据先进行了处理，没有null处理顺序就不对了。
                                         // null实现了在没有子节点时优先出最底层了，有子节点优先出中
            }
            else
            {
                st.pop(); // pop掉null
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
    //后序遍历只需要
    vector<int> postorderTraversal(TreeNode *root)
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
                st.pop();
                st.push(node); // 中
                st.push(NULL);
                if (node->right)
                    st.push(node->right); // 右
                if (node->left)
                    st.push(node->left); // 左
            }
            else
            {
                st.pop(); //把空pop掉
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};