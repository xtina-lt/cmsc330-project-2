/******************************************************************************* 
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

// This file contains the class definition of the SymbolTable class. The symbol table is represented
// with a vector (list) of type Symbol which is a pair consisting of a variable and its associated value.
// The body of its functions are defined in symboltable.cpp.  
*********************************************************************************/


class SymbolTable {
public:
    SymbolTable() {}
    void insert(string variable, double value);
    double lookUp(string variable) const;
    // UPDATED: ADDED TO REPLACE VARIABLE'S VALUE
    void replaceMe(string variable, double value);
    // void check();
    // static vector<string> used;
private:
    struct Symbol {
        Symbol(string variable, double value) {
            this->variable = variable;
            this->value = value;
            this->used = false;
        }
        string variable;
        double value;
        bool used;
    };
    vector<Symbol> elements;
};


