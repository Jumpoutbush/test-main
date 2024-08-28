#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    node* next;
};
//创建链表
node* create(int Array[]){
    node *p, *pre, *head;
    head = new node;
    head->next = NULL;
    pre = head;
    for(int i=0;i<5;i++){
        p = new node;
        p->data = Array[i];
        p->next = NULL ;
        pre->next = p;
        pre = p;
    }
    return head;
}
//链表中x的个数
//可把create创建的头指针L作为第一个参数传入即可
int search(node* head,int x){
    int count = 0;
    node* p = head->next;
    while(p!=NULL){
        if(p->data = x){
            count++;
        }
        p=p->next;
    }
    return count;
}
//插入元素
void insert(node* head,int pos, int x){
    node* p = head;
    for(int i=0;i<pos-1;i++){
        p=p->next;
    }
    node* q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;
}
//删除值为x的元素
void del(node* head, int x){
    node* p = head->next;
    node* pre = head;
    while(p!=NULL){
        if(p->data == x){
            pre->next = p->next;
            delete(p);
            p = pre->next;
        }else{
            pre = p;
            p = p->next;
        }
    }
}
int main(){
    int Array[5] = {5,3,6,1,2};
    node* L = create(Array);
    insert(L,2,9);
    del(L,5);
    L = L->next;
    while(L!=NULL){
        printf("%d ",L->data);
        L = L->next;
    }
    system("pause");
    return 0;
}