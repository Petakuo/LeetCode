bool canChange(char* start, char* target) {
    int ptrs = -1, ptrt = -1;
    int len = strlen(start);
    while(ptrs < len || ptrt < len){
        ptrs++;
        ptrt++;
        while(start[ptrs] == '_'){
            ptrs++;
        }
        while(target[ptrt] == '_'){
            ptrt++;
        }
        if((start[ptrs] != target[ptrt]) || (start[ptrs] == 'L' && ptrs < ptrt) || (start[ptrs] == 'R' && ptrs > ptrt)) break;
    }
    return ptrs == len && ptrt == len;
}
