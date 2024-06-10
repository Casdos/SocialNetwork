#ifndef CLUSTER_H
#define CLUSTER_H
#include<vector>
#include"people.h"
#include<QDebug>
class Cluster
{
public:
    Cluster();
    std::vector<People> peoples;
    Cluster(const People& p) :peoples({ p }) {}
    void addPerson(const People& p) ;
    std::vector<Cluster> hierarchicalClustering(Cluster peo);
    int Threshold = 5;
    friend std::vector<std::vector<int>> generateMatrix01(int n, std::vector<Cluster> cluster);
    void load(std::string filepath);
};

#endif // CLUSTER_H
