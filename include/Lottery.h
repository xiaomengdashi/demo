//
// Created by kolane on 2020/2/3.
//

#ifndef LOTTERY_LOTTERY_H
#define LOTTERY_LOTTERY_H

#include <string>
#include <vector>
#include "Staff.h"

using namespace std;

class Lottery
{
public:
    Lottery();
    ~Lottery();
    void PrintStaff();    // 打印全体员工信息
    int GetRandomNum();   // 根据权重获取随机数
    void AddStaff(int job_number, string name, string department, string team);  // 增加员工
    void DeleteStaff(const string& name);    // 剔除指定员工
    void DoubleStaff(const string& name="");    // 优秀个人翻倍抽奖
    void DoubleTeam(const string& team="");     // 优秀团队翻倍抽奖
    void GobackLottery(string goback_type="NoGoback");   // 中奖人员回归奖池

    string LotteryStart(const string& prize, const string& department="", const string& team="");   // 开始抽奖

private:
    string DepartmentLottery(const string& department, string prize);  // 指定部门抽奖
    string TeamLottery(const string& team, string prize);              // 指定团队抽奖
    string JustLottery(string prize);    // 不指定团队，也不指定部门

private:
    vector<Staff> staff_;
    int staff_num_ = 0;
};
#endif //LOTTERY_LOTTERY_H
