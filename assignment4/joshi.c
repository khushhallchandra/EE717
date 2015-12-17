#include <stdio.h>
#include<stdlib.h>

struct node {
    int val;
    struct node *next;
};

typedef struct node * nodePtr;

char operations[][30] = {"add","deleteFirstOccurence","deDuplicate","reverseList","isSorted","getLength","printList"};

nodePtr head;

void init(void)
{
    head = (nodePtr) malloc (sizeof(struct node));
    head->val = 0;
    head->next = NULL;
}

void cleanup(void)
{
    if(head == NULL) return;

    nodePtr curr=head->next, tmp;

    while(curr!=NULL){
       tmp = curr->next;
       free(curr);
       curr = tmp; 
    }
    head->val = 0;
    head->next = NULL;
    return;
}



void printList(void)
{
    printf("List: ");
    if(head == NULL || head->val == 0){
        printf("\n");
        return;
    }
    nodePtr tmp = head->next;
    while(tmp!=NULL){
        printf("%d ",tmp->val);
        tmp=tmp->next;
    }
    printf("\n");
}

void printListWithPointers(void)
{
    if(head==NULL){
        printf("List header not created\n");
        return;
    }
    printf("(Head, %p) -> ",head->next);
    if(head->val == 0){
        printf("NULL\n");
        return;
    }
    else{
        nodePtr tmp = head->next;
        while(tmp->next != NULL){
            printf("(%d %p) -> ",tmp->val,tmp->next);
            tmp=tmp->next;
        }
        printf("(%d %p)",tmp->val,tmp->next);
        
        printf("\n");
    }
}

int add(int val)
{
  nodePtr new_node = (struct node*) malloc(sizeof(struct node)); 
  if (new_node!=NULL) 
  { new_node->val=val; 
   new_node->next=head->next; 
   head->next=new_node; 
   head->val = head->val + 1; 
   return 1; 
  } 
  else return 0; 
}


int getLength()
{
  return head->val;
}

int deleteFirstOccurence(int val)
{
  nodePtr y = (struct node*) malloc(sizeof(struct node));
  int ret=0;
  nodePtr previous = (struct node*) malloc(sizeof(struct node));
    previous=head;
 y=head->next;
  while(y!=NULL)
  {
    if(y->val==val)
    {
      previous->next=y->next;
      ret=1;
      head->val=head->val-1;
      break;
    }
   previous=y;
    y=y->next;
  }
 return ret;
    
  //return 1;
}

int deDuplicate(void) 
{ int flag=0; 
 nodePtr ptr1, ptr2, dup;
 ptr1 = head->next; 
 while(ptr1 != NULL && ptr1->next != NULL)
 { ptr2 = ptr1; while(ptr2->next != NULL) 
 { if(ptr1->val == ptr2->next->val) 
 { dup = ptr2->next; 
  ptr2->next = ptr2->next->next; 
  free(dup); 
  head->val--; 
  flag+=1; 
 } 
  else ptr2 = ptr2->next;
 } 
  ptr1 = ptr1->next; 
 }
 return flag; 
}
void reverseList(void) { struct node* prev =(struct node*) malloc(sizeof(struct node)); struct node* current= (struct node*) malloc(sizeof(struct node)); struct node* net=(struct node*) malloc(sizeof(struct node)); prev=NULL; current=head->next; while (current != NULL) { net = current->next; current->next = prev; prev = current; current = net; } head->next=prev; }

int isSorted(nodePtr p) { return ( (p == NULL) ||(p->next == NULL) || (( p->val <= p->next->val) && isSorted(p->next))); }

int main(void)
{
    int op, val;

    int status;


    init();

    while(scanf("%d",&op) != EOF){
        switch(op){
            case 0: scanf("%d",&val);status=add(val); printf("%d\n",status);break;
            case 1: scanf("%d",&val);status=deleteFirstOccurence(val); 
                        printf("%d\n",status);break;
            case 2: status=deDuplicate(); printf("%d\n",status);break;
            case 3: reverseList(); break;
            case 4: status=isSorted(head->next); printf("%d\n",status);break;
            case 5: status=getLength(head); printf("%d\n",status);break;
            case 6: printList(); break;
        }
    }       
    
    printList();
    cleanup();
    return 0;
}
