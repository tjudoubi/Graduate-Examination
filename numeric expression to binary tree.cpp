//////找到表达式中最后一次进行运算的运算符然后左右递归/////

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
/*
////no recursion///
void houxu(Node* root){
    Node* node = root;
    Node* prev = NULL;
    stack<Node*> st;
    while(node||!st.empty()){
        while(node){
            st.push(node);
            node = node->l;
        }
        Node* top = st.top();
        if(top->r==NULL||prev==top->r){
            cout << top->data;
            prev = top;
            st.pop();
        }else{
            node = top->r;
        }
    }
}
*/

int main(){
    string s = "a+b*c+(d*e+f)*g";
    construct(s,0,s.size()-1,root);
    //cout << 213 << endl;
    houxu(root);
    cout << endl;
}

/*
#include <iostream>
using namespace std;

typedef struct Tree{
    Tree* left ,* right;
    char data;
}Tree;
Tree* root;

void build(string s,int a,int b,Tree* & node){
    int index = -1;
    int signal_last = 0x3f3f3f3f;
    //cout << a <<  " " << b << endl;
    if(a == b){
        node = new Tree();
        node->data = s[a];
    }else if(s[a] == '(' && s[b] == ')'){
        build(s,a+1,b-1,node);
    }else{
        int i = b;
        while( i >= a){
            cout << i << endl;
            if(s[i] == ')'){
                while(s[i] != '('){
                    i--;
                }
                i--;
            }else if(s[i] <= 'z'&&s[i] >= 'a'){
                i--;
            }else if(s[i] == '*'||s[i] == '/'){
                if(signal_last > 2){
                    signal_last = 2;
                    index = i;
                }
                i--;
            }else if(s[i] == '+'||s[i] == '-'){
                if(signal_last > 1){
                    cout << i << endl;
                    signal_last = 1;
                    index = i;
                }
                i--;
            }
        }
        node = new Tree();
        node->data = s[index];
        build(s,a,index-1,node->left);
        build(s,index+1,b,node->right);
    }
}

void houxu(Tree* node){
    if(node != NULL){
        houxu(node->left);
        houxu(node->right);
        cout << node->data;
    }
}

int main(){
    string s = "a+b*c+(d*e+f)*g";
    build(s,0,s.size()-1,root);
    houxu(root);
    cout << endl;
}
*/
