#include <bits/stdc++.h>
using namespace std;


     class ListNode{
         
         public:

         int val;
         ListNode* next;

         ListNode(int val){

            this -> val = val;
            this -> next = NULL;
         }
     };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* list = new ListNode(-1);
        ListNode* connect = list;

        int carry = 0;

        while( carry || (l1 || l2) ){
             
              int sum = carry;

              if(l1){
                 
                 sum += l1 -> val; l1 = l1 -> next;
              }

              if(l2){
                 
                 sum += l2 -> val; l2 = l2 -> next;
              }

              carry = sum / 10;

              connect -> next = new ListNode(sum % 10);
              connect = connect -> next;

        }

        list = list -> next;

        return list;
    }
    
    
    void print(ListNode* head){
         
        ListNode* temp = head;
        
        while( temp != NULL){
            
            cout<<temp -> val<<" ";
            
            temp = temp -> next;
       }
    
    }
    
  
};

int main() {
	
	    Solution leetcode;
	
     	ListNode* node1 = new ListNode(2);
        node1 -> next = new ListNode(4);
        node1 -> next -> next = new ListNode(3);
        
        ListNode* node2 = new ListNode(5);
        node2 -> next = new ListNode(6);
        node2 -> next -> next = new ListNode(4);
        
        ListNode* ans = leetcode.addTwoNumbers(node1,node2);
        
        leetcode.print(ans);
        
        
        
        
}
