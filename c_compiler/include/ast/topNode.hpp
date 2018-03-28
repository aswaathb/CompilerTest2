#ifndef TOPNODE_HPP
#define TOPNODE_HPP


#include "base_expr.hpp"
#include "baseNode.hpp"


class topNode {
public:
	topNode();

	void create(baseNode* in_base) ;

    //void prettyprint(std::ostream &stream) const ;

    void allocate_memory(int& allocated_mem) const ;

    void generate_assembly(context* context, mips_registers* registers, int& dest_reg) const;

private:
	std::vector<baseNode*> all_list;

};

#endif
