#include "Graph.h"
#include "DisjointSetUnion.h"
#include "constant.h"

double manhattanDistance(const Person& p1, const Person& p2);
void printSquareMatrix(int** matrix, int a);

void Graph::autoGenerateEdge(std::vector<Person> people) {
	for (int i = 0; i < vertices; ++i) {
		for (int j = i; j < vertices; ++j) {
			if (manhattanDistance(people[i], people[j]) < Threshold) { addEdge(i, j); }
		}
	}
}

int** Graph::dispaly01Matrix() {
	int** matrix = new int* [vertices];
	for (int i = 0; i < vertices; ++i) {
		matrix[i] = new int[vertices](); // 为每一行分配内存并初始化为0
	}
	for (int i = 0; i < vertices; ++i) {
		for (int neighbor : adjList[i]) {
			matrix[i][neighbor] = 1; // 直接设置为1，因为邻接表中已经包含了所有邻接点
		}
	}
	printSquareMatrix(matrix, vertices);
	return matrix;
}

bool Graph::check(std::string name1, std::string name2, std::vector<Person> people, DisjointSetUnion& dsu) {
	int size = people.size();
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < size; i++) {
		if (name1 == people[i].name){
			num1 = i;
			break;
		}	
	}
	for (int i = 0; i < size; i++) {
		if (name2 == people[i].name) {
			num2 = i;
			break;
		}
	}
	if (dsu.find(num1) == dsu.find(num2)) return true;
	else return false;
}