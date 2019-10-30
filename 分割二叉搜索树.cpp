/*编写算法，将一颗二叉排序树t分解成两颗二叉排序树t1与t2，
使得t1中的所有节点关键字的值都小于x，t2中所有节点的关键字的
值都大于x*/

# include <iostream>
using namespace std;

typedef struct Node{
    Node* node[2];
    int data;
}Node;
Node* root;

Node* root_B,* root_S;

void insert(Node* & node,int data){
    if(node == NULL){
        node = new Node();
        node->data = data;
    }else{
        if(data < node->data){
            insert(node->node[0],data);
        }else{
            insert(node->node[1],data);
        }
    }
}

void add_node(Node* & node,Node* & node_temp){
    if(node_temp == NULL){
        return ;
    }

    if(node == NULL){
        node = node_temp;
    }else{
        if(node->data > node_temp->data){
            add_node(node->node[0],node_temp);
        }else{
            add_node(node->node[1],node_temp);
        }
    }
}


void detach(Node* node,int val){
    if(node == NULL){
        return ;
    }
    if(node->data > val){
        Node* temp = node->node[0];
        node->node[0] = NULL;
        add_node(root_B,node);
        detach(temp,val);
    }else if(node->data < val){
        Node* temp = node->node[1];
        node->node[1] = NULL;
        add_node(root_S,node);
        detach(temp,val);
    }else{
        add_node(root_B,node->node[1]);
        add_node(root_S,node->node[0]);
    }
}

void bianli(Node* node){
    if(node == NULL){
        return ;
    }else{
        bianli(node->node[0]);
        cout << node->data << " ";
        bianli(node->node[1]);
    }
}


int main(){
    int array[] = {63,55,90,42,58,70,10,45,67,83};
    for(int i = 0;i < 10;i++){
        insert(root,array[i]);
    }
    bianli(root);
    cout << endl;
    int c;
    cin >> c;

    detach(root,c);
    bianli(root_S);
    cout << endl;
    bianli(root_B);
    cout << endl;
}
