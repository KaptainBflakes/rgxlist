#include <filesystem>
#include <iostream>
#include <string>
//requires std:c++17 to compile. NOTE IF YOU WANT TO MAKE A LIST FROM FILE EXTENSION, USE extlist! THIS DOES NOT HANDLE EXTENSION DATA!
using namespace std;
using namespace std::filesystem;
int main(int argc, char ** argv){
	//argv[1] gives the regex string. argv[2] is the input directory. input is assumed local unless given. use '>' to send output to a file
	string dir=".\\";//If on linux, change this shit to a "./"
	if(argc==3){dir=argv[2];}//optional search directory dication
	string out="";string reg=argv[1];//regex dictation
	for(auto& entry: directory_iterator(dir)){
		if(entry.path().has_extension()){
			string name=entry.path().stem().string();
			for(int i=0;i<name.size();i++){
				//checks if a match starting at this index is possible. Checks if this index matches the start of the regex and if there is space in the name left for regex.
				if(name[i]==reg[0]&&name.size()-i>=reg.size()){
					//checks if possible match is a complete match.
					bool good = true;for(int c=0;c<reg.size();c++){if(reg[c]!=name[c+i]){good=false;break;}}//if one char doesn't match, break and go on to the next index.
					//output string building in case of match find.
					if(good){out+=entry.path().string();out+="\n";
						break;//breaks so that then next path can be processed.
					}
				}
			}
		}
	}
	cout<<out;
	return 0;
}