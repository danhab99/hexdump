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
		for (int i = 0; i < 9; ++i)
			cout << " ";

		for (int i = 0; i < column; ++i)
			cout << setfill('0') << setw(2) << hex << i << ' ';

		cout << endl;


		return 0;
	}
	else {
		cerr << "Cannot open file";
		return 1;
	}
}