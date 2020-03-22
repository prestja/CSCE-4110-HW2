//
//  Makematrix.cpp
//
//
//  Created by Bhowmick, Sanjukta on 1/20/20.
//
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <math.h>
using namespace std;

int main(int argc, char *argv[])
{
    if ( argc < 4) { cout << "Foure inputs needed:\\ 1: Number of Rows; 2: Number of Columns; \\ 3: Sparsity (between 0-100) \\ 4: Name of output files \n";}
    
    
    int rows=atoi(argv[1]);
    int cols=atoi(argv[2]);
    int sparsity=atoi(argv[3]);
    //name of matrix is given in argv[4];
    
if(sparsity>100){sparsity=100;}

    //Get the numbers
    srand(time(NULL));
    int k=0;
    int zs=ceil(rows*cols*(double)sparsity/100.00); //nmber of zeros.
    
    int A[rows][cols];
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
        
            int x=rand()%2;
            if(x==0 && k<zs) //set vale to zero
            { A[i][j]=0;
                k++;
            }
            else //or to non-zero
            { A[i][j]=rand()%(100+1);}
        }
    }//end of for
   
    

    ofstream output;
    output.open(argv[4]);
    output << rows << " " <<cols <<"\n";
    for (int k=0; k<rows; k++)
    {
        for (int l=0; l<cols; l++)
        {
            output << A[k][l] << " "; // behaves like cout - cout is also a stream
        }
        output << "\n" << endl;
    }
    output.close();
    
    
    return 0;
    
    
}
