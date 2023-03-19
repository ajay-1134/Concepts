#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(){
        val = 0;
        next = NULL;
    }
    ListNode(int x){
        val = x;
        next = NULL;
    }
    ListNode(int x, ListNode* next){
        val = x;
        next = next;
    }
};

ListNode* reverseList(ListNode* head) {
    ListNode* temp = NULL;
    while(head != NULL){
        ListNode* node = head->next;
        head->next = temp;
        temp = head;
        head = node;
    }
    return temp;
}

int main(){
    int n;
    cin>>n;
    int first; cin>>first;
    ListNode* head = new ListNode(first);
    ListNode* temp = head;
    for(int i=0; i<n-1; i++){
        int var; cin>>var;
        // cout<<var<<" ";
        temp->next = new ListNode(var);
    }
    ListNode* given = head;
    ListNode* reversed = reverseList(head);
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl<<"After reversing"<<endl;
    while(reversed){
        cout<<reversed->val<<" ";
        reversed = reversed->next;
    }



}