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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;
        ListNode* rh = NULL;
        ListNode* r = rh;
        while(carry || p1 || p2) {
            int sum = 0;
            int dig;
            if (carry) {
                sum += carry;
            }
            if (p1) {
                sum += p1->val;
                p1 = p1->next;
            }
            if (p2) {
                sum += p2->val;
                p2 = p2->next;
            }
            if (sum >= 10) {
                dig = sum - 10;
                carry = 1;
            } else {
                dig = sum;
                carry = 0;
            }
            if (r) {
                r->next = new ListNode(dig);
                r = r->next;
            } else {
                rh = new ListNode(dig);
                r = rh;
            }
        }
        return rh;
    }  
};
