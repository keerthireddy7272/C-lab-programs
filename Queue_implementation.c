#include<stdio.h>
#define SIZE 5
void insert(int item,int *front,int *rear,int q[]){
if(*rear==SIZE-1){
printf("Queue overflow\n");
}else{
if(*front==-1){
*front=0;
}
(*rear)++;
q[*rear]=item;
printf("%d inserted into the queue\n",item);
}
}
int delete(int *rear,int q[],int *front){
if(*front==-1||*front>*rear){
printf("Queue is empty\n");
return-1;
}
int item_del=q[*front];
(*front)++;
if(*front>*rear){
*front=*rear=-1;
}
return item_del;
}
void display(int q[],int *front,int *rear){
if(*front==-1||*front>*rear){
printf("Queue is empty\n");
}else{
printf("Elements in the queue:");
for(int i=*front;i<=*rear;i++){
printf("%d ",q[i]);
}
printf("\n");
}
}
int main(){
int q[SIZE],choice,item,gone;
int front=-1,rear=-1;
while(1){
printf("Enter the choice (1.insert,2.delete,3.display,4.exit):");
scanf("%d",&choice);
switch(choice){
case 1:
printf("Enter the element to be inserted:");
scanf("%d",&item);
insert(item,&front,&rear,q);
break;
case 2:
gone=delete(&rear,q,&front);
if(gone!=-1){
printf("The element deleted is %d\n",gone);
}
break;
case 3:
display(q,&front,&rear);
break;
case 4:
printf("Exiting the program.\n");
return 0;
default:
printf("You entered a wrong choice\n");
break;
}
}
return 0;
}
