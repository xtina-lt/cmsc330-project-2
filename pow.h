/************************************************************************* 
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

// UPDATED: created
// GET THE POWER OF A VALUE ON THE LEFT TO THE VALUE OF THE RIGHT
**************************************************************************/
#include <cmath>

class Pow: public SubExpression {
public:
    Pow(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate() {
       return pow(left->evaluate(), right->evaluate());
    }
};