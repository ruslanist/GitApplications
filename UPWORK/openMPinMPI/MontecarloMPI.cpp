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
#include <mpi.h>                                                                

using namespace std;

double sum(double (*f)(double), int n, int myid, int proc_nums)
{
    double result=0.0, total_sum = 0;
    double PI = 3.14159265358979323846;
    
    
    // for(int i=0;i<n;i++)                        
    for(int i = myid + 1 ; (i <= n) ; i += proc_nums)                           //loop to seperate "darts" for integral obtain.  
    {
        double r = fmod((double)rand(),PI);
        result+=f(r);
    }
    
    MPI_Allreduce(&result, &total_sum, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
    
    return PI*total_sum/n;
}

double f(double x)      //write the function whose definite integral is to be calcuated here
{
    double a=sin(x);
    return a;
}

int main(int argc, char **argv)                                                 
{
    MPI_Init(&argc, &argv);                                                     
    
    
    double value, t1, t2;
    int n, myid, proc_nums;
    MPI_Comm_size(MPI_COMM_WORLD,&proc_nums);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);                                        
    
    if(myid==0) {                                                               
  
        cout<<"Give the number of sampling points: ";
        cin>> n;
        
        t1 = MPI_Wtime();                                                       
    }                                                                           
    
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    value=sum(f,n, myid, proc_nums);
    
    if(myid==0) {                                                               
        
       t2 = MPI_Wtime();                                                        
        std::cout << "The value of definite integral is " << std::fixed << std::setprecision(10) << value<<"\n";
        cout<<"Error with respect to analytical result is "<< abs(2-abs(value)) << endl;
        cout<<"The percentage of error is " << (abs(2-abs(value))/2)*100 << "%\n";
        cout<<"Running time with " << proc_nums << " threads is: " << t2-t1 << "ms\n";
       
    }                                                                           
    
    MPI_Finalize();                                                             
    
    return 0;
}