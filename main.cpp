#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	
	ifstream in;
	map<string, int> wordcount;
	string word;
	in.open("hw2_data.txt");
	
	while(in>>word){
		pair<map<string, int>::iterator, bool> rPair;
		rPair=wordcount.insert(pair<string, int>(word, 1));
		
		if(rPair.second==true)
			wordcount.insert(pair<string, int>(word, 1));
		else
			wordcount[word]++;
		
	}
	
	for(const auto& w:wordcount)
		cout<<w.first<<": "<<w.second<<endl;
	
	in.close();
	
	return 0;
}
