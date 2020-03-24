/*
	4110 Assignment 2
	By Richard Butler

*/


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;
#include "matrixs.h"


int main(int argc, char *argv[]){
	//cout<<argv[1]<<"\t"<<argv[2]<<endl;
	ofstream fout2;
	//this file stores reports of the time results
	fout2.open("times/times.txt");
	ofstream fout;
	fout.open("times/timesForEachExperiment.txt");
	//takes any numbers of arguments
	//the arguments are the names of the matrix.txt files
	for(int j=0;j<3; j++){
		fout2<<"Run number "<<j<<endl;
		auto start= high_resolution_clock::now();
		for(int i=1;i<argc;i++){
			string filename(argv[i]);
			if(j==0){
				matrixs m;
				m.load(argv[i], argv[i]);
				m.SparseMulti();
			}
			else if(j==1){
				matrixs m;
				m.loads(argv[i], argv[i]);
				
			}
			else{
			
			
				fout<<"times for file "<<filename<<endl;
				matrixs m;
				cout<<"Run number "<<i<<endl;
				cout<<"Multipling matrix "<<argv[i]<<endl;
				m.load(argv[i], argv[i]);
				//times the matrix multiplaction 
				auto start3= high_resolution_clock::now();
				m.basicMulti();
				auto stop3= high_resolution_clock::now();
				auto duration3= duration_cast<microseconds>(stop3-start3);
				fout<<"Normal runtime \t\t"<<duration3.count()<<endl;
				//records the time to the file
				
				auto start1= high_resolution_clock::now();
				m.StrassenMulti();
				auto stop1= high_resolution_clock::now();
				auto duration1= duration_cast<microseconds>(stop1-start1);
				fout<<"Strassen runtime \t"<<duration1.count()<<endl;
				
				
				auto start2= high_resolution_clock::now();
				m.SparseMulti();
				auto stop2= high_resolution_clock::now();
				auto duration2= duration_cast<microseconds>(stop2-start2);
				fout<<"Sparse runtime \t\t"<<duration2.count()<<endl;
				fout<<endl<<endl;
			}
		}
		auto stop= high_resolution_clock::now();
		auto duration= duration_cast<microseconds>(stop-start);
		fout2<<"runtime \t"<<duration.count()<<endl;
		fout2<<endl;
	}
	fout2.close();
	fout.close();
	return 0;
}