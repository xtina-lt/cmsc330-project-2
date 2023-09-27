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
// DIVIDE LEFT AND RIGHT
**************************************************************************/

class Divide: public SubExpression {
public:
    Divide(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate()  {
       return left->evaluate() / right->evaluate();
    }
};