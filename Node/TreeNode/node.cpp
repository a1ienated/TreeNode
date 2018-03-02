#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <boost/variant.hpp>

using namespace std;

/*
typedef boost::variant<int, float, double, string> customVariant;

class Node {
public:
	Node() {}
	Node(string name)
	{
		this->name = name;
	}

	Node(string name, customVariant value, Node *parent = nullptr) : Node(name)
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
		cout << "name " << name << "; value: " << value << endl;
		for (auto i = childs.begin(); i != childs.end(); ++i)
		{
			(*i)->print();
		}
	}

	void printValue()
	{
		cout << "value: " << value << endl;
	}
private:
	list<Node*> childs;
	customVariant value = 0;
	string name = "";
};*/


string path = "myFile.txt";

class Point {
public:
	Point() {
		int x = y = z = 0;
	}
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	~Point() {}

private:
	int x, y, z;
	friend ostream& operator<< (ostream& os, const Point& point);
	friend istream& operator>> (istream& is, Point& point);
};


ostream& operator<< (ostream& os, const Point& point) {
	os << point.x << " " << point.y << " " << point.z;
	return os;
}

istream& operator>> (istream& is, Point& point) {
	is >> point.x >> point.y >> point.z;
	return is;
}

void inputFile();
void outputFile();

char *allowedFlags[] = { "--i", "--o" };
void(*commandsStore[])(void) = { inputFile, outputFile };
int allowedFlagsLength = sizeof allowedFlags / sizeof allowedFlags[0];

void validateFlags(const char * const flags[], const int const length) {
	int incorrectFlagIndex = -1;

	for (int i = 1; i < length; i++) {
		for (int j = 0; j < allowedFlagsLength; j++) {
			if (strcmp(flags[i], allowedFlags[j]) == 0) {
				incorrectFlagIndex = -1;
				break;
			}
			else incorrectFlagIndex = i; //сохраняем индекс некорректного флага
		}

		if (incorrectFlagIndex > -1) {
			printf("[-] Error: %s incorrect flag was given!\n", flags[incorrectFlagIndex]);
			exit(EXIT_FAILURE);
		}
	}
}

void invokeCommands(const char * const commands[], const int count) {
	for (int i = 1; i < count; i++) {
		for (int j = 0; j < allowedFlagsLength; j++) {
			if (strcmp(commands[i], allowedFlags[j]) == 0) {
				commandsStore[j]();
			}
		}
	}
}

void inputFile() {
	ofstream fWrite;
	Point point(63, 812, 37);

	fWrite.open(path, ofstream::app);
	if (!fWrite.is_open()) {
		cout << "Error open file!" << endl;
	}
	else {
		cout << "Enter data: ";
		fWrite << "\n" << point;
		cout << "Data recorded!" << endl;
	}
	fWrite.close();
}

void outputFile() {
	ifstream fRead;

	fRead.open(path);
	if (!fRead.is_open()) {
		cout << "Error open file!" << endl;
	}
	else {
		cout << "File is open. Content:" << endl;
		//посимвольный вариант считывания
		/*char ch;
		while (fRead.get(ch)) { //метод get считывает посимвольно
		cout << ch;
		}*/
		//построчный вариант считывания
		//eof() - это функция, которая возвращает true, если обнаружен конец файла.
		string str;
		while (!fRead.eof()) {
			str = "";
			//fRead >> str;
			getline(fRead, str); // std::пропускает пробелы но учитывает '\n'
			cout << str << endl;
		}
	}
	fRead.close();
}

int main(int argc, char const *argv[]) {
	if (argc > 1) validateFlags(argv, argc);
	else printf("[+] Congratulations!\n");
	invokeCommands(argv, argc);

	/*Node *parentNode = new Node("node0", "root");
	Node *pointerToNode = new Node("node1", 8, parentNode);
	pointerToNode = new Node("node2", "bar", parentNode);
	pointerToNode = new Node("node3", 2.015, pointerToNode);
	pointerToNode = new Node("node4", "baz", pointerToNode);
	parentNode->print();
	delete parentNode;*/


	return 0;
}