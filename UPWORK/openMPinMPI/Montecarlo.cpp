//MonteCarlo Method for the evaluation of Definite Integrals for sin(x)
//Compile :- g++ -o Montecarlo -fopenmp Montecarlo.cpp
//Code Execution: ./Montecarlo
//Serial Execution:- Set the number of threades to 1
//Parallel Execution:- No. of threads can be set as 2,4,6 & 8


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <cmath> 
#include <omp.h>

using namespace std;

double sum(double (*f)(double), int n, int th)
{
    double result=0.0;
    double PI = 3.14159265358979323846;
    
    #pragma omp parallel for reduction(+:result) num_threads(th)
    for(int i=0;i<n;i++)                        //loop to seperate "darts" for integral obtain.
    {
        double r = fmod((double)rand(),PI);
        result+=f(r);
    }
    return PI*result/n;
}

double f(double x)      //write the function whose definite integral is to be calcuated here
{
    double a=sin(x);
    return a;
}

int main(void)
{
    ofstream time;
    time.open ("time.txt"); //file for timestamp
    double value, t1, t2;
    int n, threads, thr;
    cout<<"Enter the numbers of thread that you want to use : "; //define number of threads
    cin>>threads;
    thr=omp_get_max_threads();
    if (threads>thr){
        threads=thr;
        cout<<"Max thread number of your system is: " << threads << " and those will be used.\n";
    }
    cout<<"Give the number of sampling points: ";
    cin>> n;
    t1=omp_get_wtime();
    value=sum(f,n,threads);
    t2=omp_get_wtime();
    std::cout << "The value of definite integral is " << std::fixed << std::setprecision(10) << value<<"\n";
    cout<<"Error with respect to analytical result is "<< abs(2-abs(value)) << endl;
    cout<<"The percentage of error is " << (abs(2-abs(value))/2)*100 << "%\n";
    cout<<"Running time with " << threads << " threads is: " << t2-t1 << "ms\n";
    time << "Monte Carlo running time with " << threads << " threads is: " << t2-t1 << "ms\n";
    time.close();
    return 0;
}
