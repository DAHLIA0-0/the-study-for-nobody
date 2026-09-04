#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *merge(struct node *a,struct node *b){
       struct node *pa=a;
       struct node *pb=b;
       struct node *tail=NULL;
       struct node *p=NULL;
       struct node *head=NULL;
       if(pa==NULL) return pb;
       if(pb==NULL) return pa;
       while(pa!=NULL&&pb!=NULL){
            if(pa->data<=pb->data){
               p=pa;
               pa=pa->next;
            }else{
               p=pb;
               pb=pb->next;
            }
            if(head==NULL){
                head=p;
                tail=p;
            }else{
            tail->next=p;
            tail=p;
         }
       }

       if(pa==NULL){
         tail->next=pb;
       }else
         tail->next=pa;

       return head;
}

int count(struct node *head){
    int i=0;
    while(head!=NULL){
        i++;
        head=head->next;
    }
    return i;
}

struct node *find(struct node *head,int x){
       struct node *p=NULL;
       while(head!=NULL){
             if(head->data==x){
                p=head;
                break;
             }
             head=head->next;
       }
       return p;
}

struct node *reverse(struct node *head) {
    struct node *head2 = NULL;   /* 新链头，初始空 */
    struct node *p = head;       /* 从原链头开始摘 */
    struct node *q = NULL;       /* 用来记"下一个" */
    while (p != NULL) {
        q = p->next;      /* ① 先记下原链的下一个 */
        p->next = head2; /* ② 把 p 头插到新链最前 */
        head2 = p;   /* ③ 更新新链头 */
        p = q;       /* ④ p 回到原链的下一个（继续摘）*/
    }
    return head2;         /* 返回新链头（反转后的头）*/
}

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
    struct node *headA, *headB, *headC ,*headD,*thefind,*combine;
    int n1, n2,add,fin;

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

    headD=reverse(headD);
    printf("\n反转链表后:");
    print(headD);
    
    printf("结点一共有%d个\n",count(headD));
    printf("请输入要找的结点:\n");
    scanf("%d",&fin);
    thefind=find(headD,fin);
    if(thefind==NULL)
    printf("链表中没有该数据\n");
    else
    printf("找到了该数据，是%d",thefind->data);

    combine=merge(*headA,*headB);

    destroy(headD);

    return 0;
}
