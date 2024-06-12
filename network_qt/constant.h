#pragma once
#include<iostream>
#include<map>

enum Sex {
	male,
	female
};
Sex str2sex(const std::string& str);
// parameters set randomly, in fact, they need identification
enum Job {
	student,
	teacher,
	doctor = 4,
	nurse,
	policeman = 7,
	fireman,
	saler = 10
};
Job str2job(const std::string& str);

struct Point {
	int age;
	Sex sex;
	Job job;
};
struct Person {
	std::string name;
	Point point;
};

extern std::map<std::string, Job> JobMap;
extern std::map<std::string, Sex> SexMap;

const int Threshold = 5;