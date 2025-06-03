#include <iostream>  
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void KMER_FINDER(string seqA, string seqB);
	
int main() {

	string seqA = {"TATACGTAGACTACGTAGACCACGACGTGACTTGTACGTAGACGTAGATACGTAGACC"};
	string seqB = {"ACGACGTGACGACGTGACTTGACGACGTGACTTGAACGACGTGACTTGCTACTTACGTGACTGAC"};
	
	KMER_FINDER(seqA,seqB); // my function 
		
	return 0;
}


void KMER_FINDER(string seqA, string seqB) {
	
	//prepare seq
	vector<string> seq;
	seq.push_back(seqA);
	seq.push_back(seqB);
	
	//get size of seq
	vector<int> lt;
	for(const string& st:seq){
		lt.push_back(st.size());
	}
	
	//get index of min
	int idx;
	auto min_ = min_element(lt.begin(), lt.end());	
	idx=distance(lt.begin(),min_);
	
	
	//get short sequence
	string seq_small = seq.at(idx);
	
	//get index of the long sequence
	int idx_long_seq;
	if (idx == 0){
		idx_long_seq = 1;
	} else {
		idx_long_seq = 0;
	}
	string seq_long = seq.at(idx_long_seq);


	// find the longest common string between two seqeunces
	int pos;
	string kmer;
	vector<string> kmer_vec;
	vector<int> kmer_size;
	for(int k=3;k<seq_small.size();++k){
		int kmer_count=seq.at(idx).size()-k+1;
		for(int j=0;j<kmer_count;++j){
		
			kmer = seq_small.substr(j,k);
			pos = seq_long.find(kmer);
		
			if (pos < seq_long.size()){
				kmer_vec.push_back(kmer);
				kmer_size.push_back(k);
			}
		}
	}
	
	
	// report 	
	auto kmer_final = max_element(kmer_size.begin(),kmer_size.end());
	int kmer_max = distance(kmer_size.begin(),kmer_final);
	
	cout << "The largest common kmers berween " << seq_long << " & " << seq_small << " is " << endl;
	for(int m = kmer_max;m<kmer_size.size();++m){
			cout << kmer_vec.at(m) << " with the kmer size at " << kmer_size.at(m) << endl; 
	}
		
}
