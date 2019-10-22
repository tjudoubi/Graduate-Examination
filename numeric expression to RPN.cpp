#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
int se(char s){
    if(s == '*'||s == '/'){
        return 2;
    }else if(s == '+'||s == '-'){
        return 1;
    }
}

void reform(string s){
    stack<char> st_num;
    stack<char> st_op;
    st_op.push('#');
    st_num.push('#');
    int l = s.size();
    for(int i = 0;i < l;i++){
        if(s[i]<='z'&&s[i]>='a'){
            st_num.push(s[i]);
        }else if(s[i] == '('){
            st_op.push(s[i]);
        }else if(s[i] == ')'){
            while(st_op.top() != '('){
                char temp = st_op.top();
                st_num.push(temp);
                st_op.pop();
            }
            st_op.pop();
        }else if(s[i] == '+'||s[i] == '-'||s[i] == '*'||s[i] == '/'){
            char temp = st_op.top();
            if(temp == '('){
                st_op.push(s[i]);
            }else{
                while(se(temp) >= se(s[i])&&temp != '('&&temp != '#'){
                    st_num.push(temp);
                    //cout << st_num.top() << endl;
                    st_op.pop();
                    if(st_op.empty()){
                        break;
                    }else{
                        temp = st_op.top();
                    }
                }
                st_op.push(s[i]);
                cout << i << endl;
                cout << st_op.top() << endl; cout << endl;
            }
        }
    }
    while(!st_op.empty()){
        char temp = st_op.top();
        st_num.push(temp);
        st_op.pop();
    }
    while(!st_num.empty()){
        cout << st_num.top() <<endl;
        st_num.pop();
    }

}

int main(){
    string s = "a+b*c+(d*e+f)*g";
    reform(s);
}
