
void B(){
    w(t){
        int n; sd(n);
        int a[n+1];
        int b[n+1];
        int s1=0;
        int s2=0;
        int f=0;
        for(int i=1 ; i<=n/2 ; i++){
            a[i] = 2*i;
            s1+=a[i];
        }
        for(int i=1 ; i<=n/2 ; i++){
            if(i==n/2){
                b[i]=(s1-s2);
                if(b[i]%2==0){
                    f=1;
                    break;
                }
            }
            else{
                b[i] = 2*i-1;
                s2+=b[i];
            }
        }
        if(f){
            cout <<"NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(int i=1 ; i<=n/2 ; i++)
                cout << a[i] << " ";
            for(int i=1 ; i<=n/2 ; i++)
                cout << b[i] <<" ";
                cout << endl;
        }
    }
}
