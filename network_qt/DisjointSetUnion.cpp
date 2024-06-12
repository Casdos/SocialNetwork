#include "DisjointSetUnion.h"
#include "constant.h"

void DisjointSetUnion::buildConnectionsFromMatrix(int** matrix, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) { // ���ھ����ǶԳƵģ�ֻ����������ǻ������ǲ���
			if (matrix[i][j] == 1) { // ���������ֵΪ1����ʾi��j֮����ֱ�ӹ�ϵ
				unite(i, j); // �ϲ�i��j���ڵļ���
			}
		}
	}
}

std::vector<int> DisjointSetUnion::displaySets() {
    std::vector<int> node;
    std::vector<int> rootCount(size, 0); // ��¼ÿ�����ڵ�ļ��ϴ�С

    // ����parent���飬����ÿ�����ϵĴ�С
    for (int i = 0; i < size; ++i) {
        int root = find(i);
        rootCount[root]++;
    }

    // ���ÿ�����ϵ���Ϣ
    for (int i = 0; i < size; ++i) {
        if (rootCount[i] > 0) {
            std::cout << "���ϵĸ��ڵ�: " << i << ", ���ϴ�С: " << rootCount[i] << std::endl;
            node.push_back(i);
        }
    }

    return node;
}
std::vector<int> DisjointSetUnion::getElementsInSet(int root) {
    std::vector<int> elementsInSet;
    for (int i = 0; i < size; ++i) {
        if (find(i) == root) { // ע�⣺����ֱ�ӱȽ�find(i)�Ľ����root����Ϊfind�ڲ�����·��ѹ��
            elementsInSet.push_back(i);
        }
    }
    return elementsInSet;
}
