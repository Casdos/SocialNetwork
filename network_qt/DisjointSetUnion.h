#pragma once
#include "constant.h"
#include <vector>

class DisjointSetUnion {
private:
    std::vector<int> parent, rank;
    int size;

public:
    DisjointSetUnion(int size) : parent(size), rank(size, 0) ,size(size){
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Â·¾¶Ñ¹Ëõ
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                std::swap(rootX, rootY);
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY])
                rank[rootX]++;
        }
    }

    void buildConnectionsFromMatrix(int** matrix, int size);
    std::vector<int> displaySets();
    std::vector<int> getElementsInSet(int root);
};
