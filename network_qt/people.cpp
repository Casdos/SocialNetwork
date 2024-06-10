#include "people.h"

People::People() {}
Sex People::str2sex(const std::string& str)
{
    if(str=="male")
    return male;
    else
        return female;
}
Job People::str2job(const std::string& str)
{
    if(str=="student")
        return student;
    else if(str=="teacher")
        return teacher;
    else if(str=="doctor")
        return doctor;
    else if(str=="nurse")
        return nurse;
    else if(str=="policeman")
        return policeman;
    else if(str=="fireman")
        return fireman;
    else
        return saler;
}
 double People::manhattanDistance( People& p2)
{
    return 0.5*abs(this->age - p2.age) +
           fabs(this->job - p2.job) +
           fabs(this->sex - p2.sex);
}

