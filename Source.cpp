

#include "ByteCode.h"



int main()
{
	Lexer l("Test.txt");
	//l.log_lexing();
	
	Parser p(l.out());
	//p.logTree();
	//InstructionGen c(p.getTree());
	//c.Traverse("ASM.txt");
	VM vm;
	vm.Interpreter(p.getTree());
	
	
}