// Copyright 2020 GHA Test Team

#include "Automata.h"
#include <gtest/gtest.h>

TEST(AutomataTest, InitialState) {
  Automata a;
  EXPECT_EQ(a.GetState(), Automata::Off);
}
TEST(AutomataTest, TurnOn) {
  Automata a;
  a.On();
  EXPECT_EQ(a.GetState(), Automata::On);
}
TEST(AutomataTest, TurnOff) {
  Automata a;
  a.On();
  a.Off();
  EXPECT_EQ(a.GetState(), Automata::Off);
}
TEST(AutomataTest, Coin) {
  Automata a;
  a.On();
  a.Coin(10);
  EXPECT_EQ(a.GetCash(), 10);
  a.Coin(20);
  EXPECT_EQ(a.GetCash(), 30);
}
TEST(AutomataTest, Cancel) {
  Automata a;
  a.On();
  a.Coin(50);
  a.Choice(1);
  a.Check();
  testing::internal::CaptureStdout();
  a.Cancel();
  std::string output = testing::internal::GetCapturedStdout();
  std::string expected = "succesfull canceled\n";
  EXPECT_EQ(output, expected);
  EXPECT_EQ(a.GetState(), Automata::On);
  EXPECT_EQ(a.GetCash(), 0);
}
TEST(AutomataTest, CheckSuccess) {
    Automata a;
    a.On();
    a.Coin(50);
    a.Choice(1);
    EXPECT_TRUE(a.Check());
    EXPECT_EQ(a.GetState(), Automata::Accept);
}
TEST(AutomataTest, Cook) {
    Automata a;
    a.On();
    a.Coin(30);
    a.Choice(2);
    a.Check();
    a.Cook();
    EXPECT_EQ(a.GetState(), Automata::Cook);
}
