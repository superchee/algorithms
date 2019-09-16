
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
    if (p->x < q->x){
        return true;
    }else if(p->x == q->x){
        if (p->h < q->h){
            return true;
        }
    }
    return false;
}

int parent(int i){
    return i>>1;
}

void heapInit(heap* hq, int size){
    hq->head = (node*)malloc(sizeof(node)*size);
    hq->size = 0;
}

void heapInsert(heap* hq, int x, int h){
    int i = hq->size, nP = 0;

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

    hq->size++;
    
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
    heapInit(hq, buildingsSize*2);

    for (int i = 0; i < buildingsSize; i ++){
        heapInsert(hq, buildings[i][0], -buildings[i][1]);
        heapInsert(hq, buildings[i][0], buildings[i][2]);
    }

    while (hq->size > 0){
        
    }

    

}