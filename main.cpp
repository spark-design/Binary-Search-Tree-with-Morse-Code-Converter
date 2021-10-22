/*Student Name: Connor Sparkman
Student NetID: cps260
Compiler Used: Visual Studio
Program Description: Program can convert a string to a series of morse code, also can construct a binary search tree in which you can print the tree inOrder postOrder or preOrder and you can clear
*/

// Add our class header files
#include "Tokenizer.h"
#include "BST.h"

#include <fstream>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using namespace::std;


// Interactive Shell Function
bool processText(istream& is, BST& bst, bool interactive)
{
	string line;
	string command;

	// Command argument variables
	int intArg1, intArg2;
	string strArg1;

	// Initialize our classes as objects
	Tokenizer tkn;
	
	while (true)
	{
		// Begin interactive tokenizer shell
		if (!interactive)
		{
			if (is.eof()) return true;
		}
		else { cout << ">> "; }

		// Read in a line from the user
		getline(is, line);

		// Set tokenizer line from user input
		tkn.setString(line);

		// Read the command string
		// Begin long chain of if statement
		tkn.readString(command);

		// Exit command. Just exits the interactive shell and
		// and end the program
		if (command == "exit")
		{
			cout << "Exiting ...." << endl;
			return false;
		}

		// Load file command
		if (command == "load")
		{
			// load expects a filename (string arg), so error if 
			// no filename is provided
			if (!tkn.readString(strArg1)) {
				cout << "Missing file name" << endl;
				continue; // skip back to the top of the read loop
			}
			ifstream fin;
			bool status = true;

			// Attempts to open filename
			fin.open(strArg1);

			// Process file if able to open
			if (fin.is_open())
				status = processText(fin, bst, false);
			// Error out if file cannot be opened
			else
				cout << "Failed to open the file" << endl;

			// Close file
			fin.close();

			if (!status)
				return false;
		}


		// Help Command
		if (command == "help")
		{
			// Help Menu Formatting Color Codes
			string commandColorCode = "\x1b[36m";
			string parameterColorCode = "\x1b[35m";
			string defaultColorCode = "\x1b[39m";

			// Lists all possible shell commands
			cout << "Commands" << endl
				<< "############" << endl
				<< commandColorCode << "exit\t\t" << defaultColorCode << "Exits the interactive shell" << endl
				<< commandColorCode << "load " << parameterColorCode << "String\t" << defaultColorCode << "Loads a file to execute a list of commands" << endl
				<< commandColorCode << "constructTree " << parameterColorCode << "Int\t" << defaultColorCode << "Creates tree based on depth passe in" << endl
				<< commandColorCode << "help\t\t" << defaultColorCode << "Lists all possible commands and their parameters" << endl
				<< commandColorCode << "insert " << parameterColorCode << "Int\t" << defaultColorCode << "Inserts a Node containing an Integer to the BST" << endl
				<< commandColorCode << "remove " << parameterColorCode << "Int\t" << defaultColorCode << "Removes a Node containing an Integer from the BST" << endl
				<< commandColorCode << "preOrder\t" << defaultColorCode << "Prints the list via preOrder" << endl
				<< commandColorCode << "inOrder\t\t" << defaultColorCode << "Prints the list via inOrder" << endl
				<< commandColorCode << "postOrder\t" << defaultColorCode << "Prints the list via postOrder" << endl
				<< commandColorCode << "convert " << defaultColorCode << "String\t" << "Converts string to morse code sequence" << endl
				<< commandColorCode << "clear" << defaultColorCode << "Clears content of tree" << endl
				<< "############" << endl;
		}

		/*
		if (command == "insert")
		{
			if (tkn.readInteger(intArg1))
			{
				bst.insert(intArg1);
				cout << "Added Node Containing " << intArg1 << " To End Of List" << endl;
			}
			else
			{
				cout << "Expected an Integer" << endl;
			}
		}
		*/

		/*if (command == "remove")
		{
			if (tkn.readInteger(intArg1))
			{
				if (bst.remove(intArg1))
				{
					cout << "Removed Node Containing " << intArg1 << endl;
				}
				else
				{
					cout << "No Node Containing " << intArg1 << " Found" << endl;
				}
			}
			else
			{
				cout << "Expected an Integer" << endl;
			}
		}
		*/

		if (command == "inOrderTraversal")
		{
			bst.inOrder();
			cout << endl;
		}

		if (command == "preOrderTraversal")
		{
			bst.preOrder();
			cout << endl;
		}

		if (command == "postOrderTraversal")
		{
			bst.postOrder();
			cout << endl;
		}

		if (command == "constructTree")
		{
			if (tkn.readInteger(intArg1))
			{
				bst.constructTree(intArg1);
			}
			else
			{
				cout << "Expected an integer" << endl;
			}
		}

		if (command == "clear")
		{
			bst.clear();
		}

		
		if (command == "convert")
		{
			if (tkn.readString(strArg1))
			{
				bst.convertString(strArg1);
				cout << "convert" << endl;
			}
			else
			{
				cout << "Expected a string" << endl;
			}
		}
		
	}
}


int main()
{
	BST bst;
	// Passes cin, a LinkedList, and a bool to the function
	// This is needed to create an interacive shell
	processText(cin, bst, true);
	return 0;

}