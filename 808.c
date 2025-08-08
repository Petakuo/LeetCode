double dfs(int a, int b, double table[200][200]){
    if(a <= 0 && b <= 0) return 0.5;
    else if(a <= 0) return 1.0;
    else if(b <= 0) return 0.0;
    if(table[a][b] > 0) return table[a][b];
    table[a][b] = (dfs(a-4, b, table)+dfs(a-3, b-1, table)+dfs(a-2, b-2, table)+dfs(a-1, b-3, table))/4.0;
    return table[a][b];
}

double soupServings(int n) {
    if(n > 4800) return 1.0;
    double table[200][200] = {0};
    return dfs((n+24)/25, (n+24)/25, table);
}
