// Copyright 2020 GHA Test Team

#pragma once
#include <iostream>
#include <string>
#include <array>

using std::string;
using std::array;

const int MENU_SIZE = 8;

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
 public:
    Automata() {
        state = OFF;
        cash = 0;
        menu = {
            "Black tea",
            "Americano",
            "Cappuccino",
            "Latte",
            "Flat white",
            "Espresso",
            "Hot chocolate",
            "Water"
        };
        prices = { 50, 120, 100, 125, 125, 100, 25 };
        position = -1;
    }

    array<string, MENU_SIZE> GetMenu() {
        return menu;
    }

    STATES GetState() {
        return state;
    }

    double GetCash() {
        return cash;
    }

    void On();
    void Off();
    void Coin(double money);
    void Choice(int position);
    void Check();
    int Cancel();
    void Cook();
    void Finish();

 private:
    STATES state;
    double cash;
    array<string, MENU_SIZE> menu;
    array<int, MENU_SIZE> prices;
    int position;
};
