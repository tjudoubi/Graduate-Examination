#include <iostream>
using namespace std;
typedef struct Node{
    Node* next;
    int val;
}Node;
Node* head,* tail;

void build(int n){
    head = new Node();
    //tail = new Node();
    Node* head_temp = head;
    for(int i = 1;i <= n;i++){
        head->next = new Node();
        head->val = i;
        if(i != n){
            head = head->next;
        }
    }
    tail = head;
    head = head_temp;
    tail->next = head;//cout << tail->next->val << endl;
}

int main(){
    int n = 10;
    build(n);
    int len = n;
    //cout << tail->val << endl;
    Node* pre = tail;//cout << tail->val << endl;
    int i = 0;
    while(len != n/2){
        i++;
        if(i == 9){
            cout << head->val << endl;
            pre->next = head->next;
            head = head->next;
            len--;
            i = 0;
        }else{
            pre = pre->next;
            head = head->next;
        }
    }
}
