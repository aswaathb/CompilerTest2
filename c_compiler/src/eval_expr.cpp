#include "ast.hpp"

#include <iomanip>

int main(int argc, char *argv[])
{
    
    const baseNode *ast=parseAST();
    
    //python translation
    std::cout<<std::endl;
    //Python "Footer"
    std::cout<<"if __name__ == \"__main__\": "<<std::endl;
    std::cout<<"import sys" <<std::endl ;
    std::cout<<"ret=main()" << std::endl;
    std::cout<<"sys.exit(ret)" << std::endl;
    

    //MIPS Machine Code
    ast->generate_assembly();
    //std::cout<<std::endl;   
    
    return 0;
}
