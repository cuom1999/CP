
// 3^n
    FOR (i,0,(1<<17)-1){
        b[i]=a[0]*1ll*a[i]%K;
        for (int j=i; j; j=(j-1)&i){
            b[i]=(b[i]+a[j]*1ll*a[j^i])%K;
        }
    }

