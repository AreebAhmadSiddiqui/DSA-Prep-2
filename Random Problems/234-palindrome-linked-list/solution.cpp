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
private:
    ListNode* getMid(ListNode* slow,ListNode* fast){
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        while(curr){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* mid=getMid(head,head);
        
        ListNode* revHead=reverse(mid);
        
        ListNode* start1=head,*start2=revHead;
        
        while(start1 && start2){
            if(start1->val!=start2->val) return false;
            
            start1=start1->next;
            start2=start2->next;
        }
        return true;
        
    }
};