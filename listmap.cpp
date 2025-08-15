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
// 24. 两两交换链表中的节点
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      ListNode dummy = ListNode(0);
      ListNode* p0 = &dummy;
      ListNode* cur = head;
      if(cur == nullptr) return nullptr;
      if(cur->next == nullptr) return head;
      while(cur && cur->next){
        ListNode* nxt = cur->next;
        p0->next = nxt;
        cur->next = nxt->next;
        nxt->next = cur;
        p0 = cur;
        cur = cur->next;
      }
      return dummy.next;
    }
};
// 25. K个一组反转链表
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy = ListNode(0, head);
        int n = 0;
        ListNode *p0 = &dummy, *cur = head, *pre = nullptr;
        for (ListNode* cur = head; cur; cur = cur->next) {
            n++;
        }
        for (; n >= k; n -= k) {
            for(int j = 0; j < k; j++){
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            ListNode* nxt = p0->next;
            p0->next->next = cur;p0->next = pre;
            p0 = nxt;
        }
        return dummy.next;
    }
};
// 138. 随机链表的复制
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> umap;
        Node* cur = head;
        while(cur){
            Node* node = new Node(cur->val);
            umap[cur] = node;
            cur = cur->next;
        }
        cur = head;
        while(cur){
            umap[cur]->next = umap[cur->next];
            umap[cur]->random = umap[cur->random];
            cur = cur->next;
        }
        return umap[head];
    }
};
// 148. 排序链表
class Solution {
public:
    // 876. 链表的中间结点（快慢指针）
    ListNode* middleNode(ListNode* head) {
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            pre = slow; // 记录 slow 的前一个节点
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr; // 断开 slow 的前一个节点和 slow 的连接
        return slow;
    }

    // 21. 合并两个有序链表（双指针）
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; // 用哨兵节点简化代码逻辑
        ListNode* cur = &dummy; // cur 指向新链表的末尾
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1; // 把 list1 加到新链表中
                list1 = list1->next;
            } else { // 注：相等的情况加哪个节点都是可以的
                cur->next = list2; // 把 list2 加到新链表中
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2; // 拼接剩余链表
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* head2 = middleNode(head);
        ListNode* l = sortList(head);
        ListNode* r = sortList(head2);
        return mergeTwoLists(l, r);
    }
};
// 23. 合并k个升序链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy{}; // 用哨兵节点简化代码逻辑
        auto cur = &dummy; // cur 指向新链表的末尾
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1; // 把 list1 加到新链表中
                list1 = list1->next;
            } else { // 注：相等的情况加哪个节点都是可以的
                cur->next = list2; // 把 list2 加到新链表中
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2; // 拼接剩余链表
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int m = lists.size();
        if(m == 0) return nullptr;
        for(int step = 1; step < m; step *= 2){
            for(int i = 0; i < m - step; i += step * 2){
                lists[i] = mergeTwoLists(lists[i], lists[i + step]);
            }
        }
        return lists[0];
    }
};
