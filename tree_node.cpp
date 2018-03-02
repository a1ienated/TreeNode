/*
#include <iostream>
#include <string>
//#include <fstream>
#include <vector>
#include <memory> //unique_ptr
using namespace std;


class baseNode {
public:
	baseNode() {
		varInt = 0;
		varStr = "";
		varFl = 0;
	}
	baseNode(int varInt)
	{
		cout << "Calling varInt" << endl;
	}
	baseNode(int varStr)
	{
		cout << "Calling varStr" << endl;
	}
	baseNode(int varFl)
	{
		cout << "Calling varFl" << endl;
	}
	void setInt(int varInt) {
		this->varInt = varInt;
	}

	virtual void func() = 0;
private:
	int varInt;
	string varStr;
	float varFl;
};


class Children : public baseNode {
public:
	Children(int varInt) {
		setInt(varInt);
	}
	
	void func() override {
		cout << "Children" << endl;
	}
};





int main(int argc, char const *argv[]) {

	

	Children ch(34);

	


	return 0;
}
*/

/*Node *baseNode;

Int intVal;

baseNode = &intVal;
baseNode->func();*/




/*
class String : public baseNode {
public:
void func() override {
cout << "String" << endl;
}
};

class Int : public baseNode {
public:
void func() override {
cout << "Int" << endl;
}
};

class Float : public baseNode {
public:
void func() override {
cout << "Float" << endl;
}
};*/

/*

//это через union
class TreeUnion {
public:
enum Type { isString, isInt };
TreeUnion(const string& value) :type(isString), stringValue(value) {}
TreeUnion(int value) :type(isInt), intValue(value) {}
~TreeUnion()
{
if (type == isString)
stringValue.string::~string();
}

Type type;
union
{
string stringValue;
int intValue;
};
};

class TreeVirtual {
public:
virtual bool isString()const { return false; }
virtual bool isInt()const { return false; }
virtual bool isDouble()const { return false; }

virtual const string& getString()const { throw runtime_error("Ops.."); }
virtual int getInt()const { throw runtime_error("Ops.."); }
virtual double getDouble()const { throw runtime_error("Ops.."); }

vector<unique_ptr<TreeVirtual>> childList;
};

//вот здесь хранится строка для TreeVirtual
class TreeString : public TreeVirtual
{
public:
bool isString()const { return true; }
const string&getString()const { return value; }
string value;
};
*/