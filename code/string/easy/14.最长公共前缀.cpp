/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (39.14%)
 * Likes:    1439
 * Dislikes: 0
 * Total Accepted:    439.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 0 
 * strs[i] 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 简单的模拟
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.empty())    return res;

        for(int i=0,l=strs[0].size();i<l;++i){
            char c=strs[0][i];
            for(auto& str:strs){
                if(str.size()<=i||str[i]!=c)
                    return res;
            }
            res+=c;
        }
        return res;
    }
};
// @lc code=end

