#include <iostream>
using namespace std;

struct Queue
{
    int *arr;
    int front,size,capacity;
    
};

    struct Queue* createQueue(int s){
        struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
        queue->capacity=s;
        queue->size=0;
        queue->front=0;
        queue->arr = new int[s];
    }

    int getrear(struct Queue* queue){
        if(isempty(queue)) return -1;
        return (queue->front+queue->size-1)%queue->capacity;
    }

    int getfront(struct Queue* queue){
        if(isempty(queue)) return -1;
        return queue->front;
    }

    bool isfull(struct Queue* queue){
        return (queue->size==queue->capacity);
    }

    bool isempty(struct Queue* queue){
        return (queue->size==0);
    }

    void eque(int x,struct Queue* queue){
        if(isfull(queue)) {
            cout<<"Queue is full.";
            return ;
        }
        int rear=getrear(queue);
        rear=(rear+1)%queue->capacity;
        queue->arr[rear]=x;
        queue->size++;
    }

    void deque(int x,struct Queue* queue){
        if(isempty(queue)) {
            cout<<"Queue is empty.";
            return ;
        }
        queue->front=(queue->front+1)%queue->capacity;
        queue->size--;
    }


int main(){
    struct Queue* q = createQueue(1000);
    // q = new Queue(10);
    // eque(10);
    // eque(20);
    // eque(30);
    // eque(40);


    return 0;
}
