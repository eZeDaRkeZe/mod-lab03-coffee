// Copyright 2020 GHA Test Team

#include "Automata.h"

using std::cout;
using std::string;
using std::endl;

static void PrintInfo(STATES state) {
    switch (state) {
        case OFF:
            cout << "Automata is off" << endl;
            break;
        case WAIT:
            cout << "Automata is waiting for order" << endl;
            break;
        case ACCEPT:
            cout << "Select the menu item" << endl;
            break;
        case CHECK:
            cout << "Financial check" << endl;
            break;
        case COOK:
            cout << "Cooking" << endl;
            break;
        default:
            break;
    }
}

void Automata::Choice(int pos) {
    if (pos <= MENU_SIZE && pos > 0) {
        if (state == ACCEPT) {
            state = CHECK;
            position = pos - 1;
        }
    } else {
        cout << "Invalid value entered" << endl;
    }
    PrintInfo(state);
}

void Automata::On() {
    state = On;
    std::cout << "Automata is turned on." << std::endl;
}

void Automata::Off() {
    state = OFF;
    std::cout << "Automata is turned off." << std::endl;
}

void Automata::Coin(double money) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += money;
    }
    PrintInfo(state);
}

bool Automata::Check() {
    if (cash >= prices[chosen]) {
        return true;
    } else {
        std::cout << "Not enough money." << std::endl;
        state = ON;
        return false;
    }
}

int Automata::Cancel() {
    if (state == ACCEPT || state == CHECK) {
        position = -1;
        state = WAIT;
        double change = cash;
        cash = 0;
        PrintInfo(state);
        return change;
    }
    return -1;
}

void Automata::Cook() {
    if (state == COOK)  {
        cash -= prices[position];
        cout << "Processing..." << endl;
    }
}

void Automata::Finish() {
    if (state == COOK) {
        state = WAIT;
    }
    PrintInfo(state);
}
