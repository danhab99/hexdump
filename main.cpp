#include <iostream>
#include <fstream>
#include "argparse/argparse.hpp"

using namespace std;

int main(int argc, const char** argv) {
	ArgumentParser parser;

	parser.addFinalArgument("file");

	parser.parse(argc, argv);

	ifstream ifile;
	const int column = 16;

	ifile.open(parser.retrieve<string>("file"), ios::in | ios::binary);

	if (ifile.is_open()) {


		return 0;
	}
	else {
		cerr << "Cannot open file";
		return 1;
	}
}