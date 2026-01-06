#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){
        val = 0;
        next = nullptr;
    }
    ListNode(int val){
        this->val = val;
        next = nullptr;
    }
    ListNode(int val, ListNode* L){
        this->val = val;
        next = L;
    }
};

class Solution{
public:
    //迭代版本
    ListNode* reverse_iteration(ListNode* head){
        if(head == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* aft = nullptr;
        while(head != nullptr){
            aft = head->next;
            head->next = pre;
            pre = head;
            head = aft;
        }
        return pre;
    }
    //递归版本
    ListNode* reverse_recursion(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* newhead = reverse_recursion(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
};

int main(){
    ListNode l3(3);
    ListNode l2(2, &l3);
    ListNode l1(1, &l2);
    ListNode* p = &l1;
    while(p != nullptr){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    Solution s;
    ListNode* ans = s.reverse_recursion(&l1);
    while(ans != nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}