/**
 * A demo program for bull-pgia.
 *
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};


        ConstantChooser c5812{"5812"}, c12{"12"}, c25{"25"};
		ConstantGuesser g9898{"9898"}, g12{"12"}, g25{"25"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}

		////
        testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1215","9844"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("9745","4152"), "0,2")
		.CHECK_OUTPUT(calculateBullAndPgia("9745","8152"), "0,1")
		.CHECK_OUTPUT(calculateBullAndPgia("9745","4552"), "0,2")
		.CHECK_OUTPUT(calculateBullAndPgia("9745","4555"), "1,1") 
		.CHECK_OUTPUT(calculateBullAndPgia("9412","9415"), "3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("4565","4565"), "4,0")

		.CHECK_OUTPUT(calculateBullAndPgia("1","2"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("4","7"), "0,0") 
		.CHECK_OUTPUT(calculateBullAndPgia("3","3"), "1,0")

		.CHECK_OUTPUT(calculateBullAndPgia("10", "53"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("15","51"), "0,2")
		.CHECK_OUTPUT(calculateBullAndPgia("25","15"), "1,0") 
		.CHECK_OUTPUT(calculateBullAndPgia("55","54"), "1,0")

		.CHECK_OUTPUT(calculateBullAndPgia("123","456"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("123","345"), "0,1")
		.CHECK_OUTPUT(calculateBullAndPgia("123","423"), "2,0") 
		.CHECK_OUTPUT(calculateBullAndPgia("123","123"), "3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("555","999"), "0,0")

		.CHECK_OUTPUT(calculateBullAndPgia("12345","67890"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("55555","55555"), "1,0") 
		.CHECK_OUTPUT(calculateBullAndPgia("55558","12345"), "0,1")
		.CHECK_OUTPUT(calculateBullAndPgia("45658","45651"), "4,0")
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c5812, g12345, 4, 100), 0)
		.CHECK_EQUAL(play(c5812, g9999, 4, 100), 101)
		.CHECK_EQUAL(play(c12, g12, 2, 100), 0)
		.CHECK_EQUAL(play(c12345, g12, 5, 100), 0)
		.CHECK_EQUAL(play(c12, g12345, 2, 100), 0)
		.CHECK_EQUAL(play(c25, g12, 2, 100), 101)

		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy2;
		SmartGuesser smarty2;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy2, smarty2, 2, 100)<=50, true);
		}

        	for (uint i=0; i<100; ++i) {
		testcase.CHECK_EQUAL(play(randy2, smarty2, 5, 100)<=10, true);
		}
		
		for (uint i=0; i<100; ++i) {
		testcase.CHECK_EQUAL(play(randy2, smarty2, 2, 10)<=20, true);
		}
		
		for (uint i=0; i<10; ++i) {
		testcase.CHECK_EQUAL(play(randy2, smarty2, 5, 100)<=4, false);
		}
		
       		 for (uint i=0; i<100; ++i) {
		testcase.CHECK_EQUAL(play(randy2, smarty2,3, 100)<=10, true);
		}
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}


