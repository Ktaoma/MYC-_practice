#include <iostream>  
#include <string>
using namespace std;


//Problem 4: Hamming Distance — Given two DNA sequences of equal length, count the number of positions where they differ (i.e., point mutations).


int main(){
	
	string ref = "ACGACGTGACGACGTGACTTGACGACGTGACTTGAACGACGTGACTTGCTACTTACGTGACTGAC";
	string target = "ACGACGTGACGACATGACATGCCGACGTGACTTGAACGACGTGACTTGCTACTTACGTGACTGAC";
	
	int DNA_size = ref.size();
	int cnt = 0;
	for(int i=0;i<DNA_size;++i){
		
		cnt += 1-(ref[i] == target[i]);
		
	}
	
	cout << "number of mutation between ref and target is: " << cnt;
	
}
