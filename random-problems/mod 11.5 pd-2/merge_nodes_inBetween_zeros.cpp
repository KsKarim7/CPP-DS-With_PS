// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:

//     void insert_tail(ListNode *&head,ListNode *&tail,int val){
//         ListNode *newNode = new ListNode(val);
//         if(head == NULL){
//             head = newNode;
//             tail = newNode;
//             return;
//         }
//         tail->next = newNode;
//         tail = newNode;
//     }
//     ListNode* mergeNodes(ListNode* head) {
//         ListNode *st = NULL;
//         ListNode *nd = NULL;
//         ListNode *temp = head;
//         int sum = 0;
//         while(temp->next != NULL){
//             if(temp->next->val > 0){
//                 sum+=temp->next->val;
//             }
//             else{
//                 insert_tail(st,nd,sum);
//                 sum = 0;
//             }
//             temp = temp->next;
//         }
//         return st;
//     }
// };