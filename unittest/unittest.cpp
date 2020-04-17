// Created by kolane on 2020/2/6.

#include "../include/Lottery.h"
#include "/usr/local/include/gtest/gtest.h"

 TEST(LettryTest, AddStaffTest)
 {
     Lottery lottery;
     lottery.AddStaff(1001, "小明", "一部", "mcp");
     EXPECT_TRUE("小明" == lottery.LotteryStart("first_prize"));
 }

TEST(Lew, add)
{
    EXPECT_EQ(1,12);
}