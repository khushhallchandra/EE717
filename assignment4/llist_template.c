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
  nodePtr temp = (nodePtr) malloc (sizeof(struct node));
  temp->next = head->next;
  head->next=temp;
  temp->val=val;
  head->val++;
  return 1;
}

int getLength()
{ 
  return head->val;
}

int deleteFirstOccurence(int val)
{
  if(head == NULL || head->val == 0)
  return 0;
  nodePtr temp = head->next;
  nodePtr p1 = head;
  while(temp!=NULL){
    if(temp->val==val){
      nodePtr t1=temp;
      free(t1);
      p1->next=temp->next;
      head->val--;
      return 1;
    }
    temp=temp->next;
    p1=p1->next;
  }
  return 0;
}

int deDuplicate(void){
  int dupl=0; 
  nodePtr ptr1, ptr2, dup;
  ptr1 = head->next; 
  while(ptr1 != NULL && ptr1->next != NULL)
    {
    ptr2 = ptr1;
    while(ptr2->next != NULL){
      if(ptr1->val == ptr2->next->val){
        dup = ptr2->next;
        ptr2->next = ptr2->next->next; 
        free(dup);
        head->val--; 
        dupl+=1; 
        }
      else
       ptr2 = ptr2->next;
    }
    ptr1 = ptr1->next; 
  }
 return dupl; 
}
void reverseList(void){
  if(head == NULL || head->val <=1){
        return;
    }
{
    nodePtr prev   = NULL;
    nodePtr current = head->next;
    nodePtr next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    head->next = prev;
}
}

int isSorted(nodePtr p)
{
    if(head == NULL || head->val <=1){
        return 1;
    }
    nodePtr temp = p;
    while(temp->next!=NULL){
      if(temp->val<temp->next->val)
        temp=temp->next;
      else
         return 0;         
    }
    return 1;
}

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