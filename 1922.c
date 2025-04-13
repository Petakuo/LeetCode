#define MOD 1000000007

int countGoodNumbers(long long n) {
    long long even = (n+1)/2, odd = n/2;
    long long evenPow = 1, oddPow = 1, evenBase = 5, oddBase = 4;
    while(even){
        if((even&1) == 1) evenPow = (evenPow*evenBase)%MOD;
        evenBase = (evenBase*evenBase)%MOD;
        even >>= 1;
    }
    while(odd){
        if((odd&1) == 1) oddPow = (oddPow*oddBase)%MOD;
        oddBase = (oddBase*oddBase)%MOD;
        odd >>= 1;
    }
    return (evenPow*oddPow)%MOD;
}
