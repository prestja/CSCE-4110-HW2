vector< vector<int> > strassen(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, unsigned int tam);
unsigned int nextPowerOfTwo(int n);
void strassenR(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int tam);
void sum(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int tam);
void subtract(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int tam);



class matrixs{
	private:
		vector< vector<int> > a;
		vector< vector<int> > b;
		vector< vector<int> > result;
		int size;
	public:
		void load(string AName, string BName);
		void prt();
		void basicMulti();
		void StrassenMulti();
		void SparseMulti();

};