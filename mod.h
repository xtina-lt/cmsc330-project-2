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
// FIND THE MODULUS
**************************************************************************/

class Mod: public SubExpression {
public:
    Mod(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
        double leftValue = left->evaluate();
        double rightValue = right->evaluate();
        return leftValue - static_cast<int>(leftValue / rightValue) * rightValue;
    }
};