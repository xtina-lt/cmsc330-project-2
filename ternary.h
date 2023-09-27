/************************************************************************* 
// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// UMGC CITE
// Spring 2023

  _____           _           _     ___  
 |  __ \         (_)         | |   |__ \ 
 | |__) | __ ___  _  ___  ___| |_     ) |
 |  ___/ '__/ _ \| |/ _ \/ __| __|   / / 
 | |   | | | (_) | |  __/ (__| |_   / /_ 
 |_|   |_|  \___/| |\___|\___|\__| |____|
                _/ |                     
               |__/                                       

// UPDATED: created
// IF (CONDITION) ? TRUE : FALSE;
// If the expression to the left of the operator ? is not 0, 
// the value of the expression is the value of the first expression after the operator ?. 
// If it is 0, the value of the expression is the value of the second expression after the operator ?.
**************************************************************************/

class Ternary: public SubExpression {
public:
    Ternary(Expression* left, Expression* right, Expression* rightMost): SubExpression(left, right, rightMost) {
    }
    double evaluate() {
        double cVal = left->evaluate();
        double tVal = right->evaluate();
        double fVal = rightMost->evaluate();
        if (cVal != 0)
            return tVal;
        return fVal;
    }
};