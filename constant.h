#pragma once
#include<iostream>
#include<map>
enum Sex {
	male,
	female
};
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
struct Point {
	int age;
	Sex sex;
	Job job;
};

const int Threshold = 5;