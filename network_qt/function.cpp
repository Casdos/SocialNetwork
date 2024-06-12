#include "constant.h"
#include <vector>
#include <fstream>
#include <sstream>

std::map<std::string, Sex> SexMap = {
	{"male",Sex::male},
	{"female",Sex::female}
};
Sex str2sex(const std::string& str) {
	auto it = SexMap.find(str);
	if (it != SexMap.end()) {
		return it->second;
	}
	else {
		throw std::invalid_argument("Invalid color string");
	}
}
std::map<std::string, Job> JobMap = {
	{"student",Job::student},
	{"teacher",Job::teacher},
	{"doctor",Job::doctor},
	{"nurse",Job::nurse},
	{"policeman",Job::policeman},
	{"fireman",Job::fireman},
	{"saler",Job::saler}
};
Job str2job(const std::string& str) {
	auto it = JobMap.find(str);
	if (it != JobMap.end()) {
		return it->second;
	}
	else {
		throw std::invalid_argument("Invalid color string");
	}
}

void Load(std::vector<Person>& people, std::string filepath) {
	std::ifstream file(filepath);

	if (!file.is_open()) {
		std::cerr << "无法打开文件！" << std::endl;
		return;
	}

	std::string line;
	int i = 0;
	while (getline(file, line)) {
		Person currentPerson;
		std::istringstream iss(line);
		getline(iss, currentPerson.name, ',');
		//std::cout << "name: " << currentPerson.name << std::endl;
		iss >> currentPerson.point.age;
		//std::cout << "age: " << currentPerson.point.age << std::endl;
		iss.ignore(); // 默认丢弃后一个字符
		std::string sex;
		getline(iss, sex, ',');
		//std::cout << "sex: " << sex << std::endl;
		currentPerson.point.sex = str2sex(sex);
		std::string job;
		getline(iss, job);
		//std::cout << "job: " << job << std::endl;
		currentPerson.point.job = str2job(job);
		people.push_back(currentPerson);
	}
	
	file.close();
}

double manhattanDistance(const Person& p1, const Person& p2) {
	return 0.5 * abs(p1.point.age - p2.point.age) +
		fabs(p1.point.job - p2.point.job) +
		fabs(p1.point.sex - p2.point.sex);
}

void printSquareMatrix(int** matrix, int a) {
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < a; ++j) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}