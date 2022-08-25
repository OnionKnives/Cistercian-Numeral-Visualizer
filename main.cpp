#include "text.h"
#include "input.h"
#include "graphics.h"
#include "cistercianNumeral.h"

#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	init_Graphics();
	init_Text();

	vector<Numeral> numerals = {
		6594, {13, {60, 20}}, {231, {100, 20}}, {889, {140, 20}}, {9863, {180, 20}}
	};

	// Game Loop
	while (running()) {
		input();
		render(numerals);
	}

	shutdown_Text();
	shutdown_Graphics();
	return 0;
}