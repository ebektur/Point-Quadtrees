#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;


vector<string> found;
vector<string> visited;

struct Node {
	int x, y;
	string city_name;
	Node* SE;
	Node* SW;
	Node* NE;
	Node* NW;

	Node(int coordx, int coordy, Node* SE, Node* SW, Node* NE, Node* NW, string city)
		:x(coordx), y(coordy), SE(SE), SW(SW), NE(NE), NW(NW), city_name(city) {}


	Node()
	{
		Node* SE = nullptr;
		Node* SW = nullptr;
		Node* NE = nullptr;
		Node* NW = nullptr;
		x = 0;
		y = 0;

	}

	Node(string c, int x, int y) : city_name(c), x(x), y(y)
	{
		Node* SE = nullptr;
		Node* SW = nullptr;
		Node* NE = nullptr;
		Node* NW = nullptr;
	}
	//~Node() {
	//
	//	/*makeEmpty(root);*/
	//
	//}



	//pointers for directions (+ children of BST)

	////root
	//Node* root;
	//Node* results;

	//void Insert(const Node& x, Node* root);
	//void insert(const Node& x);
	//void search(int x, int y, int r);
	//void Search_sec(int x, int y, int r, Node* root);
	//void makeEmpty(Node* x);

	//create

	//results vector



};


class Tree {
public:
	explicit Tree(const string& notFound);
	Tree(const Tree& rhs);
	~Tree();

	void MakeEmpty();
	void insert(int x, int y, string s);
	void search(int x, int y, unsigned int r);
	void PrintTree();


	bool isInAreaSE(int x, int y, int r, Node* t);
	bool isInAreaSW(int x, int y, int r, Node* node);
	bool isInAreaNE(int x, int y, int r, Node* node);
	bool isInAreaNW(int x, int y, int r, Node* node);

private:

	Node* root;
	const string ITEM_NOT_FOUND;



	void insert(int x, int y, string s, Node*& t);
	void search(int x, int y, unsigned int r, Node* t);
	void MakeEmpty(Node*& t) const;
	void PrintTree(Node* t);
	bool isInside(int x, int y, unsigned int rad, Node* t);


};

Tree::Tree(const string& notFound) : ITEM_NOT_FOUND(notFound), root(nullptr) {}

Tree::~Tree() {

	MakeEmpty();
}


/**
  * Insert x into the tree; duplicates are ignored.
  */

void Tree::insert(int x, int y, string s)
{
	insert(x, y, s, root);
}


bool Tree::isInside(int x, int y, unsigned int rad, Node* t)
{

	if ((t->x - x) * (t->x - x) + (t->y - y) * (t->y - y) <= rad * rad)
	{
		return true;
	}

	return false;
}

bool Tree::isInAreaSE(int x, int y, int r, Node* node)
{
	if (x - r > node->x && y < node->y) //?
	{
		return true;
	}
	if (x + r > node->x && y < node->y)
	{
		return true;
	}
	if (x > node->x && y + r < node->y)
	{
		return true;
	}
	if (x > node->x && y - r <= node->y) //?
	{
		return true;
	}

	return false;


}

bool Tree::isInAreaSW(int x, int y, int r, Node* node)
{
	if (x - r <= node->x && y < node->y) //check equality
	{
		return true;
	}
	if (x + r < node->x && y < node->y)
	{
		return true;
	}
	if (x < node->x && y + r < node->y)
	{
		return true;
	}
	if (x < node->x && y - r < node->y)
	{
		return true;
	}

	return false;
}

bool Tree::isInAreaNE(int x, int y, int r, Node* node)
{

	if (x - r > node->x && y > node->y)
	{
		return true;
	}
	if (x + r >= node->x && y > node->y)
	{
		return true;
	}
	if (x > node->x && y + r > node->y)
	{
		return true;
	}
	if (x > node->x && y - r > node->y)
	{
		return true;
	}

	return false;
}


bool Tree::isInAreaNW(int x, int y, int r, Node* node)
{

	if (x - r <= node->x && y > node->y) //?
		return true;
	if (x + r < node->x && y > node->y)
		return true;
	if (x < node->x && y + r > node->y)
		return true;
	if (x < node->x && y - r > node->y)
		return true;

	return false;
}

void Tree::search(int x, int y, unsigned int r)
{

	search(x, y, r, root);

}

void Tree::search(int x, int y, unsigned int rad, Node* t)
{

	if (t == nullptr)
	{
		return;
	}

	visited.push_back(t->city_name);

	if ((t->x - x) * (t->x - x) + (t->y - y) * (t->y - y) <= rad * rad) //if it is inside
	{
		found.push_back(t->city_name);
		//return;

	}
	if (isInAreaSE(x, y, rad, t) == true)
	{
		search(x, y, rad, t->SE);
	}

	if (isInAreaSW(x, y, rad, t) == true)
	{
		search(x, y, rad, t->SW);
	}

	if (isInAreaNE(x, y, rad, t) == true)
	{
		search(x, y, rad, t->NE);
	}

	if (isInAreaNW(x, y, rad, t) == true)
	{
		search(x, y, rad, t->NW);
	}
}


//if (x - rad < t->x && y + rad > t->y) //NW 1

//	if(t->x < x - rad && t->y > y + rad)
//	{
//		//visited.push_back(t->city_name);
//		search(x, y, rad, t->SE);
//	/*	search(x, y, rad, t->NW);*/
//		return;
//	}
//
//	//if (x == t->x && y < t->y) //2
//	
//	if(t->x > x - rad && t->y > y + rad)
//	{
//		//visited.push_back(t->city_name);
//		search(x, y, rad, t->SE);
//		search(x, y, rad, t->SW);
//		//search(x, y, rad, t->NE);
//		//search(x, y, rad, t->NW);
//
//
//	}
//
//
//	if(t->x > x + rad && t->y > y +rad) //3
//	{
//		//visited.push_back(t->city_name);
//		search(x, y, rad, t->SW);
//		//search(x, y, rad, t->NE);
//
//	}
//
//	//if (x > t->x && y == t->y) //4
//
//	if(t->y > y - rad && t->x < x -rad)
//	{
//		//visited.push_back(t->city_name);
//		search(x, y, rad, t->SE);
//		search(x, y, rad, t->NE);
//		//search(x, y, rad, t->SW);
//		//search(x, y, rad, t->NW);
//
//	}
//
//
//	//if (x < t->x && y == t->y) //5
//	if(t->x > x + rad && t->y < y + rad)
//	{
//		//visited.push_back(t->city_name);
//		search(x, y, rad, t->SW);
//		search(x, y, rad, t->NW);
//		//search(x, y, rad, t->SE);
//		//search(x, y, rad, t->NE);
//
//
//	}
//
//
//	//if (x - rad > t->x && y - rad > t->y) //6
//	if (x - rad > t->x && y - rad > t->y)
//	{
//
//		//visited.push_back(t->city_name);
//		search(x, y, rad, t->NE);
//		/*search(x, y, rad, t->SW);*/
//		return;
//	}
//
//
//	//if (x == t->x && y > t->y) //7
//	if(t->x < x + rad && t->y < y - rad)
//	{
//		//visited.push_back(t->city_name);
//		search(x, y, rad, t->NE);
//		search(x, y, rad, t->NW);
//		//search(x, y, rad, t->SE);
//		//search(x, y, rad, t->SW);
//
//	}
//
//
//	if (x + rad < t->x && y - rad > t->y) //8
//	{
//		//visited.push_back(t->city_name);
//		search(x, y, rad, t->NW);
//		/*search(x, y, rad, t->SE);*/
//	}
//
//	if (x - rad < t->x && y + rad > t->y && isInside(x, y, rad, t) == false) //NW 9
//	{
//		//visited.push_back(t->city_name);
//		search(x, y, rad, t->SE);
//		search(x, y, rad, t->SW);
//		search(x, y, rad, t->NE);
//
//		//search(x, y, rad, t->SW);
//		//search(x, y, rad, t->NE);
//		//search(x, y, rad, t->NW);
//
//		return;
//	}
//
//	if (x + rad > t->x && y + rad > t->y && isInside(x, y, rad, t) == false) //NE y=, 10
//	{
//
//		//visited.push_back(t->city_name);
//		search(x, y, rad, t->SE);
//		search(x, y, rad, t->SW);
//		search(x, y, rad, t->NW);
//
//
//		//search(x, y, rad, t->SE);
//		//search(x, y, rad, t->NE);
//		//search(x, y, rad, t->NW);
//
//		return;
//	}
//
//	if (x - rad < t->x && y - rad < t->y && isInside(x, y, rad, t) == false) //SW 11
//	{
//
//		//visited.push_back(t->city_name);
//		search(x, y, rad, t->SE);
//		search(x, y, rad, t->NE);
//		search(x, y, rad, t->NW);
//
//		//search(x, y, rad, t->SE);
//		//search(x, y, rad, t->SW);
//		//search(x, y, rad, t->NW);
//
//		return;
//	}
//
//
//
//	if (x + rad > t->x && y - rad < t->y && isInside(x, y, rad, t) == false) //SE x= ,12
//	{
//		//visited.push_back(t->city_name);
//
//		search(x, y, rad, t->SW);
//		search(x, y, rad, t->NE);
//		search(x, y, rad, t->NW);
//
//		//search(x, y, rad, t->SE);
//		//search(x, y, rad, t->SW);
//		//search(x, y, rad, t->NE);
//
//		return;
//	}
//
//
//	if ((t->x - x) * (t->x - x) + (t->y - y) * (t->y - y) <= rad * rad) //if it is inside
//	{
//		found.push_back(t->city_name);
//		//visited.push_back(t->city_name);
//		return;
//
//	}
//
//
//}









//
//
//
//void Tree::search(int x, int y, unsigned int rad, Node* t)
//{
//
//	//upper-right,
//	//if(((t->x + rad) > x && (t->y + rad) > y) || 
//
//	if (t == nullptr)
//	{
//		return;
//	}
//
//
//	if ((t->x - x) * (t->x - x) + (t->y - y) * (t->y - y) <= rad * rad) //if it is inside
//	{
//		found.push_back(t->city_name);
//		visited.push_back(t->city_name);
//		return;
//
//	}
//
//
//	//else if (y < t->y) //SE,SW
//	//{
//	//	visited.push_back(t->city_name);
//	//	search(x, y, rad, t->SE);
//	//	visited.push_back(t->city_name);
//	//	search(x, y, rad, t->SW);
//	//	return;
//	//}
//
//	//else if (x < t->x) //SW,NW
//	//{
//	//	visited.push_back(t->city_name);
//	//	search(x, y, rad, t->SW);
//	//	//visited.push_back(t->city_name);
//	//	search(x, y, rad, t->NW);
//	//	return;
//	//}
//
//
//	if (x >= t->x && y < t->y) //SE
//	{
//		visited.push_back(t->city_name);
//		search(x, y, rad, t->SE);
//		return;
//	}
//
//	if (x > t->x && y >= t->y) //NE //y=
//	{
//		
//		visited.push_back(t->city_name);
//		search(x, y, rad, t->SE);
//		search(x, y, rad, t->NE);
//		//search(x, y, rad, t->SE);
//		return;
//	}
//
//	if (x < t->x && y < t->y) //SW
//	{
//		
//		visited.push_back(t->city_name);
//		search(x, y, rad, t->SE);
//		search(x, y, rad, t->SW);
//		search(x, y, rad, t->NW);
//		return;
//	}
//
//	if (x < t->x && y > t->y) //NW
//	{
//		
//		visited.push_back(t->city_name);
//		
//		//search(x, y, rad, t->SW);
//		search(x, y, rad, t->NW);
//
//		return;
//	}
//
//}

void PrintVectors() //print the visited and found, later empty.
{
	if (found.empty() == true)
	{
		cout << "‘<None>’" << endl;

		//cout << "VISITED: " << endl;
		//cout << endl;
		for (int i = 0; i < visited.size() - 1; i++)
		{
			cout << visited.at(i) << ", ";
		}

		cout << visited.at(visited.size() - 1);

		cout << endl;
		cout << endl;

		return;
	}

	//cout << endl;

	for (int i = 0; i < found.size() - 1; i++)
	{
		cout << found.at(i) << ", ";
	}
	cout << found.at(found.size() - 1);

	cout << endl;
	//cout << "VISITED: " << endl;

	for (int i = 0; i < visited.size() - 1; i++)
	{
		cout << visited.at(i) << ", ";
	}
	cout << visited.at(visited.size() - 1);

	cout << endl;
	cout << endl;

	found.clear();
	visited.clear();
}



void Tree::insert(int x, int y, string s, Node*& t) { //private insert. t==root x == node

	if (t == nullptr)
	{
		string a = s;
		int xx = x;
		int yy = y;

		t = new Node(xx, yy, nullptr, nullptr, nullptr, nullptr, a);
	}


	else if (x < t->x && y < t->y) //SW, 
	{
		insert(x, y, s, t->SW);

	}

	else if (x >= t->x && y >= t->y)//NE
	{
		insert(x, y, s, t->NE);

	}

	else if (x >= t->x && y < t->y)//SE
	{
		insert(x, y, s, t->SE);

	}

	else if (x < t->x && y >= t->y) //NW
	{
		insert(x, y, s, t->NW);
	}

	else {

	}

}

void Tree::MakeEmpty()
{
	MakeEmpty(root);
}

void Tree::PrintTree()
{
	PrintTree(root);
}

void Tree::PrintTree(Node* t)
{
	if (t != NULL)
	{
		PrintTree(t->NW);
		cout << t->city_name << endl;
		PrintTree(t->NE);
		cout << t->city_name << endl;
		PrintTree(t->SW);
		cout << t->city_name << endl;
		PrintTree(t->SE);


	}


}

void Tree::MakeEmpty(Node*& t) const
{
	if (t != NULL)
	{
		MakeEmpty(t->SE);
		MakeEmpty(t->SW);
		MakeEmpty(t->NE);
		MakeEmpty(t->NW);
		delete t;
	}
	t = NULL;

}
