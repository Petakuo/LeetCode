int cmp(const void* a, const void* b){
    return (*(int**)a)[0]-(*(int**)b)[0];
}

typedef struct{
    int data[100001];
    int size;
} minHeap;

void heapInsert(minHeap* h, int val){
    int curIdx = h->size++;
    while(curIdx > 0){
        if(h->data[(curIdx-1)/2] > val){
            h->data[curIdx] = h->data[(curIdx-1)/2];
            curIdx = (curIdx-1)/2;
        }
        else break;
    }
    h->data[curIdx] = val;
}

int heapPop(minHeap* h){
    int ans = h->data[0];
    int temp = h->data[--h->size];
    int curIdx = 0;
    while(curIdx*2+1 < h->size){
        int leftIdx = curIdx*2+1, rightIdx = leftIdx+1;
        int smaller = rightIdx < h->size && h->data[rightIdx] < h->data[leftIdx] ? rightIdx : leftIdx;
        if(h->data[smaller] < temp){
            h->data[curIdx] = h->data[smaller];
            curIdx = smaller;
        }
        else break;
    }
    h->data[curIdx] = temp;
    return ans;
}

int heapTop(minHeap* h){
    return h->data[0];
}

int maxEvents(int** events, int eventsSize, int* eventsColSize) {
    qsort(events, eventsSize, sizeof(int*), cmp);
    minHeap h = {.size = 0};
    int lastDay = 0;
    for(int i = 0; i < eventsSize; i++){
        lastDay = events[i][1] > lastDay ? events[i][1] : lastDay;
    }
    int idx = 0, ans = 0;
    for(int day = 1; day <= lastDay; day++){
        while(idx < eventsSize && events[idx][0] == day){
            heapInsert(&h, events[idx][1]);
            idx++;
        }
        while(h.size > 0 && heapTop(&h) < day){
            heapPop(&h);
        }
        if(h.size > 0){
            heapPop(&h);
            ans++;
        }
    }
    return ans;
}
