#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include "Binary_Tree.h"
#include "Translator.h"
using namespace std;

string DECODE(Binary_Tree<string>& tree, BTNode<string>* root, const BTNode<string>* start, string& to_decode, string& result, const int& i) {

	char morse = to_decode[i];

	if (morse == '*') {
		root = root->left;
	}

	if (morse == '-') {
		root = root->right;
	}
	if (morse == ' ' || i == to_decode.size() - 1) {
		result += root->data;
		root = tree.getRoot();
	}

	if (i == to_decode.size() - 1) {
		return result;
	}

	return DECODE(tree, root, start, to_decode, result, i + 1);

}

string DECODE_Wrapper(Binary_Tree<string>& tree, string& to_decode) {
	BTNode<string>* root = tree.getRoot();
	const BTNode<string>* start = root;
	const int i = 0;
	string result;

	return DECODE(tree, root, start, to_decode, result, i);
}

int main() {

	Translator t("morse.txt");
	t.buildTree();
	Binary_Tree<string> tree = t.getTree();
	
	/*vector<string> expression{"Empty", "e", "i", "s", "h", "NULL" , "NULL" , "v", "NULL" , "NULL" , "u", "f", "NULL" , "NULL" , "NULL" , "a" , "r", "l", "NULL", "NULL" , "NULL" ,"w", "p", "NULL", "NULL", "j", "NULL", "NULL", "t", "n", "d", "b", "NULL" , "NULL" , "x", "NULL" , "NULL" , "k", "c", "NULL" , "NULL" , "q", "NULL" , "NULL" , "o" , "NULL" , "NULL" };
	Binary_Tree<string> tree;
	tree.read_tree(expression);*/

	string word = "*** **- *-* *-- -** -*- --* ---";
	string decode = DECODE_Wrapper(tree, word);

	cout << decode;


	cin.get();
	return 0;
}
