//迭代前中后序遍历二叉树
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> ts;
        TreeNode *node = new TreeNode(0);
        if (root == NULL)
            return res;
        //先压是为了方便下面第一个先出
        ts.push(root);
        while (!ts.empty())
        {
            node = ts.top(); //中节点先出处理
            ts.pop();
            res.push_back(node->val);
            if (node->right != NULL)
                ts.push(node->right);
            if (node->left != NULL)
                ts.push(node->left);
        }
        return res;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> t_stack;
        vector<int> res;
        TreeNode *cur;
        //记录当前处理的节点，非空就一直压左，到空说明到低了，一次返回两个（左和中）
        //再把右压进去，进行重复进行压左，如此循环
        cur = root;
        while (cur != NULL || !t_stack.empty())
        {
            if (cur != NULL)
            {
                t_stack.push(cur);
                cur = cur->left;
            }
            else //进一次else定会再进一次
            {
                cur = t_stack.top();
                t_stack.pop();
                res.push_back(cur->val);
                //一次定会出两个，一个是左一个是中(特殊左节点缺失会导致只出右边了)
                cur = cur->right;
            }
        }
        return res;
    }
    //后序遍历，本质就是将前序的顺序反了 从（中左右）->（中右左）再逆序一下，变为（左右中）
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if (root == NULL)
            return result;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left)
                st.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
            if (node->right)
                st.push(node->right); // 空节点不入栈
        }
        reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
        return result;
    }
};
