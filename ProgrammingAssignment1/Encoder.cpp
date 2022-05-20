#include "Encoder.h"
#include <iostream>
#include <string>
#include <fstream>


/*****************************************************************************************
*  function Name:  WordToNumber()
*  Parameters:  none
*  Return Value: none
*  Purpose: contains all code. Decompresses and Compresses files
*****************************************************************************************/

void WordSorting::WordToNumber()
{
	/* variable to keep track of non unique numbers */
	int nonunique = 0;

	/* variable to keep track of unique numbers */
	int unique = 0;

	/* variable to keep track of how many words are in the file */
	int wordcount = 0;

	/* string variable to store the text from the file */
	string word;

	/* opens stream for the input file */
	ifstream infile;

	/* opens the file */
	infile.open("testfile.txt");

	/* opens stream for the output file */
	ofstream outfile;

	/* opens the file */
	outfile.open("Output.txt");

	/* checks to make sure the file was open, if not says the file was not opened. the file was open it continues*/
	if (!infile)
	{
		cout << "The file was not opened.\n";
		system("pause");
	}
	else
	{
		/* creates an arry of strings for 500 places */
		string words[500];

		/* checks to see if there is a word in the file and stores it as word */
		while (infile >> word)
		{
			/* keeps track of how many words there are */
			wordcount += 1;

			/* try statement to see if the word in the file is in the array already */
			try
			{
				/* loops to check if the word in the file is in the array */
				for (int i = 0; i < wordcount; i++)
				{
					/* if word is in array, throws i */
					if (word == words[i])
						throw int(i);
				}
			}
			/* catches i */
			catch (int i)
			{ /* if exception was caught, nonunique is increased i + 1*/
				nonunique = i + 1;

				/* print statement for the duplicate */
				cout << nonunique;

				/* writes the duplicate to the file */
				outfile << nonunique;
			}

			/* if statement for if nonunique is 0 */
			if (nonunique == 0)
			{
				/* writes the word to the array in position of unique */
				words[unique] = word;

				/* unique increase by 1 */
				unique += 1;
				
				/* writes data to output file */
				outfile << unique;

				/* print statement for the non duplicate */
				cout << unique;

			}

			/* if the non unique is more than 0, it is set back to 0 */
			else if (nonunique > 0)
			{
				nonunique = 0;
			}
		}

		/* print statement to clean up output*/
		cout << endl << endl;
		outfile << endl << endl;

		/* loops through how many places in the array there are and prints each value in the array */
		for (int i = 0; i < unique; i++)
		{
			cout << i + 1 << ". " << words[i] << endl;
			outfile << i + 1 << ". " << words[i] << endl;
		}

		/* pauses */
		system("pause");

		/*  closes input file */
		infile.close();

		/* closes output file*/
		outfile.close();
	}
}
