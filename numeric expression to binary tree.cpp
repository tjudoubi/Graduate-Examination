#include <iostream>
using namespace std;

typedef struct Node{
    char data;
    Node* l,* r;
}Node;
Node* root = new Node();

int se(char s){
    if(s == '*'||s == '/'){
        return 2;
    }else if(s == '+'||s == '-'){
        return 1;
    }
}

void construct(string s,int a,int b,Node* node){
    char temp = '#';int level = 0x3f3f3f;
    int po = -2;
    if(s[a] == '('&&s[b] == ')'){
        b = b-1;
        a = a+1;
    }
    int i = b;
    cout << a << " " << b <<endl;
    while(i >= a){
        if(s[i]>='a'&&s[i] <= 'z'){
            i--;
            continue;
        }else if(s[i]==')'){
            while(s[i] != '('&&i >= a){
                i--;
            }
        }else{
            cout << s[i] << endl;
            if(se(s[i]) < level){
                level = se(s[i]);
                po = i;
           }
        }
        i--;
    }
    if(po != -2){
        node->data = s[po];
        node->l = new Node();
        node->r = new Node();
        construct(s,a,po-1,node->l);
        construct(s,po+1,b,node->r);
    }else{
        node->data = s[a];
        node->l = NULL;
        node->r = NULL;
    }
}

void houxu(Node* node){
    if(node != NULL){
        houxu(node->l);
        houxu(node->r);
        cout << node->data;
    }
}

int main(){
    string s = "a+b*c+(d*e+f)*g";
    construct(s,0,s.size()-1,root);
    //cout << 213 << endl;
    houxu(root);
    cout << endl;
}
