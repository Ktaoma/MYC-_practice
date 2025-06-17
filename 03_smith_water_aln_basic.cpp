#include <iostream>  
#include <string>
#include <map>
using namespace std;

//Goal: Implement a basic version of the Smith-Waterman algorithm to find the best local alignment between two DNA sequences.
//Match: +2, Mismatch: -1, Gap penalty: -2

int score (vector<vector<int>> H, int match, int i, int j, string type_ = "score"){
	
	int left = H[i-1][j] - 2;
	int top = H[i][j-1] - 2;
	int diag = H[i-1][j-1] + match;
		
	if (type_ == "score"){

		int score1 = max(top,left);
		int score2 = max(score1,diag);
		H[i][j] = max(0,score2);
		return H[i][j];

	} else{
		
	
		if(diag > max(top,left)){
			return 1;
		} else if (left > max(top,diag)){
			return -1;
		} else if (top > max(left,diag)) {
			return -2;
		} else if (0 <= max(left,max(diag,top))){
			return 99;
		} else {
			return 0;
		}
	}
}



int main(){
	
	string ref_1 = "AGCT", ref_2 = " ", ref_ = ref_2+ref_1;
	string query_1 = "AGCTAC",query_2 = " ", query_ = query_2 + query_1;
	
	//1. init matrix
	vector<vector<int>> mat(ref_.size(),vector<int>(query_.size(),0)); 
	
	//2. fill matrix 
	int gap_i = 0;
	int gap_j = 0;
	
	for(int i=0;i<ref_.size();++i){
		
		for(int j=0;j<query_.size();++j){
			 
			
			if (i == 0 && j==0 ){
				
				mat[i][j] = 0;
				cout << mat[i][j] << " ";
				
			}else if(i == 0 && j > 0){
				
				gap_i += -2;
				mat[i][j] = gap_i;	
				cout << mat[i][j] << " ";
					
			} else if (i > 0 && j == 0) {
				
				gap_j += -2;
				mat[i][j] = gap_j;
				cout << mat[i][j] << " ";
				
			} else {
				
				mat[i][j] = (ref_.at(i) == query_.at(j)) ? 2 : -1;
				cout << score(mat,mat[i][j],i,j,"score") << " ";
			}
		}
		cout << endl;
	}
	
	// 3. track back
	//3.1 find maximum value
	int qs = query_.size();
	int rs = ref_.size();
	vector<int> score_vec;
	
	for(int h = 1;h <= qs;++h ){
		
		int SC=score(mat,mat[rs-1][h],rs-1,h,"score");
		
		score_vec.push_back(SC);		
		
	}
	
	int maxValue = *max_element(score_vec.begin(),score_vec.end());
	int cnt = 1;
	vector<int> max_idx;
	
	for (int m:score_vec){
		if(m == maxValue){
			cout << cnt << endl;
			max_idx.push_back(cnt);	
		}
		++cnt;
	}
	
	// 3.2 track
	map<int,int> path;
	int n = max_idx.at(0);
	int end_pos_row = rs-1;
	int end_pos_col = n;
	
	//3.3 move back to start
	int score_diag;
	int score_top;
	int score_left;
	int end_ = 0;
	int pos_=score(mat,mat[end_pos_row][end_pos_col],end_pos_row,end_pos_col,"trackback");
	cout << end_pos_row << endl;
	cout << end_pos_col << endl;
	cout << "->>>>>" << mat[end_pos_row][end_pos_col] << endl;
	path[end_pos_row] = end_pos_col;
	
	--end_pos_row;
	--end_pos_col;
	
	while(end_ < 1){
		
		if (pos_ == 1){
			
			//diag
			if(end_pos_row == 0 && end_pos_col == 0){
				break;
			}
			
			cout << "diag" << endl;
			cout << end_pos_row << endl;
			cout << end_pos_col<< endl;
						
			path[end_pos_row] = end_pos_col;
			
			int tb = (ref_.at(end_pos_row) == query_.at(end_pos_col)) ? 2 : -1;
			int pos_=score(mat,tb,end_pos_row,end_pos_col,"trackback");
			
			if(pos_ == 99){
				break;
			}
			
			cout << pos_<<endl;
			cout << "->>>>>" << mat[end_pos_row][end_pos_col] << endl; 
			
			--end_pos_row;
			--end_pos_col;
			
			
		} else {
			cout << "placeholder for mismatch" << endl;
		} 
	}
	
	
	// 3.4 Visualization
	vector<int> keys;
	vector<int> vals;
	for (auto i : path){
		keys.push_back(i.first);
		vals.push_back(i.second);
	}
	
	for(auto i: keys){
		cout << ref_1.at(i-1) << " ";
	}
	
	cout << endl;
	
	for(auto i: keys){
		cout << "*" << " ";
	}
	
	cout << endl;
	
	for(auto i: vals){
		cout << query_1.at(i-1) << " ";
	}
	
			
}












