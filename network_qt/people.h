#ifndef PEOPLE_H
#define PEOPLE_H
#include<QString>
#include<QFile>
#include<QTextStream>

enum Sex {
    male,
    female
};
enum Job {
    student,
    teacher,
    doctor = 4,
    nurse,
    policeman = 7,
    fireman,
    saler = 10
};
class People
{
public:
    People();
    std::string name;
    int age;
    Sex sex;
    Job job;
    People(std::string n, int a,Sex s, Job j) :name(n),age(a),sex(s),job(j){};

    Sex str2sex(const std::string& str); //导入性别
    Job str2job(const std::string& str);//导入职业
    double manhattanDistance( People& p2);//求二者距离

};

#endif // PEOPLE_H
