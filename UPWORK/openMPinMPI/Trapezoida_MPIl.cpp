#include<iostream>
#include<cmath>
#include <fstream>
#include <mpi.h>                                                                                                                         
#include<iomanip> 

using namespace std;
double f(double x)        //write the function whose definite integral is to be calcuated here
{
    double a=sin(x);
    return a;
}
int main(int argc, char **argv)                                                 
{
    MPI_Init(&argc, &argv);                                                     
    int myid;                                                                   
    int n,i,proc_nums;        //n is for subintervals and i is for loop
    double a,b,h,sum=0,integral,t1=0,t2=0, total_sum = 0;
    MPI_Comm_size(MPI_COMM_WORLD,&proc_nums);                                          
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);                                        
    
    if(myid==0) {                                                               
        cout<<"Enter the limits of integration,\nInitial limit,a=";    //get the limits of integration
        cin>>a;
        cout<<"Final limit, b=";
        cin>>b;
        cout<<"Enter the no. of subintervals, n=";            //get the no. of subintervals
        cin>>n;
        t1 = MPI_Wtime();                                                       
    }                                                                           
    
    MPI_Bcast(&a, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(&b, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    h = (b - a) / n;                //get the width of the subintervals

    for(int i = myid + 1 ; (i <= n) ; i += proc_nums)
    {
        sum += h * f(a + i * h);
    }

    // Resetting results from all processes and adding
    MPI_Reduce(&sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(myid==0) {      
        integral = h / 2.0 * (f(a + 0 * h) + f(a + n * h)) + total_sum;

        cout << "The value of definite integral is " << std::fixed << std::setprecision(10) << integral<<"\n";
        cout<<"Error with respect to analytical result is "<< 2-abs(integral) << endl;
        cout<<"The percentage of error is " << ((2-abs(integral))/2)*100 << "%\n";
        t2 = MPI_Wtime();                                                            
        cout<<"Running time with " << proc_nums << " proc_nums is: " << t2-t1 << "ms\n";
    }                                                                           
    
    MPI_Finalize();                                                             
    
    return 0;
    
}
