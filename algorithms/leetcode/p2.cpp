/*
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

#include <iostream>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * **/
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            if((NULL == l1) && (NULL == l2))
                return NULL;

            ListNode* p1 = l1;
            ListNode* p2 = l2;

            ListNode* head = NULL;
            ListNode* p = head;

            int carry = 0;
            bool started = false;
            while((NULL != p1) || (NULL != p2) || 0 != carry) {
                bool eol = false;
                int dsum = carry;
                carry = 0;

                if((NULL != p1) && (NULL != p2)) {
                    dsum += p1->val + p2->val;
                } else if((NULL == p1) && (NULL != p2)) {
                    dsum += p2->val;
                } else if((NULL == p2) && (NULL != p1)) {
                    dsum += p1->val;
                }

                if(!started) {
                    head = new ListNode(dsum%10);
                    p = head;
                    started = true;
                } else {
                    ListNode* node = new ListNode(dsum%10);
                    p->next = node;
                    p = node;
                }

                if(dsum >= 10) {
                    carry = 1;
                }

                if(NULL != p1)
                    p1 = p1->next;
                if(NULL != p2)
                    p2 = p2->next;

            } // end of while
            p->next = NULL;

            return head;
        }
};

int main(int argc, char** argv) {
    //int arr1[] = {1, 8, 2};
    //int arr2[] = {1, 2, 3};
    int arr1[] = {5};
    int arr2[] = {5};
    ListNode* l1 = new ListNode(); 
    ListNode* p1 = l1;
    ListNode* l2 = new ListNode(); 
    ListNode* p2 = l2;

    int size_arr1 = sizeof(arr1)/sizeof(int);
    int size_arr2 = sizeof(arr2)/sizeof(int);

    for(int i=0; i<size_arr1; ++i) {
        p1->val = arr1[i];
        
        if((size_arr1 -1) == i) {
            p1->next = NULL;
        } else {
            ListNode *tmp1 = new ListNode();
            p1->next = tmp1;
            p1 = p1->next;
        }
    }

    for(int i=0; i<size_arr2; ++i) {
        p2->val = arr2[i];

        if((size_arr2 -1) == i) {
            p2->next = NULL;
        } else {
            ListNode *tmp2 = new ListNode();
            p2->next = tmp2;
            p2 = p2->next;
        }
    }

    p1 = l1;
    p2 = l2;
    while(p1 != NULL) {
        std::cout << p1->val << ", ";
        p1 = p1->next;
    }
    std::cout << std::endl;

    while(p2 != NULL) {
        std::cout << p2->val << ", ";
        p2 = p2->next;
    }
    std::cout << std::endl;

    Solution sol;
    ListNode* rp = sol.addTwoNumbers(l1, l2);

    while(NULL != rp) {
        std::cout << rp->val << ",";
        rp = rp->next;
    }
    std::cout << std::endl;

    return 0;
}
