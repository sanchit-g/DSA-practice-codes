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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1, s2, s3;

        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }

        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }

        int carry = 0;

        while (!s1.empty() and !s2.empty()) {
            int sum = carry + s1.top() + s2.top();
            s1.pop();
            s2.pop();
            s3.push(sum % 10);
            carry = sum / 10;
        }

        while (!s1.empty()) {
            int sum = carry + s1.top();
            s1.pop();
            s3.push(sum % 10);
            carry = sum / 10;
        }

        while (!s2.empty()) {
            int sum = carry + s2.top();
            s2.pop();
            s3.push(sum % 10);
            carry = sum / 10;
        }

        if (carry > 0)
            s3.push(carry);

        ListNode* newHead = new ListNode(0);
        ListNode* curr = newHead;

        while (!s3.empty()) {
            curr -> next = new ListNode(s3.top());
            s3.pop();
            curr = curr -> next;
        }

        return newHead -> next;
    }
};