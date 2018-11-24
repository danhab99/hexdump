#include <iostream>
#include <fstream>
#include "argparse/argparse.hpp"

using namespace std;

int main(int argc, const char** argv) {
	ArgumentParser parser;

	parser.addFinalArgument("file");

	parser.parse(argc, argv);


}