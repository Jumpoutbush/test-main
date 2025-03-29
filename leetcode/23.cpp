#include <iostream>
#include <vector>

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 合并两个有序链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // 创建一个虚拟头节点，方便操作
    ListNode dummy(0);
    ListNode* tail = &dummy;

    // 比较两个链表的节点值，将较小的节点添加到结果链表中
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // 将剩余的节点添加到结果链表中
    if (l1) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;
}

// 分治法合并多个有序链表
ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    // 如果链表为空，则返回空指针
    if (lists.empty()) return nullptr;
    int n = lists.size();

    // 不断合并链表，直到只剩下一个链表
    while (n > 1) {
        // 计算需要合并的链表数量
        int k = (n + 1) / 2;
        // 合并链表
        for (int i = 0; i < n / 2; ++i) {
            lists[i] = mergeTwoLists(lists[i], lists[i + k]);
        }
        // 更新链表数量
        n = k;
    }

    // 返回合并后的链表
    return lists[0];
}

// 辅助函数：创建链表
ListNode* createList(const std::vector<int>& values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) {
            std::cout << "->";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // 创建示例链表数组
    std::vector<ListNode*> lists = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };

    // 合并链表
    ListNode* mergedList = mergeKLists(lists);

    // 打印合并后的链表
    printList(mergedList);

    return 0;
}