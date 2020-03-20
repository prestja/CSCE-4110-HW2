//
//  create_input.cpp
//  
//
//  Created by Bhowmick, Sanjukta on 1/20/20.
//
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    if ( argc < 2) { cout << "One inputs needed: the number of entries \n";
        return 0;
    }
    int n=atoi(argv[1]);

    vector<int> myarray;
    myarray.clear();
    for (int i=0;i<n;i++) {
        myarray.push_back(i);
    }
    
    std::random_shuffle ( myarray.begin(), myarray.end() );
    
     ofstream myfile;
    myfile.open ("input.txt");
          for (int i=0;i<n;i++) {
            myfile << myarray[i] <<"\n";
         }
    myfile.close();
    return 0;
    
    
}
