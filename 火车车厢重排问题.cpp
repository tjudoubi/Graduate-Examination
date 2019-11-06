#include <iostream>
#include <queue>
using namespace std;

const int size_ = 3;

void find_optimal(queue<int> q[],int t){
    int index = -1;
    int small_max = -1;
    for(int i = 0 ;i < size_;i++){
        if(t > q[i].back()){
            if(q[i].back() > small_max){
                index = i;
                small_max = q[i].back();
            }
        }
    }
    if(index != -1){
        q[index].push(t);
    }
}


int main(){
    queue<int> q[size_];
    int array[] = {5,8,1,7,4,2,9,6,3};
    for(int i = 0;i < size_;i++){
        q[i].push(0);
    }
    for(int i = 8;i >=0;i--){
        find_optimal(q,array[i]);
    }
    for(int i = 0;i < size_;i++){
        q[i].pop();
    }

    while(!q[0].empty()||!q[1].empty()||!q[2].empty()){
        int top_0,top_1,top_2;
        top_0 = top_1 = top_2 = 0x3f3f3f3f;
        if(!q[0].empty()){
            top_0 = q[0].front();
        }
        if(!q[1].empty()){
            top_1 = q[1].front();
        }
        if(!q[2].empty()){
            top_2 = q[2].front();
        }
        int minn = min(top_0,min(top_1,top_2));
        if(top_0 == minn){
            cout << top_0 << endl;
            q[0].pop();
        }else if(top_1 == minn){
            cout << top_1 << endl;
            q[1].pop();
        }else if(top_2 == minn){
            cout << top_2 << endl;
            q[2].pop();
        }
        cout << q[1].size() << q[2].size() << q[0].size() << endl;
    }
}
