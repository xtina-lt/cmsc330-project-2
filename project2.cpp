/*************************************************************************** 
// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023
// Edited by: Christina Torres

  _____           _           _     ___  
 |  __ \         (_)         | |   |__ \ 
 | |__) | __ ___  _  ___  ___| |_     ) |
 |  ___/ '__/ _ \| |/ _ \/ __| __|   / / 
 | |   | | | (_) | |  __/ (__| |_   / /_ 
 |_|   |_|  \___/| |\___|\___|\__| |____|
                _/ |                     
               |__/                                     

// This file contains the main function for the project 2 skeleton. It reads an input file named input.txt
// that contains one statement that includes an expression following by a sequence of variable assignments.
// It parses each statement and then evaluates it.
*************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"
#include "operand.h"

SymbolTable symbolTable;

void parseAssignments(stringstream& in);

int main() {
	//  UPDATE: ADDED QUOTES FOR FUN
	const char* quotes[] = {
		"Finished last will always be better than not finished.", 
		"It only seems impossible until it's done.", 
		"Many will start fast. Few will finish strong."
		};
	// UPDATE: added for counting lines and showing in therminal
	int linecount = 0;
	const int SIZE = 256;
	Expression* expression;
    char paren, comma, line[SIZE];
 
	ifstream fin;
	fin = ifstream("input.txt");
	if (!(fin.is_open())) {
		cout << "File did not open" << endl;
		system("pause");
		return 1;
	}
	while (true) {
        fin.getline(line, SIZE);
		if (!fin)
			break;
		stringstream in(line, ios_base::in); 
		in >> paren;
		// UPDATE: changed o show line and added line num
		printf("%d %s\n", linecount, line);
		try {
			expression = SubExpression::parse(in);
			in >> comma;
			parseAssignments(in);
			double result = expression->evaluate();
			// UPDATE: changed to show result as double
			printf("Value = %f\n", result);
			// 	ADDITIONS: for random quotes
			int num = sizeof(quotes) / sizeof(quotes[0]);
			srand(time(NULL));
			int randomIndex = rand() % num;
			printf("%s", quotes[randomIndex]);
			// added to increase line number
			linecount++;
		}
		catch (string message) {
			// UPDATE: changed for personalization
			printf("Oops! %s\n", message);
		}
	}
	// COMMENT BACK IN WHEN FINISHED
	// system("pause");
	return 0;
}

void parseAssignments(stringstream& in) {
	char assignop, delimiter;
    string variable;
	// UPDATED: CHANGED TO ALLOW FOR DECIMALS
    double value;
    do {
		variable = parseName(in);
		in >> ws >> assignop >> value >> delimiter;
		// ****************** FINAL TASK *************************
		// The symbol table should be initialized before each statement is evaluated, so that variables that are reused do not contain the value from a previous statement.
		// A variable initialized more than once in a statement should be reported as an error (Creating an exception class to accommodate this error and the previous one is the recommended approach).
		try {
				// if it isn't in there add it
		 		if (symbolTable.lookUp(variable) == -1) {
					symbolTable.insert(variable, value);
		 		} else {
		 			throw (-1);
		 		}
		 	}
			// if it is in there catch the error and update the variable
		 	catch (int num) {
		 		printf("%s", "Oops! Updating variable!\n");
		 		symbolTable.replaceMe(variable, value);
		 	}
			// ****************** END FINAL TASK *************************
    }
    while (delimiter == ',');
}
   
