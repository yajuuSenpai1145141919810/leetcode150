// 2. Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// 1. 「一掛」：先掛好鉤子 (Dummy Node)
// 2. 「二加」：把值吸過來，算完塞進去
// 3. 「三走」：大家一起往前踏一步
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 跟 21. Merge Two Sorted Lists 比那題目是原本就有node 但這邊沒有! 
        ListNode* current1=l1;
        ListNode* current2=l2;

        ListNode* result =new ListNode(0);
        ListNode* current3=result;

        int carry=0;

        // 如果還有進位就繼續跑
        while(current1!=nullptr||current2!=nullptr||carry!=0){
            int val1=0;
            if(current1!=nullptr){
                val1=current1->val;
            }
            int val2=0;
            if(current2!=nullptr){
                val2=current2->val;
            }
            int sum=val1+val2+carry;
            carry=(sum/10);
            int digit=sum%=10;

            // 重點  每一輪加完就建立一個
            current3->next=new ListNode(digit);


            // 各往前走一步
            current3=current3->next;
            
            // 因為while用|| 所以要預防!!!! 不然絕對會出錯
            if(current2!=nullptr) current2=current2->next;
            if(current1!=nullptr) current1=current1->next;
        }
        return result->next;
    }
};
