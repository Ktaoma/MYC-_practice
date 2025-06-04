#include <iostream>  
#include <string>
using namespace std;

//Given a DNA sequence, return its reverse complement.

int main(){
	
	string seq = "ACGACGTGACGACGTGACTTGACGACGTGACTTGAACGACGTGACTTGCTACTTACGTGACTGAC";
	string rev;
	
	for(int i= seq.size()-1;i>=0;--i){
		
		char base = seq.at(i);	
		
		if(base == 'A'){
			rev += 'T';
		} else if(base == 'T'){
			rev += 'A';
		} else if(base == 'C'){
			rev += 'G';
		} else {
			rev += 'C';
			
		}
	}	
	
	cout << rev ;
	
	
}
