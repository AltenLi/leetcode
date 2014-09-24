# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

## Use Merge Sort

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def sortList(self, head):
        if not head:
            return None
        if not head.next:
            return head
        # dummy=ListNode(0)
        # dummy.next=head
        fast=head
        slow=head
        while fast.next and fast.next.next:
            slow=slow.next
            fast=fast.next.next
        fast=slow.next
        slow.next=None
        a = self.sortList(head)
        b = self.sortList(fast)
        return self.MergeList(a,b)

    def MergeList(self, head1, head2):
        dummy=ListNode(0)
        p=dummy
        while head1 and head2:
            if head1.val<head2.val:
                p.next=head1
                head1=head1.next
                p=p.next
                p.next=None
            else:
                p.next=head2
                head2=head2.next
                p=p.next
                p.next=None
        if head1:
            p.next=head1
        if head2:
            p.next=head2
        return dummy.next
            
