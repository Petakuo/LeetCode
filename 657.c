bool judgeCircle(char* moves) {
    int len = strlen(moves);
    int hor = 0, ver = 0;
    for(int i = 0; i < len; i++){
        if(moves[i] == 'U') ver++;
        else if(moves[i] == 'D') ver--;
        else if(moves[i] == 'R') hor++;
        else if(movesa[i] == 'L') hor--;
    }
    return (hor == 0) & (ver == 0);
}
