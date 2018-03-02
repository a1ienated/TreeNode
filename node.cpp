#include <iostream>
#include <list>
#include <string>
//#include <boost\variant.hpp>
#include <boost/variant.hpp>

typedef boost::variant<int, float, double, std::string> customVariant;

class Node {
public:
	Node() {}
	Node(std::string name)
	{
		this->name = name;
	}

	Node(std::string name,
		customVariant value,
		Node *parent = nullptr) : Node(name)
	{
		this->value = value;
		if (parent != nullptr) {
			parent->addChild(this);
		}
	}

	~Node() {
		for (auto i = childs.begin(); i != childs.end(); ++i) {
			Node *child = *i;
			delete child;
		}
		std::cout << this->name << " deleted" << std::endl;
	}

	void addChild(Node *node)
	{
		childs.push_front(node);
	}

	customVariant getValue() const
	{
		return this->value;
	}

	void setValue(customVariant value)
	{
		this->value = value;
	}

	void print() {
		std::cout << "name " << name << "; value: " << value << std::endl;
		for (auto i = childs.begin(); i != childs.end(); ++i) {
			(*i)->print();
		}
	}

	void printValue()
	{
		std::cout << "value: " << value << std::endl;
	}
private:
	std::list<Node*> childs;
	customVariant value = 0;
	std::string name = "";
};

int main() {
	Node *parentNode = new Node("node0", "Value1");
	Node *pointerToNode = new Node("node1", 0, parentNode);
	pointerToNode = new Node("node2", 0.1, parentNode);
	pointerToNode = new Node("node3", 0.1f, pointerToNode);
	parentNode->print();
	delete parentNode;
	return 0;
}