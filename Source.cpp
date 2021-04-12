
//#include "Parser.h"
#include "ByteCode.h"
int main()
{
	Lexer l("Test.txt");
	//l.log_lexing();
	
	/*ParseNode head("Head", 1);
	ParseNode leaf1("Leaf1", 2);
	ParseNode leaf2("Leaf2", 2);
	head.addNode(&leaf1);
	leaf1.addNode(&leaf2);

	head.logNodes();
	*/
	Parser p(l.out());
	//p.logTree();

	VM vm;
	vm.Interpreter(p.getTree());

	
}