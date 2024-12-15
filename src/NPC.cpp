#include "NPC.h"

// Реализация методов accept для каждого типа NPC
void Bear::accept(NPCVisitor& visitor) {
    visitor.visit(*this); // Посетитель вызывает метод visit для объекта Bear
}

void Bittern::accept(NPCVisitor& visitor) {
    visitor.visit(*this); // Посетитель вызывает метод visit для объекта Bittern
}

void Desman::accept(NPCVisitor& visitor) {
    visitor.visit(*this); // Посетитель вызывает метод visit для объекта Desman
}
