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
// IF (CONDITION) # ONE : TWO : THREE;
// If the expression to the left of the operator # is less than 0, 
// the value of the expression is the value of the first expression after the operator #. 
// If it is equal to 0, the value of the expression is the value of the second expression after the operator #. 
// If it is greater than 0, the value of the expression is the value of the third expression after the operator #.
**************************************************************************/
class Quarternary: public SubExpression {
public:
    Quarternary(Expression* left, Expression* right, Expression* rightMost, Expression* last): SubExpression(left, right, rightMost, last) {
    }
    double evaluate() {
        double aVal = left->evaluate();
        double bVal = right->evaluate();
        double cVal = rightMost->evaluate();
        double dVal = last->evaluate();

        if (aVal < 0){
            return bVal;
        } else if (aVal == 0){
            return cVal;
        } else {
            return dVal;
        }
    }
};