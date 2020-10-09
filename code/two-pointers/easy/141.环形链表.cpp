/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 *
 * https://leetcode-cn.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (49.34%)
 * Likes:    796
 * Dislikes: 0
 * Total Accepted:    254.2K
 * Total Submissions: 509.5K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * 给定一个链表，判断链表中是否有环。
 * 
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos
 * 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos
 * 不作为参数进行传递，仅仅是为了标识链表的实际情况。
 * 
 * 如果链表中存在环，则返回 true 。 否则，返回 false 。
 * 
 * 
 * 
 * 进阶：
 * 
 * 你能用 O(1)（即，常量）内存解决此问题吗？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：head = [1,2], pos = 0
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：head = [1], pos = -1
 * 输出：false
 * 解释：链表中没有环。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [0, 10^4]
 * -10^5 <= Node.val <= 10^5
 * pos 为 -1 或者链表中的一个 有效索引 。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /// 利用快慢指针，快指针每次+2，慢指针每次+1，
        /// 若快指针追上慢指针说明有环
        /// 若快指针先到NULL说明无环

        // 元素个数为0/1时无环
        if(!head||!head->next)  return false;

        // 初始化快慢指针的位置
        for(ListNode *slow=head,*fast=head->next;slow!=fast;slow=slow->next,fast=fast->next->next){
            // fast当前或下一个位置为nullptr说明链表有尾，判断两个是因为fast一次前进2
            if(!fast||!fast->next)  return false;
        }
        // 两指针相等说明有环
        return true;
        // 注意for循环的执行顺序，先进行判断，再执行循环体，最后执行累加！
        // 因为先进行判断，所以slow和fast指针不能同时指向head
        // 因为fast要指向head->next，所以要先判断是否存在
    }
};
// @lc code=end

