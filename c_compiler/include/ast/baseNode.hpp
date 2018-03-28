#ifndef BASENODE_HPP
#define BASENODE_HPP

#include <iostream>
#include <map>
#include "tokens.hpp"
#include <vector>

class ast_base
{
public:
    virtual ~ast_base();

    virtual void xmlprint() const =0;
    
    virtual void prettyprint(std::ostream &stream) const =0;

    virtual void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const = 0;

    virtual void allocate_memory(int& allocated_mem) const = 0;
    

};

#endif
