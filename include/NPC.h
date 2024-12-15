#ifndef NPC_H
#define NPC_H

#include <string>
#include <memory>
#include <iostream>

class NPCVisitor;

class NPC {
public:
    NPC(const std::string& name, int x, int y) : name(name), x(x), y(y) {}
    virtual ~NPC() = default;

    const std::string& getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }

    void setCoordinates(int newX, int newY) {
        x = newX;
        y = newY;
    }

    virtual void accept(NPCVisitor& visitor) = 0;
    virtual std::string getType() const = 0;

protected:
    std::string name;
    int x, y;
};

class Bear : public NPC {
public:
    Bear(const std::string& name, int x, int y) : NPC(name, x, y) {}

    void accept(NPCVisitor& visitor) override;
    std::string getType() const override { return "Bear"; }
};

class Bittern : public NPC {
public:
    Bittern(const std::string& name, int x, int y) : NPC(name, x, y) {}

    void accept(NPCVisitor& visitor) override;
    std::string getType() const override { return "Bittern"; }
};

class Desman : public NPC {
public:
    Desman(const std::string& name, int x, int y) : NPC(name, x, y) {}

    void accept(NPCVisitor& visitor) override;
    std::string getType() const override { return "Desman"; }
};

class NPCVisitor {
public:
    virtual ~NPCVisitor() = default;
    virtual void visit(Bear& bear) = 0;
    virtual void visit(Bittern& bittern) = 0;
    virtual void visit(Desman& desman) = 0;
};

#endif
