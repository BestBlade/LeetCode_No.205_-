/* ------------------------------------------------------------------|
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true
示例 2:

输入: s = "foo", t = "bar"
输出: false
示例 3:

输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/isomorphic-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	数组哈希表法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了97.07%的用户
*	内存消耗：7.1 MB, 在所有 C++ 提交中击败了75.78%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//简单映射用数组，更快
bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }
    char s2t[256] = { 0 };
    char t2s[256] = { 0 };
    for (int i = 0; i < s.size(); i++) {
        if (!s2t[s[i]]) {
            s2t[s[i]] = t[i];
        }
        else {
            if (s2t[s[i]] != t[i]) {
                return false;
            }
        }
        if (!t2s[t[i]]) {
            t2s[t[i]] = s[i];
        }
        else {
            if (t2s[t[i]] != s[i]) {
                return false;
            }
        }
    }
    return true;
}

