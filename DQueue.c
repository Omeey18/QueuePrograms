#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5


int queue[MAXSIZE];

int front = -1;
int rear = -1;

void DQINSERT_FRONT(int value){
    if(front==-1){
        printf("Queue is empty...!\n");
    }
    else if(front==0){
        printf("Queue is underflow...!\n");
    }
    else {
        front--;
        queue[front]=value;
    }
}

int DQDELETE_REAR(){
    if(rear==0){
        printf("Queue is underflow...!\n");
        return 0;
    }
    int y = queue[rear];
    if(rear==front){
        rear = front = -1;
    }else{
        rear--;
    }
    return y;
}

void DQDISPLAY(){
    printf("[ ");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("]");
    printf("\n");
}

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



int main()
{

	   enqueue(5);
	   enqueue(6);
	   enqueue(7);
	   enqueue(8);
	   enqueue(4);
	   DQDISPLAY();
	   dequeue();
	   dequeue();
	   printf("Deleted: %d\n",DQDELETE_REAR());
	   DQINSERT_FRONT(3);
	   DQINSERT_FRONT(3);
	   DQDISPLAY();
	   

   
    return 0;
}
