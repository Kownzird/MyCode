/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
假设除了数字 0 之外，这两个数都不会以 0 开头

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *root = new ListNode(0);
        ListNode *cursor = root;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0) {
            int l1Val = l1 != NULL ? l1->val : 0;
            int l2Val = l2 != NULL ? l2->val : 0;
            int sumVal = l1Val + l2Val + carry;
            carry = sumVal / 10;
            
            ListNode *sumNode = new ListNode(sumVal % 10);
            cursor->next = sumNode;
            cursor = sumNode;
            
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        
        return root->next;
    }

    static void showListNode(ListNode *l){
        ListNode *cursor = l;

        while(cursor!=NULL){
            cout << cursor->val << " ";
            cursor = cursor->next;
        }
        cout << endl;
    }

    static ListNode* createListNode(vector<int> &v){
        ListNode *root = new ListNode(0);
        ListNode *cursor = root;

        int len = v.size();
        for(int i=0; i<len; i++){
            ListNode *node = new ListNode(v[i]);
            cursor->next = node;
            cursor = cursor->next;
        }

        return root->next;
    }
};


int main(int argc, char **argv){
    vector<int> v1,v2;
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;
    ListNode *pTarget = NULL;

    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(3);
    v1.push_back(0);
    v1.push_back(1);

    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(4);

    l1 = Solution::createListNode(v1);
    l2 = Solution::createListNode(v2);
    pTarget = Solution::addTwoNumbers(l1,l2);

    Solution::showListNode(pTarget);

    return 0;
}