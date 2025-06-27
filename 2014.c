typedef struct{
    char* str;
    int len;
} QNode;

typedef struct{
    QNode* data;
    int front, rear, size, capacity;
} Queue;

Queue* CreatQ(int capacity){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (QNode*)malloc(capacity*sizeof(QNode));
    q->front = 0;
    q->rear = capacity-1;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

void enQ(Queue* q, char* str, int len){
    if(q->size == q->capacity) return;
    q->rear = (q->rear+1)%q->capacity;
    q->size++;
    q->data[q->rear].str = strdup(str);
    q->data[q->rear].len = len;
}

QNode deQ(Queue* q){
    if(q->size == 0){
        QNode empty = {"", 0};
        return empty;
    }
    QNode ret = q->data[q->front];
    q->size--;
    q->front = (q->front+1)%q->capacity;
    return ret;
}

bool isRepSub(char* s, char* t, int k){
    int idx = 0, matched = 0, tlen = strlen(t);
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == t[idx]){
            idx++;
            if(idx == tlen){
                matched++;
                idx = 0;
                if(matched == k) return 1;
            }
        }
    }
    return 0;
}

char* longestSubsequenceRepeatedK(char* s, int k) {
    int freq[26] = {0};
    for(int i = 0; s[i] != '\0'; i++){
        freq[s[i]-'a']++;
    }
    char candidates[26];
    int candidatesSize = 0;
    for(int i = 25; i >= 0; i--){
        if(freq[i] >= k) candidates[candidatesSize++] = 'a'+i;
    }
    Queue* q = CreatQ(10000);
    for(int i = 0; i < candidatesSize; i++){
        char str[2] = {candidates[i], '\0'};
        enQ(q, str, 1);
    }
    char* ans = strdup("");
    while(q->size > 0){
        QNode cur = deQ(q);
        if(cur.len > strlen(ans)){
            free(ans);
            ans = strdup(cur.str);
        }
        for(int i = 0; i < candidatesSize; i++){
            char* next = (char*)malloc((cur.len+2)*sizeof(char));
            strcpy(next, cur.str);
            next[cur.len] = candidates[i];
            next[cur.len+1] = '\0';
            if(isRepSub(s, next, k)) enQ(q, next, cur.len+1);
            else free(next);
        }
        free(cur.str);
    }
    return ans;
}
