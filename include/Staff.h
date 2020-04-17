//
// Created by kolane on 2020/2/3.
//

#ifndef staff_H
#define staff_H

#include <string>
#include <vector>

using namespace std;

enum Awards
{
    no_prize = 0,
    first_prize,
    second_prize,
    third_prize,
    common_prize,
    super_prize
};

struct Staff
{
    int job_number = 0;
    string name = "";
    string department = "";
    string team = "";
    int weight = 1;
    Awards awards = no_prize;
};
#endif //staff_H