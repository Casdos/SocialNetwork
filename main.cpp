#define _CRT_SECURE_NO_WARNINGS     

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include "constant.h"

using namespace std;

class Person {
public:
	string name;
	struct Point point;
	Person(string n, int a, Sex s, Job j) :name(n), point{a,s,j} {};
	Person() {};
};

class Cluster {
public:
	vector<Person> people;
	Cluster(const Person& p) :people({ p }) {}
	void addPerson(const Person& p) {
		people.push_back(p);
	}
};

// 采用曼哈顿距离聚类
double manhattanDistance(const Person& p1, const Person& p2) {
	return abs(p1.point.age - p2.point.age) +
		fabs(p1.point.job - p2.point.job) +
		fabs(p1.point.sex - p2.point.sex);
}

void hierarchicalClustering(vector<Person>& people) {
	if (people.empty()) return;
	vector<Cluster> clusters;
	for (const auto& p : people) {
		clusters.emplace_back(p);
	}

	while (clusters.size() > 1) {
		int minDistance = INT_MAX;
		pair<int, int> nearClusters;
		for (int i = 0; i < clusters.size(); i++) {
			for (int j = i + 1; j < clusters.size(); j++) {
				int distance = INT_MAX;
				for (const auto& p1 : clusters[i].people) {
					for (const auto& p2 : clusters[j].people) {
						int dist = manhattanDistance(p1, p2);
						distance = min(distance, dist);
					}
				}
				if (distance < minDistance) {
					minDistance = distance;
					nearClusters = { i,j };
				}
			}
		}
		//cout << "minDistance:" << minDistance << endl;
		if (minDistance > Threshold) break;

		clusters[nearClusters.first].people.insert(clusters[nearClusters.first].people.end(),
			clusters[nearClusters.second].people.begin(),
			clusters[nearClusters.second].people.end());
		clusters.erase(clusters.begin() + nearClusters.second);

		//cout << "cluster.size() = " << clusters.size() << endl;
	}

	cout << "Final Clusters:" << endl;
	for (int i = 0; i < clusters.size(); i++) {
		cout << "Cluster" << i + 1 << ":";
		for (const auto& p : clusters[i].people) {
			cout << "\"" << p.name << "\",";
		}
		cout << endl;
	}
}
//vector<Person> people;
// initial a zero matrix 
//vector<vector<int>> matrix(MaxN, vector<int>(MaxN,0));

//初始化图
void init_people(vector<Person>& people) {
	people.push_back(Person("111", 25, female, student));
	people.push_back(Person("222", 30, male, doctor) );
	people.push_back(Person("333", 35,female, teacher) );
	people.push_back(Person("444", 25, male, student) );
	people.push_back(Person("555", 45, female, student) );
	people.push_back(Person("666", 46, male, teacher) );
	people.push_back(Person("777", 21, male, policeman));
}

void load(vector<Person>& people, string filepath) {
	ifstream file(filepath);

	if (!file.is_open()) {
		cerr << "无法打开文件！" << endl;
		return ;
	}

	string line;
	while (getline(file, line)) {
		istringstream iss(line);
		Person p;
		getline(iss, p.name, ',');
		iss >> p.point.age;
		iss.ignore();
		string sex;
		getline(iss, sex, ',');
		p.point.sex = str2sex(sex);
		string job;
		getline(iss, job);
		p.point.job = str2job(job);
		people.push_back(p);
	}
}

/*
void cluster_matrix() {
	double m[MaxN][MaxN] = { 0 };
	for (int i = 0; i < MaxN; i++) {
		for (int j = 0; j < MaxN; j++) {
			m[i][j] = manhattanDistance(people[i], people[j]);
		}
	}

}

void print_matrix(vector<vector<int>>& matrix) {
	for (auto& row : matrix) {
		for (int val : row) {
			cout << val << " ";
		}
		cout << endl;
	}
}
*/

int main() {
	vector<Person> people = {};
	init_people(people);
	//load(people,"data.csv");
	hierarchicalClustering(people);
	return 0;
}