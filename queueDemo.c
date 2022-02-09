#include <stdio.h>


#define MAXSIZE 10

int queue[MAXSIZE];

int front = -1;
int rear = -1;

void enqueue(int value)
{
if(rear==MAXSIZE-1)
{
	printf("Queue is full\n");
}
if(front==-1 && rear==-1)
{	
	front = rear = 0;
        queue[rear] = value;
}
else
{
	rear++;
	queue[rear] = value;
}
}

int dequeue()
{
if(front==-1 && rear==-1)
{
	printf("Queue is empty\n");
	return 0;
}
else if(front==rear)
{
	
	front=rear=-1;
	//return queue[front];
}
else
{
	
        front++;
	return queue[front-1];
}
}

int Front()
{
    return queue[front];
}

void display()
{
    int i;
	if(front==-1 && rear==-1)
		printf("Queue is empty\n");
    	else if(rear>=front)
    	{
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
	printf("\n");
    }
    
}

int main()
{
	    enqueue(4);
	    enqueue(8);
	    enqueue(10);
	    enqueue(20);
	    display();
	    printf("Deleted element: %d",dequeue());
	    printf("\nAfter dequeue\n");
	    display();
	    printf("\n%d",Front());
		
   
    return 0;
}
