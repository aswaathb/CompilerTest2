#ifndef ast_hpp
#define ast_hpp

#include "ast/assignment_expr.hpp"
#include "ast/base_expr.hpp"
#include "ast/base_statement.hpp"
#include "ast/baseNode.hpp"
#include "ast/binary_operators.hpp"
#include "ast/compound_statement.hpp"
#include "ast/context.hpp"
#include "ast/declaration.hpp"
#include "ast/forWHILE_statement.hpp"
#include "ast/function_params.hpp"
#include "ast/functions.hpp"
#include "ast/IFELSE_statement.hpp"
#include "ast/logical_expr.hpp"
#include "ast/math_operators.hpp"
#include "ast/register_handler.hpp"
#include "ast/return_statement.hpp"
#include "ast/tokens.hpp"
#include "ast/topNode.hpp"


// #include <iostream>

extern const Expression *parseAST();


class Expression;
class variable_declaration;
class return_statement;
class function_definition;


// class Expression {
// public:
//     virtual ~Expression()
//     {}
//     virtual void translate() const =0;
// };

// class variable_declaration : public Expression{
// public:
//     double value;
//     std::string *var_name;

//     variable_declaration(std::string *_var, double _val)
//     : var_name(_var), value(_val) {};


//     virtual void translate() const override {
//         std::cout<<*var_name;
//         std::cout<<"=";
//         std::cout<<value;
//         std::cout<<std::endl;
//     }
// };


// class function_definition : public Expression {
// public:
// std::string *func_name;
// variable_declaration Variable;

//     function_definition(std::string *_func_name, variable_declaration* _scope)
//     : func_name(_func_name), Variable(*_scope) {};

//     virtual void translate() const override{
//         std::cout<<"def ";
//         std::cout<<*func_name;
//         std::cout<<"():\n"<<std::endl;
//         std::cout<<"\t"<<*Variable.var_name;
//         std::cout<<"=";
//         std::cout<<Variable.value;
//         std::cout<<std::endl;
//     }

// };

// class return_statement : public Expression {
// public:
// std::string *return_type;
// double value;

//     return_statement(std::string *_return_type, double _val )
//     : return_type(_return_type), value(_val) {};
    
//     virtual void translate() const override{
//         std::cout<<*return_type<<" ";
//         std::cout<<value;
//         std::cout<<std::endl;
//     }    

// };

#endif
