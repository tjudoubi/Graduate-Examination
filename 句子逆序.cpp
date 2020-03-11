/*
将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
string s;
vector<string> v;
int main(){
    while(true){
        cin >> s;
        if(getchar() == '\n'){
            v.push_back(s);
            //cout << v.size() << endl;
            break;
        }
        v.push_back(s);
    }
    /*for(int i = 0;i < v.size();i++){
        for(int j = 0;j < v[i].size()/2;j++){
            char t = v[i][j];
            v[i][j] = v[i][v[i].size()-1-j];
            v[i][v[i].size()-1-j] = t;
        }
    }*/
    for(int i = v.size()-1;i >= 0;i--){
        cout << v[i];
        if(i!=0){
            cout << " ";
        }
    }cout << endl;
}
