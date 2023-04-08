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
    if (state == OFF) {
        state = WAIT;

        cout << "Menu of Automata" << endl;
        for (int i = 0; i < MENU_SIZE; i++)  {
            cout << i + 1 << " position: " << menu[i] << endl;
        }
    }
    PrintInfo(state);
}

void Automata::Off() {
    if (state == WAIT) {
        state = OFF;
    }
    PrintInfo(state);
}

void Automata::Coin(double money) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += money;
    }
    PrintInfo(state);
}

void Automata::Check() {
    if (state == CHECK) {
        cout << "---" << cash << endl;
        if (cash >= prices[position]) {
            state = COOK;
        } else {
            cout << "Not enough money" << endl;
            position = -1;
            state = WAIT;
        }
    }
    PrintInfo(state);
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