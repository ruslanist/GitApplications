//Trapezoidal Method for evaluation of Definite Integrals for sin(x)
//Compile :- g++ -o Trapezoidal -fopenmp Trapezoidal.cpp
//Code Execution : ./Trapezoidal
//Serial Execution:- Set the number of threades to 1
//Parallel Execution:- No. of threads can be set as 2,4,6 & 8


#include<iostream>
#include<cmath>
#include <fstream>
#include <omp.h>
#include<iomanip>

using namespace std;
double f(double x)        //write the function whose definite integral is to be calcuated here
{
    double a=sin(x);
    return a;
}
int main()
{
    ofstream time;
    time.open ("times.txt"); //file for timestamp
    int n,i,th,threads;        //n is for subintervals and i is for loop
    double a,b,h,sum=0,integral,t1=0,t2=0; 
    th=omp_get_max_threads();
    cout<<"Enter the numbers of thread that you want to use : "; //define number of threads
    cin>>threads;
    if (threads>th){
        threads=th;
        cout<<"Max thread number of your system is: " << threads << " and those will be used.\n";
    }
    cout<<"Enter the limits of integration,\nInitial limit,a=";    //get the limits of integration
    cin>>a;
    cout<<"Final limit, b=";
    cin>>b;
    cout<<"Enter the no. of subintervals, n=";            //get the no. of subintervals
    cin>>n;
    t1=omp_get_wtime();
    double x[n+1],y[n+1];    
    h=(b-a)/n;                //get the width of the subintervals
    #pragma omp parallel for num_threads(threads)
    for (i=0;i<=n;i++)            
    {                    //loop to evaluate x0,...xn and y0,...yn
        x[i]=a+i*h;            //and store them in arrays
        y[i]=f(x[i]);
    }
    #pragma omp parallel for reduction(+:sum) num_threads(threads)
    for (i=1;i<n;i++)            //loop to evaluate h*(y1+...+yn-1)
    {
        sum=sum+h*y[i];
    }
    integral=h/2.0*(y[0]+y[n])+sum;        //h/2*[y0+yn+2(y1+y2+y3+...yn-1)]
    std::cout << "The value of definite integral is " << std::fixed << std::setprecision(10) << integral<<"\n";
    cout<<"Error with respect to analytical result is "<< 2-abs(integral) << endl;
    cout<<"The percentage of error is " << ((2-abs(integral))/2)*100 << "%\n";
    t2=omp_get_wtime();
    cout<<"Running time with " << threads << " threads is: " << t2-t1 << "ms\n";
    time << "Running time with " << threads << " threads is: " << t2-t1 << "ms\n";
    time.close();
    return 0;
}
