/**************************************************************** 
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

// This file contains the body of the functions contained in The SubExpression class, which includes
// the constructor that initializes the left and right subexpressions and the static function parse
// parses the subexpression. Addition and subtraction are the two operators that are implemented.

*************************************************************************/


#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "unary.h"
#include "multiply.h"
#include "divide.h"
#include "pow.h"
#include "mod.h"
#include "greater.h"
#include "less.h"
#include "and.h"
#include "ternary.h"
#include "quarternary.h"
#include "symboltable.h"


//  CONSTRUCTORS
SubExpression::SubExpression(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

// UPDATED: ADDED FOR MORE PARAMS
SubExpression::SubExpression(Expression* left, Expression* right, Expression* rightMost) {
    this->left = left;
    this->right = right;
    this->rightMost = rightMost;
}

SubExpression::SubExpression(Expression* left, Expression* right, Expression* rightMost, Expression* last) {
    this->left = left;
    this->right = right;
    this->rightMost = rightMost;
    this->last = last;
}


// METHODS
Expression* SubExpression::parse(stringstream& in) {
    Expression* left;
    Expression* right;
    Expression* rightMost;
    Expression* last;
    char operation, paren;

    left = Operand::parse(in);
    in >> operation;

    // UPDATED: HANDLE TERNARY
    if (operation == '?') {
        try{
            right = Operand::parse(in);
            in >> operation;
            rightMost = Operand::parse(in);
            // look for closing
            // read if necessary
            in >> operation;
            return new Ternary(left, right, rightMost);
            } catch (const std::exception& e){
                printf("Err wrong! (condition) ? true : false ;\n");
                return nullptr;
        } 
    }
    // UPDATED: HANDLE QUATERNARY
    if (operation == '#') {
        try{
            right = Operand::parse(in);
            in >> operation;
            rightMost = Operand::parse(in);
            in >> operation;
            last = Operand::parse(in);
            in >> operation;
            return new Quarternary(left, right, rightMost, last);
            } catch (const std::exception& e){
                printf("Err wrong! (condition) ? true : false ;\n");
                return nullptr;
        } 
    }

    // UPDATED: ALL OTHER THAN TERNARY
    right = Operand::parse(in);
    in >> paren;

    switch (operation) {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        // UPDATED: ALL UNDER HERE FOR NEW OPERATIONS
        case '~':
            return new Unary(left, right);
        case '*':
            return new Multiply(left, right);
        case '/':
            return new Divide(left, right);
        case '^':
            return new Pow(left, right);
        case '%':
            return new Mod(left, right);
        case '>':
            return new Greater(left, right);
        case '<':
            return new Less(left, right);
        case '&':
            return new And(left, right);
        default:
            printf("err default = %s\n", operation);
            return nullptr;
    }
    return 0;
}
    