#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
typedef struct Node{
    int num;
    int strip;
}Node;
typedef struct Head{
    int x,y,pre;
}Head;
const int target = (1<<16)-1;
int vis[target+20];
Head pre[target+20];
int start;
string ss;


int count_(string& ss){
    int len = ss.size();
    int num = 0;
    for(int i = 0;i < len;i++){
        int a = ss[i]-'0';
        num = num*2+a;
    }
    return num;
}
int bfs(int start){
    Node node;
    node.num = start;
    node.strip = 0;
    queue<Node> que;
    que.push(node);
    vis[start] = 1;
    while(!que.empty()){
        Node u = que.front();
        que.pop();
        int u_num = u.num;
        int u_strip = u.strip;
        //cout << u_num << endl;
        //cout << u_strip << endl;
        if(u_num == target){
            return u_strip;
        }
        for(int i = 0;i < 4;i++){
            for(int j = 0;j < 4;j++){
                int v_num = u_num;
                v_num ^= 15 <<((3-i)*4);///将i所在行全部数字取反 15 = 0000 0000 0000 0001
                v_num ^= (4369 << (3-j));///将j所在列全部数字取反  4369 = 0001 0001 0001 0001
                v_num ^= (1 << (15-4*i-j));///i j位置数字再取反，因为i行取反和j列取反导致ij元重复取反没变
                if(!vis[v_num]){
                    vis[v_num] = 1;
                    Node v;
                    v.num = v_num;
                    v.strip = u.strip+1;
                    que.push(v);
                    pre[v_num].x = i+1;
                    pre[v_num].y = j+1;
                    pre[v_num].pre = u_num;///前向量
                }
            }
        }
    }
    return -1;
}
int main(){
    char ch;
    while(scanf("%c",&ch)!=EOF){
        ss = "";
        memset(vis,0,sizeof(vis));
        memset(pre,-1,sizeof(pre));
        if(ch == '+'){
            ss += '0';
        }else{
            ss += '1';
        }
        for(int i = 1;i < 16;i++){
            scanf("%c",&ch);
            if(ch == '+'){
                ss += '0';///+为0
            }else{
                ss += '1';///-为1
            }
            if(i%4 == 3){
                getchar();
            }
        }///-+-- ---- ---- -+-- 为1011 1111 1111 1011
        start = count_(ss);
        int ans = bfs(start);
        printf("%d\n",ans);
        int t = target;
        stack<int> x_s,y_s;
        while(t != start){
            x_s.push(pre[t].x);
            y_s.push(pre[t].y);
            t = pre[t].pre;
        }
        while(!x_s.empty()){
            printf("%d %d\n",x_s.top(),y_s.top());
            x_s.pop();y_s.pop();
        }

    }
}
