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
    void reorderList(ListNode* head) {

        if (!head)
            return;

        // find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast -> next and fast -> next -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        // reverse the second half of the list
        ListNode* prev = NULL;
        ListNode* curr = slow -> next;
        ListNode* temp;
        while (curr) {
            temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        // seperate the two lists
        slow -> next = NULL;

        // merge the two lists
        ListNode* head1 = head;
        ListNode* head2 = prev;
        ListNode* nxt1;
        ListNode* nxt2;
        while (head1 and head2) {
            nxt1 = head1 -> next;
            nxt2 = head2 -> next;

            head1 -> next = head2;
            head1 = nxt1;

            head2 -> next = head1;
            head2 = nxt2;
        }
    }
};