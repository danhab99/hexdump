#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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
		stringstream output;
		for (int i = 0; i < 9; ++i)
			output << " ";

		for (int i = 0; i < column; ++i)
			output << setfill('0') << setw(2) << hex << i << ' ';

		output << endl;

		int line = 0;
		while (!ifile.eof()) {
			char buffer[column] = { 0 };
			ifile.read(buffer, column);

			output << setfill('0') << setw(8) << hex << line << ' ';
			line += column;

			for (int i = 0; i < column; ++i) {
				output << setfill('0') << setw(2) << hex << (int)(uint8_t)buffer[i] << ' ';
			}

			output << endl;
		}

		ifile.close();
		cout << output.str();
		return 0;
	}
	else {
		cerr << "Cannot open file";
		return 1;
	}

	
}