#include <bits/stdc++.h>

using namespace std;


int main() {
  int T, k = 1;

  cin >> T;

  while (T--) {
    int N;
	cout << endl;
    cin >> N;
    int i, matrix[N][N];
    
	
	bool rowHasDups = false;
	bool colHasDups = false;
	
	
	for (int x = 0; x < N; x++) {
	    for (int y = 0; y < N; y++) {
	        cin >> matrix[x][y];
	    }
	}
	
	int rowRepeatCount = 0, colRepeatCount = 0,
	diagonalSum = 0;
	
	for (int i = 0; i < N; i++) {
		rowHasDups = colHasDups = false;
		std::multiset<int>row;
	    std::multiset<int>col;
		
		for (int j = 0; j <  N; j++) {
		    
			if (i == j) {
				diagonalSum += matrix[i][j];
			}
			int rowc = matrix[i][j];
			int colc = matrix[j][i];
			
			
			if (row.count(rowc)) {
				rowHasDups = true;
			}
			
			if (col.count(colc)) {
				colHasDups = true;
			}
			
			row.insert(rowc);
			col.insert(colc);
		}
		
		if (rowHasDups) {
			rowRepeatCount++;
		}
		
		if (colHasDups) {
			colRepeatCount++;
		}
	}

    cout << "Case #" << k << ": " << diagonalSum << " " 
    << rowRepeatCount << " " << colRepeatCount << endl;
    
    //k is for printing the Case Number
    k++;
  }

  return 0;
}