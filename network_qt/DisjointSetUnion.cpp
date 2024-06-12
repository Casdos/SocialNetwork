#include "DisjointSetUnion.h"
#include "constant.h"

void DisjointSetUnion::buildConnectionsFromMatrix(int** matrix, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) { // 由于矩阵是对称的，只需遍历上三角或下三角部分
			if (matrix[i][j] == 1) { // 如果矩阵中值为1，表示i和j之间有直接关系
				unite(i, j); // 合并i和j所在的集合
			}
		}
	}
}

std::vector<int> DisjointSetUnion::displaySets() {
    std::vector<int> node;
    std::vector<int> rootCount(size, 0); // 记录每个根节点的集合大小

    // 遍历parent数组，计算每个集合的大小
    for (int i = 0; i < size; ++i) {
        int root = find(i);
        rootCount[root]++;
    }

    // 输出每个集合的信息
    for (int i = 0; i < size; ++i) {
        if (rootCount[i] > 0) {
            std::cout << "集合的根节点: " << i << ", 集合大小: " << rootCount[i] << std::endl;
            node.push_back(i);
        }
    }

    return node;
}
std::vector<int> DisjointSetUnion::getElementsInSet(int root) {
    std::vector<int> elementsInSet;
    for (int i = 0; i < size; ++i) {
        if (find(i) == root) { // 注意：这里直接比较find(i)的结果与root，因为find内部做了路径压缩
            elementsInSet.push_back(i);
        }
    }
    return elementsInSet;
}
