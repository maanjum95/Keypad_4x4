/*******************************************************************************************************	
* 	File Name: Keypad_4x4.ino
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

#include <Keypad_4x4.h>

Keypad_4x4 *keypad; // Pointer to keypad object
char ch;  // character which will be used to store the output of keypad
byte arr[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  // The pins 2-9 will be connected to the keypad
  // The keypad pin numbering is from left to right
  // So port2 will be connected to left most pin.
  // And port 9 will be connected to right most pin.
  keypad = new Keypad_4x4(arr);
  
  Serial.begin(9600); // Starting serial communication for output. 
}

void loop() {
  ch = keypad->readInput(); // reading the input from the keypad

  // if there is some output from the keypad we print it to Serial
  if (ch != -1)
    Serial.println(ch);
 }
