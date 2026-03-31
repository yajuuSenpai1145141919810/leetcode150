// 21. Merge Two Sorted Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* current1=list1;
        ListNode* current2=list2;

        // 因為答案要 所以創建一個並且有指標指著他
        ListNode* dummy=new ListNode(0);
        ListNode* current3=dummy;

        // 不能寫current1->!=nullptr 不然會走不到最後一個
        while(current1!=nullptr&&current2!=nullptr){
            if(current1->val<current2->val){
                current3->next=current1;// 讓current3接過去
                current1=current1->next; 
            }else{
                current3->next=current2;
                current2=current2->next;
            }
            // 別忘了!!! current3也要走過去
            current3=current3->next;
        }
        //處理剩餘的
        if(current1!=nullptr){
            current3->next=current1;

        }else{
            current3->next=current2;
        }
        //!!!! 因為初始設ListNode(0) 所以要從下一個
        return dummy->next;

    }
};
