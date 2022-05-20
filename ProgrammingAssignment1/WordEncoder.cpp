#include <fstream>
#include "Encoder.h"
using namespace std;


/*****************************************************************************************
*  Program Name: WordEncoder.cpp
*  Created Date: 2/13/19
*  Created By: Shawn Ruby
*  Purpose: compresses and decompresses text files
*  Acknowledgements: None
*****************************************************************************************/


/*****************************************************************************************
*  function Name:  main()
*  Parameters:  none
*  Return Value: none
*  Purpose: starting position before going to WordToNumber function in Encoder.cpp
*****************************************************************************************/


int main()
{
	/* creates an object for the class*/
	WordSorting S1;

	/* points the object to the function within the class */
	S1.WordToNumber();

	/* closes the program */
	return 0;
}