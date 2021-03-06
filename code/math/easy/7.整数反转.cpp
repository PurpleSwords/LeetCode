/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (34.67%)
 * Likes:    2198
 * Dislikes: 0
 * Total Accepted:    469.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        // 仅仅使用int进行处理
        int result = 0;
        while(x){
            // 对溢出的式子进行变形，使结果不再溢出
            if(result>0&&result>(INT_MAX-x%10)/10)  return 0;
            if(result<0&&result<(INT_MIN-x%10)/10)  return 0;
            result = 10*result+x%10;
            x/=10;
        }
        //if(result>INT_MAX||result<INT_MIN) result=0;
        return result;
    }
};
// @lc code=end

