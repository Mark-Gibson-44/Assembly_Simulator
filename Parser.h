#pragma once
#include <string>
#include <vector>
#include <optional>
#include "Lexer.h"
#include <memory>

class ParseNode {
	std::string Lex;
	int tok;
	
	ParseNode* Parent;
	
	//ParseNode* getParent();
	void setParent(ParseNode* p);
public:
	ParseNode(std::string l, int v) : Lex(l), tok(v), Parent(nullptr) {}
	std::vector<ParseNode*> children;
	void logNodes();
	void addNode(ParseNode* p);
	ParseNode* getParent();
	std::string getLex();
};

class OpNode: public ParseNode {

	
	std::optional<std::unique_ptr<ParseNode>> dest;

};

class Parser {

	ParseNode* head = new ParseNode("Program", 3);//Head of a program

	ParseNode* Traversal; // Node ptr to traverse and add nodes accordingly
	int current_pos; //Current position within the stream of input
	int lookahead_pos;
	std::vector<std::pair<Tokens, std::string>> Lexed;// 
	int ExprNum = 0;

	
	void match(Tokens t);

	//Recursive parsing functions
	void Expr();
	void Op();
	
	void Reg_Reg();
	void RHS();
public:
	ParseNode* getTree();//output
	void logTree();
	Parser(std::vector<std::pair<Tokens, std::string>>& in) : Lexed(in), Traversal(head), current_pos(0), lookahead_pos(1) {
		Expr();
	}


		
};