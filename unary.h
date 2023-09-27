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
// NEGATE THE VALUE
**************************************************************************/

class Unary: public SubExpression {
public:
    Unary(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate()  {
        if ( -left->evaluate() == 1.0) 
            return -right->evaluate();
        return -left->evaluate();
    }
};