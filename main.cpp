#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	
	ifstream in;
	map<string, int> wordcount;	//初始化map
	string word;			//檔案中的字串
	in.open("hw2_data.txt");	//讀入檔案
	
	while(in>>word){
		//檢測map中是否已經存在重複的key
		pair<map<string, int>::iterator, bool> rPair;
		rPair=wordcount.insert(pair<string, int>(word, 1));
		
		if(rPair.second==true)
			//若不存在重複的key值，則新增key並把value設為1
			wordcount.insert(pair<string, int>(word, 1));
		else
			//若已有重複的key值，則將此key的value加1
			wordcount[word]++;
		
	}
	//輸出整個map
	for(const auto& w:wordcount)
		cout<<w.first<<": "<<w.second<<endl;
	
	in.close();
	
	return 0;
}
