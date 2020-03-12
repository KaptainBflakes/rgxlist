#include <filesystem>
#include <iostream>
#include <string>
//requires std:c++17 to compile. NOTE IF YOU WANT TO MAKE A LIST FROM FILE EXTENSION, USE extlist! THIS DOES NOT HANDLE EXTENSION DATA!
using namespace std;
using namespace std::filesystem;
int main(int argc, char ** argv){
	//argv[1] gives the regex string. argv[2] is the input directory. input is assumed local unless given. use '>' to send output to a file
	string dir=".\\";//If on linux, change this shit to a "./"
	if(argc==3){
		dir=argv[2];
	}
	string out="";string reg=argv[1];
	for(auto& entry: directory_iterator(dir)){
		if(entry.path().has_extension()){
			
			bool contains;//name analysis
			string name=entry.path().stem().string();
			contains=false;
			for(int i=0;i<name.size();i++){
				if(name[i]==reg[0]&&name.size()-i>=reg.size()){//if find is possible, meaning same start letter and same character size
					bool good = true;
					for(int c=0;c<reg.size();c++){
						if(reg[c]!=name[c+i]){good=false;break;}//interrupts possible find check if regex does not continue to match.	
					}
					if(good){contains=true;}
				}
			}			
			if(contains){
				out+=entry.path().string();out+="\n";
			}
		}
	}
	cout<<out;
	return 0;
}