#include <iostream>

//Interface class consist only of unimplemented functions
//Interface classes cannot be instantiated
//Holds a promise to the compiler that the class will have a function
class Printable {
public:
	virtual std::string GetClassName() = 0;
};


class Entity : public Printable{
public:
	virtual std::string GetName() const = 0;
	std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity {
private:
	std::string m_Name;
public:
	Player(const std::string& name) : m_Name(name) {}

	std::string GetName() const override { return m_Name; }
	//std::string GetClassName() { return "Player"; }
};



void Print(Printable* obj) {
	std::cout << obj->GetClassName() << std::endl;
}

int main() {
	Player* p = new Player("Adam");

	Print(p);


	__debugbreak();
	return 0;
}