// Apply quicksort to a Single linked list
#include <iostream>
#include <cstdio>
using namespace std;
 

struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

void push(struct node** head_ref, int new_data)
{

    struct node* new_node = new node(new_data);
 

    new_node->next = (*head_ref);
 

    (*head_ref)    = new_node;
}
 

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}


struct node *getTail(struct node *cur) 
{ 
    while (cur != NULL && cur->next != NULL) 
        cur = cur->next; 
    return cur; 
} 

struct node *partition(struct node *head, struct node *end, 
                    struct node **newHead, struct node **newEnd) 
{ 
    struct node *pivot = end; 
    struct node *prev = NULL, *cur = head, *tail = pivot; 
  
    while (cur != pivot) 
    { 
        if (cur->data < pivot->data) 
        {
            if ((*newHead) == NULL) 
                (*newHead) = cur; 
  
            prev = cur;  
            cur = cur->next; 
        } 
        else 
        { 
 
            if (prev) 
                prev->next = cur->next; 
            struct node *tmp = cur->next; 
            cur->next = NULL; 
            tail->next = cur; 
            tail = cur; 
            cur = tmp; 
        } 
    } 
  
 
    if ((*newHead) == NULL) 
        (*newHead) = pivot; 
  

    (*newEnd) = tail; 
  

    return pivot; 
} 

struct node *quickSortRecur(struct node *head, struct node *end) 
{  
    if (!head || head == end) 
        return head; 
  
    node *newHead = NULL, *newEnd = NULL; 
  

    struct node *pivot = partition(head, end, &newHead, &newEnd); 
  
    if (newHead != pivot) 
    { 

        struct node *tmp = newHead; 
        while (tmp->next != pivot) 
            tmp = tmp->next; 
        tmp->next = NULL; 

        newHead = quickSortRecur(newHead, tmp); 
  

        tmp = getTail(newHead); 
        tmp->next = pivot; 
    } 
 
    pivot->next = quickSortRecur(pivot->next, newEnd); 
  
    return newHead; 
} 
void quickSort(struct node **headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}