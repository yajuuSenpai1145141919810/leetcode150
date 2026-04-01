// 19. Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current=head;

        int count=0;
        // 已經有current != nullptr進去後寫current=current->next;是安全的
        while(current!=nullptr){
            current=current->next;
            count++;
        }

        int del=count-n;

        ListNode* current1=head;
        if(n==count){
            current1=head->next;
            delete head;
            head=current1;
            
            return head;// 做完下班拉
        }  
        for(int i=0;i<del-1;i++){
            current1=current1->next;
        }
        current1->next=current1->next->next;
        return head;
    }
};
