
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // First pass over linked list to create the cloned nodes without connections
        Node *curr = head;
        unordered_map<Node*, Node*> copies;
        
        while(curr != NULL) {
            copies[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // Second pass over the original linked list, this time creating the connections
        curr = head;
        
        while(curr != NULL) {
            copies[curr]->next = copies[curr->next];
            copies[curr]->random = copies[curr->random];
            curr = curr->next;
        }
        
        return copies[head];
    }
};
