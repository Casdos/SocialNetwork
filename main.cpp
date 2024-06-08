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
	return 0.5*abs(p1.point.age - p2.point.age) +
		fabs(p1.point.job - p2.point.job) +
		fabs(p1.point.sex - p2.point.sex);
}

vector<Cluster> hierarchicalClustering(vector<Person>& people) {
	vector<Cluster> clusters;
	if (people.empty()) return clusters;	
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
	return clusters;
}

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

vector<vector<int>> generateMatrix01(int n, vector<Cluster> cluster) {
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	// 定义聚类的数量
	int ClassNum = cluster.size();
	// i 表示矩阵行,j表示矩阵列
	for (int i = 0; i < n; ++i) {
		// block 表示i属于cluater的第几块
		int block = 0;
		int sum = 0;
		for (int k = 0; k < ClassNum; k++) {
			sum += cluster[k].people.size();
			if (i < sum) { block = k; break; }
		}

		for (int j = i; j < sum; ++j) {
			double distance = manhattanDistance(cluster[block].people[i], cluster[block].people[j]);
			if (distance <= Threshold) {
				matrix[i][j] = 1;
				matrix[j][i] = 1; // 因为矩阵是对称的，所以也要更新j到i的关系			
			}			
		}
	}
	return matrix;
}

int PeopleNum(vector<Person>& people) {
	return people.size();
}

vector<string> Namelist(int n, vector<Cluster> cluster) {
	// 定义聚类的数量
	int ClassNum = cluster.size();
	vector<string> namelist;

	for (int i = 0; i < ClassNum; i++) {
		for (int j = 0; j < cluster[i].people.size(); j++)
			namelist.push_back(cluster[i].people[j].name);
	}
	return namelist;
}

int main() {
	// num shows people number
	int num = 0;

	vector<Person> people = {};	
	//init_people(people);
	load(people,"data.csv");
	vector<Cluster> cluster = hierarchicalClustering(people);
	vector<vector<int>> matrix = generateMatrix01(PeopleNum(people), cluster);

	for (const auto& row : matrix) {
        for (int val : row) {
			 std::cout << val << " ";
			
		}
       std::cout << std::endl;
	}
	return 0;
}