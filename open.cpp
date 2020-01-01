#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

int isPath(string inp);

int main(int args, char* argv[]) {
	if(2 > args) {
		cout << "please input link in command-line to open!" << endl;
		return 1;
	}

	string inp(argv[1]);
	stringstream ss;
	
	string path;
	if(-1 < isPath(inp)) {
		/**
			link to a specific program
		*/
		path = inp;
	} else {
		/**
			use as a variable enviroment
		*/
		char* valVar = getenv(inp.data());
		path = string(valVar);
	}
	ss << "start \"\" \"" << path << "\"";
	string cmd = ss.str();
	system(cmd.data());

	return 0;
}

int isPath(string inp){
	int __isPath = inp.find("/");
	if(-1 == __isPath){
		__isPath = inp.find(":");
	}
	if(-1 == __isPath){
		__isPath = inp.find("\\");
	}
	return __isPath;
}
