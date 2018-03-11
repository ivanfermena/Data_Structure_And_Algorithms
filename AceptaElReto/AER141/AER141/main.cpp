// Ivan Fernandez Mena
// E13

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <string>

bool comprobarSimetria(std::string strText) {

	std::stack<char> simbolStack;
	int control = 0;

	for (char c : strText) {
		if ((c == '(')||((c == '[')|| (c == '{')))
			simbolStack.push(c);
		else if((c == ')') || ((c == ']') || (c == '}')))
			simbolStack.push(c);

		if(!simbolStack.empty()) {
			if (c == ')') {
				simbolStack.pop();
				control++;
				if (!simbolStack.empty() && simbolStack.top() == '(') {
					simbolStack.pop();
					control--;
				}	
			}
			else if (c == ']') {
				simbolStack.pop();
				control++;
				if (!simbolStack.empty() && simbolStack.top() == '[') {
					simbolStack.pop();
					control--;
				}
			}
			else if (c == '}') {
				simbolStack.pop();
				control++;
				if (!simbolStack.empty() && simbolStack.top() == '{') {
					simbolStack.pop();
					control--;
				}
			}
		}
	}

	if ((simbolStack.empty()) && (control == 0))
		return true;

	return false;
}

bool resuelveCaso() {

	std::string strSelect;

	getline(std::cin,strSelect, '\n');

	if (!std::cin)
		return false;

	if (comprobarSimetria(strSelect)) std::cout << "YES\n";
	else std::cout << "NO\n";

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

#ifndef DOMJUDGE 
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}