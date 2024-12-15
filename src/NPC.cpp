#include "NPC.h"


void Bear::accept(NPCVisitor& visitor) {
    visitor.visit(*this);
}

void Bittern::accept(NPCVisitor& visitor) {
    visitor.visit(*this); 
}

void Desman::accept(NPCVisitor& visitor) {
    visitor.visit(*this); 
}
