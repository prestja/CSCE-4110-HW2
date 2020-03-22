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
	ofstream fout;
	fout.open("times/times.txt");
	for(int i=1;i<argc;i++){
		string filename(argv[i]);
		fout<<"times for file "<<filename<<endl;
		matrixs m;
		cout<<"Run number "<<i<<endl;
		cout<<"Multipling matrix "<<argv[i]<<endl;
		m.load(argv[i], argv[i]);
		
		auto start= high_resolution_clock::now();
		m.basicMulti();
		auto stop= high_resolution_clock::now();
		auto duration= duration_cast<microseconds>(stop-start);
		fout<<"Normal runtime \t\t"<<duration.count()<<endl;
		
		
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
	fout.close();
	
	return 0;
}