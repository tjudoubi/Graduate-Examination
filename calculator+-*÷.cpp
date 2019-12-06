#include <iostream>
#include <cmath>
#include <stack>
#include <cstdio>
using namespace std;


double string_to_num(string s){
    double a = 0;
    for(int i = 0;i < s.size();i++){
        a += (s[i]-'0')*pow(10,s.size()-i-1);
    }
    return a;
}

double make(double m,double n,string op){
    if(op == "+"){
        return m+n;
    }else if(op == "-"){
        return n-m;
    }else if(op == "*"){
        return m*n;
    }else if(op == "/"){
        return n/m;
    }
}

void cacu(stack<double>& st1,stack<string>& st2,string op){
    if(op == "+"||op == "-"){
        while(!st2.empty()){
            double m = st1.top();st1.pop();
            double n = st1.top();st1.pop();
            string op = st2.top();st2.pop();
            st1.push(make(m,n,op));
        }
        st2.push(op);
    }else{
        while(!st2.empty()&&(st2.top() == "*"||st2.top() == "/")){
            double m = st1.top();st1.pop();
            double n = st1.top();st1.pop();
            string op = st2.top();st2.pop();
            st1.push(make(m,n,op));
        }
        st2.push(op);
    }
}

int main(){
    string s1 = "4 + 2 * 5 - 7 / 11";
    //cin >> s1;
    stack<double> st1;
    stack<string> st2;
    int a = 0;
    while(a < s1.size()||st1.size()!=1){
        if(a < s1.size()){
            string temp = "";
            while(a<s1.size()&&s1[a] != ' '){
                if(s1[a] >= '9'||s1[a] <= '0'){
                    temp += s1[a];
                    a++;
                }else{
                    temp += s1[a];
                    a++;
                }
            }
            if(temp == "+"||temp == "-"||temp == "*"||temp == "/"){
                if(st2.size() == 0){
                    st2.push(temp);
                }else{
                    cacu(st1,st2,temp);
                }
            }else{
                double m = string_to_num(temp);
                st1.push(m);
            }
            while(a < s1.size()&&s1[a] == ' '){
                a++;
            }
        }else{
            while(!st2.empty()){
                double m = st1.top();st1.pop();
                double n = st1.top();st1.pop();
                string op = st2.top();st2.pop();
                st1.push(make(m,n,op));
            }
        }
    }
    printf("%.2f",st1.top());
}
