#include "Parser.h"
#include <iostream>


void ParseNode::addNode(ParseNode* p)
{
	this->children.push_back(p);
	p->setParent(this);
}

ParseNode* ParseNode::getParent()
{
	return this->Parent;
}

std::string ParseNode::getLex()
{
	return Lex;
}

void ParseNode::setParent(ParseNode* p)
{
	this->Parent = p;
}

void ParseNode::logNodes()
{
	const char* parentInfo = (this->Parent == nullptr) ? "HEAD of Tree" : this->Parent->Lex.c_str();
	std::cout << "Node: " << this->Lex <<  " with Parent :" << parentInfo << std::endl;
	for (auto& child : this->children)
	{
		child->logNodes();
	}
}



void Parser::match(Tokens t)
{
	if (Lexed[current_pos].first == t)
	{
		ParseNode* leaf = new ParseNode(Lexed[current_pos].second, (int)Lexed[current_pos].first);
		Traversal->addNode(leaf);
		current_pos++;
		lookahead_pos++;
	}
	else
	{
		//Throw an error
	}

}

void Parser::Expr()
{
	while (this->lookahead_pos < Lexed.size())
	{
		if (Lexed[current_pos].first == Tokens::Labl)
		
			match(Tokens::Labl);

		else
			Op();//Currently every expressions begins with an OP
		//TODO implement Labels
		
	}
	
}

void Parser::Op()
{
	match(Tokens::Op);
	Traversal = Traversal->children[Traversal->children.size() - 1];//Set Register and either Reg or Imm as children of Opp node
	match(Tokens::Reg);
	if (Lexed[current_pos].first != Tokens::Op)
		RHS();
	Traversal = Traversal->getParent();//Return to Op Node;
}

void Parser::RHS()
{
	if (Lexed[current_pos].first == Tokens::Imm)
		match(Tokens::Imm);
	
	else
		match(Tokens::Reg);
}

ParseNode* Parser::getTree()
{
	return head;
}

void Parser::logTree()
{
	head->logNodes();
}
