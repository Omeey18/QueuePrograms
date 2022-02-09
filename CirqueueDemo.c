#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int queue[MAXSIZE];

int front = -1;
int rear = -1;

void enqueue(int value)
{
    if(rear==MAXSIZE-1)
    {
        rear = 0;
        if(rear==front){
            printf("Queue is full\n");
            rear = MAXSIZE-1;
        }else{
            queue[rear] = value;
        }
    	
    }else if(front==-1 && rear==-1)
    {	
    	front = rear = 0;
            queue[rear] = value;
    }
    else{
        rear++;
        if(rear==front){
            printf("Queue is full\n");
            rear--;
        }else{
            queue[rear] = value;
        }
    }
    

}

int dequeue()
{
int y = queue[front];
if(front==-1 && rear==-1)
{
	printf("Queue is empty\n");
	return 0;
}
else if(front==rear)
{
	front=rear=-1;
	return y;
}
else if(front==MAXSIZE-1){
    front=0;
    return y;
}
else
{
    front++;
	return y;
}
}

int Front()
{
    return queue[front];
}

void display()
{
     int i;
    if(rear == -1 && front == -1)
    {
        printf("\nQueue is Empty..!\n");
    }
    else if(rear>=front)
    {
        printf("[ ");
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("]");
        printf("\n");
    }
    else
    {
        printf("[ ");
        for(i=front;i<MAXSIZE;i++)
        {
            printf("%d ",queue[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("]");
        printf("\n");
    }
    
    
}

int main()
{
	   int data[5],val,sign;
	   while(sign!=5){
	       printf("Enter 1 for enqueue:\nEnter 2 for dequeue\nEnter 3 for Front value:\nEnter 4 for display queue:\nEnter 5 for exit:\n");
	       scanf("%d",&sign);
	       
	       switch(sign){
	           case 1:
	           printf("\nEnter value:\n");
	           scanf("%d",&val);
	           enqueue(val);
	           break;
	           
	           case 2:
	           printf("\nDeleted element is: %d\n",dequeue());
	           break;
	           
	           case 3:
	           printf("\nFront element is: %d\n",Front());
	           break;
	           
	           case 4:
	           display();
	           break;
	           
	           case 5:
	           exit(1);
	           
	           default:
	           printf("\ninvalid choice..!\n");
	          
	       }
	   }
	   

		
   
    return 0;
}
