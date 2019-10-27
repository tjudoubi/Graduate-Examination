#include <iostream>
using namespace std;

int get_average(int* array,int a,int b){
    int sum = 0;
    for(int i = a;i <= b;i++){
        sum += array[i];
    }
    return sum/(b-a+1);
}

void quick(int* array,int a,int b){
    if(a < b){
            cout << a << " " << b << endl;
        int temp = get_average(array,a,b);
        int i = a,j = b;
        while(i < j){
            while(i < j&&array[j] >= temp){
                j--;
            }
            while(i < j&&array[i] < temp){
                i++;
            }
            if(i < j){
                int lkl = array[i];
                array[i] = array[j];
                array[j] = lkl;
            }
        }

        cout << i << " " << j <<endl;
        cout << temp << endl;
        for(int i = 0;i <= 10;i++){
            cout << array[i] << " ";
        }
        cout << endl;
        if(array[i] >= temp&&i != a){
            quick(array,a,i-1);
            quick(array,i,b);
        }else if(array[i] < temp&&j != b){
            quick(array,a,i);
            quick(array,i+1,b);
        }

    }
}

int main(){
    int array[] = {1,4,2,5,6,3,123,35,646,553,-5};
    quick(array,0,10);
    for(int i = 0;i <= 10;i++){
        cout << array[i] << " " ;
    }
}
