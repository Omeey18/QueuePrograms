#include <stdio.h>
#include <stdlib.h>

/*#define MAXSIZE 5

int queue[MAXSIZE];

int front = -1;
int rear = -1;
*/
void enqueue(int value,int queue[],int *front, int *rear, int MAXSIZE)
{
    if(*rear==MAXSIZE-1)
    {
        *rear = 0;
        if(*rear==*front){
            printf("Queue is full\n");
            *rear = MAXSIZE-1;
        }else{
            queue[*rear] = value;
        }
    	
    }else if(*front==-1 && *rear==-1)
    {	
    	*front = *rear = 0;
            queue[*rear] = value;
    }
    else{
        *rear++;
        if(*rear==*front){
            printf("Queue is full\n");
            *rear--;
        }else{
            queue[*rear] = value;
        }
    }
    

}

int dequeue(int * front, int *rear, int MAXSIZE)
{
int y = queue[*front];
if(*front==-1 && *rear==-1)
{
	printf("Queue is empty\n");
	return 0;
}
else if(*front==*rear)
{
	*front=*rear=-1;
	return y;
}
else if(*front==MAXSIZE-1){
    *front=0;
    return y;
}
else
{
    *front++;
	return y;
}
}

int Front(int *front)
{
    return queue[*front];
}

void display(int queue[],int * front, int *rear, int MAXSIZE)
{
     int i;
    if(*rear == -1 && *front == -1)
    {
        printf("\nQueue is Empty..!\n");
    }
    else if(*rear>=*front)
    {
        printf("[ ");
        for(i=*front;i<=*rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("]");
        printf("\n");
    }
    else
    {
        printf("[ ");
        for(i=*front;i<MAXSIZE;i++)
        {
            printf("%d ",queue[i]);
        }
        for(i=0;i<=*rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("]");
        printf("\n");
    }
    
    
}
