#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void destroy(struct node *head){
     struct node *cur=NULL;
     struct node *p = head;
     while(p!=NULL){
          cur=p;
          p=p->next;
          printf("释放结点%d\n",cur->data);
          free(cur);
     }
}

struct node *insertHead(struct node *head){
       int data;
       struct node *add = NULL;
       printf("请输入要插在头部的结点元素：");
       scanf("%d",&data);
       add = (struct node *)malloc(sizeof(struct node));
       add->data=data;
       add->next=head;
       head=add;
       return add;
}

struct node *insertTail(struct node *head,int x){
       struct node *cur=head;
       struct node *tail=NULL;
       while(cur->next!=NULL){
             cur=cur->next;
       }
       tail=(struct node *)malloc(sizeof(struct node));
       tail->data=x;
       cur->next=tail;
       tail->next=NULL;
       return head;
}

/* 函数1：创建 n 个结点的链表，返回头指针 */
struct node *creat(int n) {
       int data,i;
       struct node *head=NULL;
       struct node *tail=NULL;
       struct node *p=NULL;
       printf("请输入\n");
       for(i=0;i<n;i++){
           scanf("%d",&data);
           p=(struct node *)malloc(sizeof(struct node));
           p->data=data;
           p->next=NULL;
           if(head==NULL){
              head = p;
              tail = p;
           }else{
              tail->next=p;
              tail=p;
           }
       }
       return head;
    /* 请补充 */
}

/* 函数2：把链表 b 接到链表 a 末尾，返回 a 的头指针 */
struct node *concentrate(struct node *a, struct node *b) {
    struct node *head=a;
    struct node *p=a;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=b;
    return head;

    /* 请补充 */
}

/* 函数3：打印整个链表 */
void print(struct node *head) {
    struct node *p = head;
    while(p!=NULL){
        printf("%d",p->data);
        if(p->next!=NULL)
        printf("->");
        else
        printf("->NULL\n");
    p=p->next;
    }
    /* 请补充 */
}

int main() {
    struct node *headA, *headB, *headC ,*headD;
    int n1, n2,add;

    printf("请输入链表A的结点个数：");
    scanf("%d", &n1);
    headA = creat(n1);

    printf("请输入链表B的结点个数：");
    scanf("%d", &n2);
    headB = creat(n2);

    headC = concentrate(headA, headB);

    printf("合并后的链表：");
    print(headC);
    
    printf("\n请输入要在尾部插入的结点\n");
    scanf("%d",&add);
    headD = insertTail(headC,add);
    printf("请输入要在尾部插入的结点\n");
    scanf("%d",&add);
    headD = insertTail(headC,add);

    printf("尾部插入后:");
    print(headD);

    headD=insertHead(headD);  //这一行是否赋值重要吗，如果没有的话也是一样的结果？
    printf("\n头部插入后:");
    print(headD);
    
    destroy(headD);

    return 0;
}