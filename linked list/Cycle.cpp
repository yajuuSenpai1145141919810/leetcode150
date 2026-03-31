// 141. Linked List Cycle

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
        // 一定要寫head==nullptr 不然會錯喔!
        if(head==nullptr||head->next==nullptr) return false;

        // 龜兔賽跑
        ListNode* fast=head;
        ListNode* slow=head;

        // 只要比快的就好 快的不會撞 慢的就不會撞
        while(fast!=nullptr&&fast->next!=nullptr){

            //讓快的多走一步
            fast=fast->next->next;
            slow=slow->next;
            // 注意不能寫else 不然第一圈就return false了
            if(fast==slow){
                return true;
            }
            
        }
        // 都追不到
        return false;      
    }
};
