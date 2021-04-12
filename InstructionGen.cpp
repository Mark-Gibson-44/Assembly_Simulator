#include "InstructionGen.h"
#include <fstream>


void InstructionGen::Traverse(const char* out)
{
	std::fstream compiled;
	compiled.open(out);


	for (auto& leaf : Iterator->children)
	{
		compiled << (int)operationMappings[leaf->getLex()];
		compiled << leaf->children[0]->getLex();

		if (leaf->children.size() > 1)
		{


			compiled << leaf->children[1]->getLex();
			
		}
		compiled << std::endl;
	}
}
