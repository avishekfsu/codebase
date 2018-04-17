/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include <unordered_map>
bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    unordered_map<struct Node*,int> listmap;
    
    while (head!=NULL)
    {
        if (listmap[head] != 0)
            return true;
        listmap[head]++;
        head=head->next;
        
    }
    return false;
}
