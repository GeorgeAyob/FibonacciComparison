// George Ayob - Project 1 - CSC 382 - 2/6/2020
#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;

int FiboR ( int n) // array of size n
{      if (n==0 || n==1)
    return (n);
else return (FiboR (n-1) + FiboR(n-2));
}

int FiboNR ( int n) // array of size n
{
    int Max = 46;
    int F[Max];
    F[0]=0; F[1]=1;
    for (int i =2; i <=n; i++)
    {
        F[i] = F[i-1] + F[i-2];
    }
    return (F[n]);
}

int main()
{
    clock_t start;
    double durationA,durationB;
    long num;
    int n[10]= {1,5,10,15,20,25,30,35,40,45};
    
    cout <<"Integer" <<setw(20)<< "FiboR (seconds)" <<setw(20)<< "\tFiboNR (seconds) " <<setw(20)<< "Fibo-value"<<endl;
    
    for (int i=0; i<=9; i++)
    {
        start = clock();                  // start clock
        num = FiboR(n[i]);                  // call function
        durationA = (clock()-start)/ (long double)CLOCKS_PER_SEC; // change to seconds and subtract time take from start and end of clock

        start = clock();        //restart clock
        num = FiboNR(n[i]);
        durationB = (clock()-start)/ (long double)CLOCKS_PER_SEC;
        
        
        cout<<fixed<<setprecision(8);
        cout<<n[i]<<setw(20)<<durationA<<setw(20)<<durationB<<setw(20)<<num<<endl;
    }
    
}

/*
 
 Output:
 
 Integer     FiboR (seconds)      FiboNR (seconds)           Fibo-value
 1          0.00000300          0.00000100                   1
 5          0.00000000          0.00000100                   5
 10          0.00000200          0.00000200                  55
 15          0.00001000          0.00000100                 610
 20          0.00007300          0.00000100                6765
 25          0.00087100          0.00000200               75025
 30          0.00939500          0.00000100              832040
 35          0.08295700          0.00000100             9227465
 40          0.86562800          0.00000200           102334155
 45          9.58540800          0.00000200          1134903170
 Program ended with exit code: 0: 0
 
 */
