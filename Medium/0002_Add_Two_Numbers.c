#include <stdio.h>
#include<stdlib.h>
// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function for adding two linked lists representing non-negative integers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));  // create a dummy node
    dummy->val = 0;  // initialize dummy node's value to 0
    dummy->next = NULL;
    struct ListNode* curr = dummy;  // set a pointer to the dummy node
    
    int carry = 0;  // initialize the carry variable to 0
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;  // set the sum variable to the carry value
        
        if (l1 != NULL) {
            sum += l1->val;  // add the value of l1's current node to the sum
            l1 = l1->next;  // move l1's pointer to the next node
        }
        
        if (l2 != NULL) {
            sum += l2->val;  // add the value of l2's current node to the sum
            l2 = l2->next;  // move l2's pointer to the next node
        }
        
        carry = sum / 10;  // calculate the new carry value
        sum = sum % 10;  // calculate the new sum value
        
        struct ListNode* newNode = malloc(sizeof(struct ListNode));  // create a new node for the sum value
        newNode->val = sum;  // set the node's value to the sum value
        newNode->next = NULL;
        
        curr->next = newNode;  // link the new node to the previous node
        curr = newNode;  // move the pointer to the new node
    }
    
    struct ListNode* result = dummy->next;  // set the result node to the first real node in the list
    free(dummy);  // free the dummy node
    
    return result;  // return the result node
}


// Test function to print a linked list
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function for testing the solution
int main() {
    // Create linked list inputs
    struct ListNode* l1 = malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;
    
    struct ListNode* l2 = malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;
    
    // Call the function to add the linked lists
    struct ListNode* result = addTwoNumbers(l1, l2);
    
    // Print the result linked list
    printf("Result: ");
    printList(result);
    
    // Free memory used by linked lists
    free(l1);
    free(l2);
    while (result != NULL) {
        struct ListNode* temp = result->next;
        free(result);
        result = temp;
    }
    
    return 0;
}
