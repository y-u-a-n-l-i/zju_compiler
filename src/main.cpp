#include <cstdio>
#include <iostream>
#include "./ast.hpp"
#include "./code_gen.hpp"
#include "./build/parser.y.hpp"

extern int yylex(void);
extern int yyparse(void);
extern void yyrestart(FILE*);
int errorLexFlag;
int errorSyntaxFlag;

extern ExprAST* Program;

int main(int argc, char** argv){
    if (argc<=1) return 1;
    FILE* f = fopen(argv[1], "r");
    
    if(!f){
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    std::cout<< "Start to parse." <<std::endl;
    yyparse();

    std::cout<< "Start to generate code." <<std::endl;
    Program->codegen();
    return 0;
}