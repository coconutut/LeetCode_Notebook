#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    //切记next指针赋值，不然为野指针
    ListNode(){
        val = 0;
        next = nullptr;
    }
    ListNode(int val){
        this->val = val;
        next = nullptr;
    }
    ListNode(int val, ListNode* next){
        this->val = val;
        this->next = next;
    }
};

class Solution{
public:
    // 殊途同归
    ListNode* IntersectionNode(ListNode* headA, ListNode* headB){
        // if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA != tempB){
            tempA = (tempA == nullptr) ? headB : tempA->next;
            tempB = (tempB == nullptr) ? headA : tempB->next;
        }
        return tempA;
    }
};

int main() {
    ListNode* common = new ListNode(8, new ListNode(9));
    ListNode* headA = new ListNode(1, new ListNode(2, common));
    ListNode* headB = new ListNode(3, new ListNode(4, common));
    Solution sol;
    ListNode* intersection = sol.IntersectionNode(headA, headB);
    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection." << endl;
    }

    delete headA->next; // 2
    delete headA;       // 1
    delete headB->next; // 4
    delete headB;       // 3
    delete common->next; // 9
    delete common;       // 8

    return 0;
}