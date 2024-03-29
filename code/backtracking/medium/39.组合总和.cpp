/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (72.67%)
 * Likes:    1506
 * Dislikes: 0
 * Total Accepted:    318.8K
 * Total Submissions: 438.6K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的正整数数组 candidates 和一个正整数 target ，找出 candidates 中所有可以使数字和为目标数 target
 * 的唯一组合。
 * 
 * candidates 中的数字可以无限制重复被选取。如果至少一个所选数字数量不同，则两种组合是唯一的。 
 * 
 * 对于给定的输入，保证和为 target 的唯一组合数少于 150 个。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: candidates = [2,3,6,7], target = 7
 * 输出: [[7],[2,2,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: candidates = [2,3,5], target = 8
 * 输出: [[2,2,2,2],[2,3,3],[3,5]]
 * 
 * 示例 3：
 * 
 * 
 * 输入: candidates = [2], target = 1
 * 输出: []
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入: candidates = [1], target = 1
 * 输出: [[1]]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入: candidates = [1], target = 2
 * 输出: [[1,1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * candidate 中的每个元素都是独一无二的。
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,target);
        return ans;
    }

    // 使用的数组，当前使用的位数，剩余大小
    void dfs(vector<int>&cs, int u, int target) {
        if(target==0) {
            ans.push_back(path);
            return;
        }

        if(u==cs.size()) return;
        // 这里或许不必优化，不优化则不用排序
        // TODO 更合适的优化应该是dfs返回false，之后的元素均不进行递归计算？
        if(cs[u]>target) return;

        // 当前数字可以使用的次数
        for(int i=0;cs[u]*i<=target;++i) {
            dfs(cs,u+1,target-cs[u]*i);
            path.push_back(cs[u]);
        }

        for(int i=0;cs[u]*i<=target;++i) {
            path.pop_back();
        }
    }
};
// @lc code=end

