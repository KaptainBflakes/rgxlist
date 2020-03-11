#include <filesystem>
#include <iostream>
#include <string>
//requires std:c++17 to compile. NOTE IF YOU WANT TO MAKE A LIST FROM FILE EXTENSION, USE extlist! THIS DOES NOT HANDLE EXTENSION DATA!
using namespace std;
using namespace std::filesystem;
bool contains(string name,string reg);
int main(int argc, char ** argv){
	//argv[1] gives the regex string. argv[2] is the input directory. input is assumed local unless given. use '>' to send output to a file
	string dir=".\\";//If on linux, change this shit to a "./"
	if(argc==3){
		dir=argv[2];
	}
	string out="";string reg=argv[1];
	for(auto& entry: directory_iterator(dir)){
		if(entry.path().has_extension()){
			if(contains(entry.path().stem().string(),reg)){
				out+=entry.path().string();out+="\n";
			}
		}
	}
	cout<<out;
	return 0;
}
bool contains(string name, string reg){//simple regex function
	for(int i=0;i<name.size()-reg.size();i++){
		if(name[i]==reg[0]){//if find is possible
			for(int c=1;c<reg.size();c++){
				if(reg[c]!=name[c+i]){break;}//interrupts possible find check if regex does not continue to match.
				if(c==reg.size()-1){return true;}//returns true if possible find completes check.
			}
		}
	}
	return false;
}