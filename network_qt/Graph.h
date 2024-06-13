#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "constant.h"
#include "DisjointSetUnion.h"

class Graph {
public:
    explicit Graph(int vertices) : vertices(vertices) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // 对于无向图，边是双向的
    }

    void autoGenerateEdge(std::vector<Person> people);
    int** dispaly01Matrix();
    bool check(std::string name1, std::string name2, std::vector<Person> people, DisjointSetUnion &dsu);
    bool check(int pos1, int pos2, DisjointSetUnion &dsu);

private:
    int vertices;
    std::unordered_map<int, std::vector<int>> adjList; // 邻接表
};

