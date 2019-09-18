
#include <stdlib.h>

typedef struct node{
    int x;
    int h;
}node;

typedef struct heap{
    int size;
    node* head;
}heap;

void swap(node* p, node* q){
    node temp;
    temp.x = p->x;
    temp.h = p->h;
    p->x = q->x;
    p->h = q->h;
    q->x = temp.x;
    q->h = temp.h;
}

int cmp(node* p, node* q){

    if (p->h < q->h) return true;

    /***
    if (p->x < q->x){
        return true;
    }else if(p->x == q->x){
        if (p->h < q->h){
            return true;
        }
    }
    ***/

    return false;
}

int parent(int i){
    return i>>1;
}

int left(int i){
    return i*2;
}

int right(int i){
    return i*2+1;
}

void heapInit(heap* hq, int size){
    hq->head = (node*)malloc(sizeof(node)*size);
    hq->size = 0;
}

void heapInsert(heap* hq, int x, int h){
    int i = ++hq->size, nP = 0;

    hq->head[i].x = x;
    hq->head[i].h = h;

    while(i>1){
        nP = parent(i);
        if(cmp(hq->head+i, hq->head+nP)){
            swap(hq->head+i, hq->head+nP);
            i = nP;
        }else{
            break;
        }
    }
}

node* heapTop(heap* hq){
    return &hq->head[1];
}

node* heapPop(heap* hq){
    if (hq->size == 0) return NULL;
    swap(hq->head+1, hq->head+hq->size);
    hq->size--;
    heapify(hq, 1);
    return &hq->head[hq->size];
}

void heapify(heap* hq, int i){
    int l = left(i);
    int r = right(i);
    int minimum = 0;
    if (l <= hq->size && cmp(hq->head+l, hq->head+i)){
        minimum = l;
    }else{
        minimum = i;
    }
    if (r <= hq->size && cmp(hq->head+r, hq->head+minimum)){
        minimum = r;
    }
    if (minimum != i){
        swap(hq->head+i, hq->head+minimum);
        heapify(hq, minimum);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int** returnArray = (int**)malloc(sizeof(int*)*(2*buildingsSize));
    heap* hq = (heap*)malloc(sizeof(heap));
    heapInit(hq, buildingsSize+1);

    int i = 0, temp = 0, height = 0;
    node* top;

    while(i < buildingsSize || hq->size!=0){
        top = heapTop(hq);
        if (hq->size == 0 || (i < buildingsSize && buildings[i][0] <= -top->x)){
            temp = buildings[i][0];
            while (i < buildingsSize && buildings[i][0] == temp){
                heapInsert(hq, -buildings[i][1], -buildings[i][2]);
                i++;
            }
        }else{
            temp = -top->x;
            while (hq->size > 0 && -heapTop(hq)->x <= temp){
                //node* check = heapTop(hq);
                heapPop(hq);
            }
        }
        height = hq->size == 0? 0:-heapTop(hq)->h;
        if (*returnSize == 0 || height != returnArray[(*returnSize)-1][1]){
            returnArray[*returnSize] = (int*)malloc(sizeof(int)*2);
            returnArray[*returnSize][0] = temp;
            returnArray[*returnSize][1] = height;
            (*returnSize)++;
        }
    }

    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for(int j = 0; j < *returnSize; j++){
        (*returnColumnSizes)[j] = 2;
    }


    return returnArray;
}