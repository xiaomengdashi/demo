//
// Created by kolane on 2020/2/3.
//

#include <iostream>
#include "../include/Lottery.h"
#include <ctime>
#include <random>
#include <utility>

using namespace std;

Lottery::Lottery()= default;

Lottery::~Lottery()= default;

int Lottery::GetRandomNum()
{
    int sum = 0;
    vector<int> w(staff_num_);
    vector<int> vec_sum(0);

    for (int i=0; i<staff_num_; i++)
    {
        w[i] = staff_[i].weight;
    }

    for (int i=0; i<staff_num_; i++)
    {
        sum += staff_[i].weight;
        vec_sum.push_back(sum);
    }

    static std::default_random_engine engine(time(NULL));
    std::uniform_int_distribution<int> u(0, sum-1);
    int target = u(engine);

    int k = 0;
    for (; k < vec_sum.size(); k++)
    {
        if (target < vec_sum[k])
        {
            break;
        }
    }
    return k;
}

void Lottery::PrintStaff()
{
    for (auto & it : staff_)
    {
        cout << " "<< it.job_number << " "<< it.name << " "
             << it.department << " "<< it.team << " "<< it.awards
             << endl;
    }
}

void Lottery::AddStaff(int job_number, string name, string department, string team)
{
    Staff staff;
    staff.job_number = job_number;
    staff.name = std::move(name);
    staff.department = std::move(department);
    staff.team = std::move(team);

    staff_.push_back(staff);
    staff_num_++;
}

void Lottery::DeleteStaff(const string& name)
{
    for (auto it = staff_.begin(); it != staff_.end(); it++)
    {
        if (it->name == name)
        {
            it = staff_.erase(it);
            staff_num_ -= 1;
            if (it == staff_.end())
                break;
        }
    }
}

void Lottery::DoubleStaff(const string& name)
{
    for (int i = 0; i<staff_num_; i++)
    {
        if (staff_[i].name == name)
        {
            staff_[i].weight = 2;
        }
    }
}

void Lottery::DoubleTeam(const string& team)
{
    for (int i = 0; i<staff_num_; i++)
    {
        if (staff_[i].team == team)
        {
            staff_[i].weight = 2;
        }
    }
}

void Lottery::GobackLottery(string goback_type)
{
    if (goback_type == "AllGoback")      //  全部回归奖池
    {
        for (auto &it : staff_)
        {
            it.awards = no_prize;
            //TODO 有bug，当人员翻倍之后，并中奖了，这时回归奖池，并没有回到翻倍的状态，可以通过再添加一个字段Is_Win来判断是否中奖
            it.weight = 1;
        }
    } else if (goback_type == "SuperPrizeGoback")    // 抽特等奖时，三等奖和阳光普照奖回归
    {
        for (auto &it : staff_)
        {
            if (it.awards == 3 || it.awards == 4)
            {
                it.awards = no_prize;
                it.weight = 1;
            }
        }
    }      // 如果都不是，则按照默认的抽奖
}

string Lottery::JustLottery(string prize)
{
    int random_id = GetRandomNum();
    if (!staff_[random_id].awards)
    {
        if (prize == "first_prize")
            staff_[random_id].awards = first_prize;
        else if (prize == "second_prize")
            staff_[random_id].awards = second_prize;
        else if (prize == "third_prize")
            staff_[random_id].awards = third_prize;
        else if (prize == "super_prize")
            staff_[random_id].awards = super_prize;
        else if (prize == "common_prize")
            staff_[random_id].awards = common_prize;

        staff_[random_id].weight = 0;
        return staff_[random_id].name;
    }
    else
    {
        return this->JustLottery(std::move(prize));
    }
}

string Lottery::DepartmentLottery(const string& department, string prize)
{
    int random_id = GetRandomNum();
    if (staff_[random_id].department == department && !staff_[random_id].awards)
    {
        if (prize == "first_prize")
            staff_[random_id].awards = first_prize;
        else if (prize == "second_prize")
            staff_[random_id].awards = second_prize;
        else if (prize == "third_prize")
            staff_[random_id].awards = third_prize;
        else if (prize == "super_prize")
            staff_[random_id].awards = super_prize;
        else if (prize == "common_prize")
            staff_[random_id].awards = common_prize;

        staff_[random_id].weight = 0;
        return staff_[random_id].name;
    }
    else
    {
        return this->DepartmentLottery(department, std::move(prize));
    }
}

string Lottery::TeamLottery(const string& team, string prize)
{
    int random_id = GetRandomNum();
    if (staff_[random_id].team == team && !staff_[random_id].awards)
    {
        if (prize == "first_prize")
            staff_[random_id].awards = first_prize;
        else if (prize == "second_prize")
            staff_[random_id].awards = second_prize;
        else if (prize == "third_prize")
            staff_[random_id].awards = third_prize;
        else if (prize == "super_prize")
            staff_[random_id].awards = super_prize;
        else if (prize == "common_prize")
            staff_[random_id].awards = common_prize;

        staff_[random_id].weight = 0;
        return staff_[random_id].name;
    }
    else
    {
        return this->TeamLottery(team, std::move(prize));
    }
}

string Lottery::LotteryStart(const string& prize, const string& department, const string& team)
{
    if (!department.empty())
    {
        return this->DepartmentLottery(department, prize);
    }

    if (!team.empty())
    {
        return this->TeamLottery(team, prize);
    }

    return this->JustLottery(prize);
}

