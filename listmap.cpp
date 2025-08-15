// 160. 相交链表
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa = headA, * pb = headB;
        while(true){
          if(pa == pb) return pa;
          pa = pa->next;
          pb = pb->next;
          if(pa == nullptr && pb != nullptr){
            pa = headB;
          }
          else if(pb == nullptr && pa != nullptr){
            pb = headA;
          }
          if(pb == nullptr && pa == nullptr) return nullptr;
        }
        return nullptr;
    }
};
// 206. 反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
          ListNode* nxt = cur->next;
          cur->next = pre;
          pre = cur;
          cur = nxt;
        }
        return pre;
    }
};
// 234. 回文链表
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
          slow = slow->next;
          fast = fast->next->next;
        }
        // reverse
        ListNode* cur = slow;
        ListNode* pre = nullptr;
        while(cur){
          ListNode* nxt = cur->next;
          cur->next = pre;
          pre = cur;
          cur = nxt;
        }
        // check
        ListNode* start1 = head;
        ListNode* start2 = pre;
        while(start2 && start1){
          if(start1->val != start2->val) return false;
          start1 = start1->next;
          start2 = start2->next;
        }
        return true;
    }
};
// 141. 环形链表
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head, * slow = head;
        while(fast && fast->next){
          fast = fast->next->next;
          slow = slow->next;
          if(fast == slow) return true;
        }
        return false;
    }
};
// 142. 环形链表Ⅱ
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        bool has_circle = false;
        while(fast && fast->next){
          fast = fast->next->next;
          slow = slow->next;
          if(fast == slow){
            has_circle = true;
            break;
          }
        }
        if(!has_circle) return nullptr;
        ListNode* start = head;
        while(start != slow){
          slow = slow->next;
          start = start->next;
        }
        return slow;
    }
};
// 21. 合并两个有序链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy = ListNode(0);
        ListNode* cur = &dummy;
        while(list1 && list2){
          if(list1->val < list2->val){
            cur->next = list1;
            list1 = list1->next;
          }
          else{
            cur->next = list2;
            list2 = list2->next;
          }
          cur = cur->next;
        }
        if(list1) cur->next = list1;
        else if(list2) cur->next = list2;
        return dummy.next;
    }
};
// 2. 两数相加
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int add = 0;
      ListNode dummy = ListNode(0);
      ListNode* cur = &dummy;
      while(l1 || l2 || add){
        int s = add;
        if(l1){
          s += l1->val;
          l1 = l1->next;
        }
        if(l2){
          s += l2->val;
          l2 = l2->next;
        }
        cur->next = new ListNode(s % 10);
        add = s / 10;
        cur = cur->next;
      }
      return dummy.next;
    }
};
// 19. 删除链表的倒数第N个节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0, head);
        ListNode* cur = head;
        while(n--){
          cur = cur->next;
        }
        ListNode *left = &dummy;
        while(left && cur){
          left = left->next;
          cur = cur->next;
        }
        left->next = left->next->next;
        return dummy.next;
    }
};
