/* This Project is a good practice to implement The most common Two methods to Make Queue data structure .
THe first method : Two pointers .
The second method : two index
*/

#include <stdio.h>
#include <stdlib.h>
#define queue_size 16
#define Success 1
#define Failed 0

int q[queue_size];
// The Two pointers method :

volatile int *Put_p;
volatile int *get_p;
void Init_queue_Pointers(void)
{
    Put_p=get_p=q;
}



int Put_Pointers(int data)
{
    int *next_put ;
    next_put=Put_p;
    next_put++;
    if(next_put==&q[queue_size])
    {
        next_put=&q[0];
    }
    if (next_put==get_p){
        return (Failed);
    }
    else{
        *(Put_p)=data;
        Put_p=next_put;
        return (Success);
    }

}


int get_Pointers(int *data){

if (Put_p==get_p){
    return (Failed);
}
else{
    *(data)=*(get_p++);
    if(get_p==&q[queue_size]){
       get_p=&q[0] ;
    }
    return (Success);
}
}


//The Two Index Method :
volatile int put_index;
volatile int get_index;

void  init_queue_Index(void)
{
    put_index=get_index=0;

}

int put_I(int data)
{

    if((put_index-get_index)&(queue_size-1))
    {
        return(Failed);
    }
    q[put_index&(queue_size-1)]=data;
    put_index++;
    return(Success);
}

int get_I(int*data)
{
    if(get_index==put_index)
    {
        return(Failed);
    }
    else {
        *data=q[get_index&(queue_size-1)];
        get_index++;
        return(Success);
    }
}


int main()
{
    int i;
    Init_queue_Pointers();
    printf("put 5 :%d\n",put_I(5));
    printf("get the value %d\n",get_I(&i));
    printf("get the value %d",i);

    return 0;
}
