/*******************************************************************************************************	
* 	File Name: Keypad_4x4.h
*	Project Name: Keypad_4x4 (Arduino)
* 	
* 	The MIT License (MIT)
*
*	Copyright (c) 2015 M.A. Anjum
*	Email : ma.anjum95@gmail.com
*	
*	Permission is hereby granted, free of charge, to any person obtaining a copy of this software
*	and associated documentation files (the "Software"), to deal in the Software without restriction,
*	including without limitation the rights to use, copy, modify, merge, publish, distribute,
*	sublicense, and/or sell copies of the Software, and to permit persons to whom the Software 
*	is furnished to do so, subject to the following conditions:
*
*	The above copyright notice and this permission notice shall be included in all copies 
*	or substantial portions of the Software.
*
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
*	INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
*	AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
*	DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF 
*	OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
********************************************************************************************************/
/**
*	4x4 Matrix Membrane Keypad (#27899)
*						  Pins
*		+---+---+---+---+
*		| 1 | 2 | 3 | A |  8
*		+---+---+---+---+
*		| 4 | 5 | 6 | B |  7
*		+---+---+---+---+
*		| 7 | 8 | 9 | C |  6
*		+---+---+---+---+
*		| * | 0 | # | D |  5
*		+---+---+---+---+	
*	Pins: 4   3   2   1
*
*	Port : |8|7|6|5|4|3|2|1| 
*
*	The numbering of the pins attached via thin cable mentioned here is from right to left.
*	So the pins are number as |8|7|6|5|4|3|2|1| when seen from the front facing the keypad upwards.
*
*	Working:
*	1- The four right pins (1-4) are either pulled up or down (in this library it is pulled down by 1k).
*	2- Then one by one the above mentioned pins are set(if pulled down) or cleared (if pulled up),
*		and the values of the rest of the pins (5-8) are checked.
*	3- Depending upon the state of the pins (5-8) we can check which button is pressed.
*	
*	** IMP ** The input ports (5-8) need to be pulled up with 1k for proper execution.
*/

#ifndef KEYPAD_4X4
#define KEYPAD_4X4

#include "Arduino.h"

#define PINS 8

// The ASCII output of each button as written on the keypad
// The last number is mn as defined in matrix as mxn ie 84 = 8x4
// These number dont necessarily represent the row or column number but the pin corresponding to each row or column
#define BUTTON_OUTPUT_84 '1'
#define BUTTON_OUTPUT_83 '2'
#define BUTTON_OUTPUT_82 '3'
#define BUTTON_OUTPUT_81 'A'

#define BUTTON_OUTPUT_74 '4'
#define BUTTON_OUTPUT_73 '5'
#define BUTTON_OUTPUT_72 '6'
#define BUTTON_OUTPUT_71 'B'

#define BUTTON_OUTPUT_64 '7'
#define BUTTON_OUTPUT_63 '8'
#define BUTTON_OUTPUT_62 '9'
#define BUTTON_OUTPUT_61 'C'

#define BUTTON_OUTPUT_54 '*'
#define BUTTON_OUTPUT_53 '0'
#define BUTTON_OUTPUT_52 '#'
#define BUTTON_OUTPUT_51 'D'

class Keypad_4x4 {
private:
	byte pins[PINS] = {0};

	/**
	*	Returns a character depending upon the mxn combination sent to the method
	*	The character corresponding to individual mxn is given above.
	*	The values of mxn can be calculated from the figure given in comments.
	*/
	char returnButtonOutput(int mxn);
public:
	/**
	*	Initializes the keypad pins from the given array of pins.
	*	pins: An array of port number on which the keypad pins are connected.
	*	The size of pins should be 8 (PINS) are must contain the port number in the order as defined in the beggining comments.
	*	ie pins[7] -> port connected to pin 8 and pins[0] - > port connected to pin 1
	*/
	Keypad_4x4(byte *pins);

	/**
	*	Reads input from the keypad and returns the appropriate character.
	*	In case of no input the keypad -1 is returned.
	*/
	char readInput(void);


	/**
	*	Waits for input from the keypad for at most ms milliseconds
	*	After the specified time if no key input is detected -1 is returned.
	*	When a key is pressed the character is returned even if time has not completed
	*	If ms = 0 then it returns infinetely till a key is pressed.
	*/
	char waitForInput(int ms=0);

	/**
	*	Reads a single input from the keypad and waits till the key is released.
	*	It prevents the same input from being read repreatly.
	*	This method does not wait for input but if the key pressed is not released the method does not return.
	*/
	char readSingleInput(void);

	/**
	*	It does the same as readSingleInput but also waits a certains specified time
	*	It is a combination of waitForInput and readSingleInput.
	*	If ms = 0 then it returns infinetely till a key is pressed.
	*	If a key is pressed it is not returned untill the key is released.
	*/
	char waitAndReadSingleInput(int ms=0);
};

#endif