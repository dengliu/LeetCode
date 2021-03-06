/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Problem:    Remove Nth Node From End of List
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_19
 Notes:
 Given a linked list, remove the nth node from the end of list and return its head.
 For example,
 Given linked list: 1->2->3->4->5, and n = 2.
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.

 Solution: head---back------front------>NULL
                   |          |
                   ---> n <----
 */

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *front = head;
        ListNode *back = head;
        for (int i = 0; i < n; i++)
        {
            front = front->next;
        }
        if (!front) // delete head
        {
            head = head->next;
            delete back;
            return head;
        }
        while (front->next)
        {
            front = front->next;
            back = back->next;
        }
        ListNode *del = back->next;
        back->next = del->next;
        delete del;
        
        return head;
    }
};