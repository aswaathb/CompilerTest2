#include "ast.hpp"

int main()
{
    const Expression *ast=parseAST();

    ast->python_print();

    return 0;
}
