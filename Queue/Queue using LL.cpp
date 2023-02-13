#include <stdio.h>
#include <stdlib.h>
struct QNode {
    int key;
    struct QNode* next;
};
struct Queue {
    struct QNode *front, *rear;
};
struct QNode* newNode(int k)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}
struct Queue* createQueue()
{
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
void enQueue(struct Queue* q, int k)
{
    struct QNode* temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return;
    struct QNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
}
int main()
{
    struct Queue* q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 50);
    deQueue(q);
    printf("Queue Front : %d \n", ((q->front != NULL) ? (q->front)->key : -1));
    printf("Queue Rear : %d", ((q->rear != NULL) ? (q->rear)->key : -1));
    return 0;
}