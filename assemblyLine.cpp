#include <bits/stdc++.h> 
using namespace std; 
#define NUM_LINE 2  
#define NUM_STATION 4  
  

void printStation(int l, int r[]){
    int i = l;
    cout<<"linia"<<i<<" "<<"estacion"<<NUM_STATION<<endl;

    for (int j = NUM_STATION-1; j > 0; j--){
        i = r[j];
        cout<<"linia"<<i<<" "<<"estacion"<<j<<endl;
    }
    
}

int carAssembly(int a[][NUM_STATION], int t[][NUM_STATION-1], int *e, int *x){  
    int T1[NUM_STATION], T2[NUM_STATION], R1[NUM_STATION],R2[NUM_STATION], i;  
  
    T1[0] = e[0] + a[0][0];  
    T2[0] = e[1] + a[1][0];  
    
    for (i = 1; i < NUM_STATION; i++)  
    {  
        if(T1[i-1]+a[0][i] <= T2[i-1]+t[1][i-1]+a[0][i]){
            T1[i]=T1[i-1]+a[0][i];
            R1[i]=1;
        }else{
            T1[i]=T2[i-1]+t[1][i-1]+a[0][i];
            R1[i]=2;
        }

        if(T2[i-1]+a[1][i] <= T1[i-1]+t[0][i-1]+a[1][i]){
            T2[i]= T2[i-1]+a[1][i];
            R2[i]=2;
        }else{
            T2[i]= T1[i-1]+t[0][i-1]+a[1][i];
            R2[i]=1;
        } 
    }

    /*for (int e = 1; e < NUM_STATION; e++)
    {   
        //cout<<T1[e]<<" ";
        cout<<R1[e]<<" ";
    }
    cout<<endl;
    for (int e = 1; e <= NUM_STATION; e++)
    {   
        //cout<<T2[e]<<" ";
        cout<<R2[e]<<" ";
    }*/
    int l;

    if(T1[NUM_STATION-1]+x[0]<=T2[NUM_STATION-1]+x[1]){
        l=1;
        printStation(l,R1);
        return T1[NUM_STATION-1]+x[0];
    }else{
        l=2;
        printStation(l,R2);
        return T2[NUM_STATION - 1] + x[1];
    }

}  
  
int main(){  
    int a[][NUM_STATION] = {{4, 5, 3, 2},  
                            {2, 10, 1, 4}};  
    int t[][NUM_STATION-1] = {{7, 4, 5},  
                            {9, 2, 8}};  
    int e[] = {10, 12}, x[] = {18, 7};  
    
    cout << carAssembly(a, t, e, x);  
  
    return 0;  
} 