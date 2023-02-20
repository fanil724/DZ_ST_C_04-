#pragma once

#include <string>
#include <time.h>

using namespace std;
enum PART_OF_DAY {
    Night = 0, Morning, Day, Evening
};

class People {
public:
    People() {};

    People(int t) : People() { this->next = this->next->next, this->tCome = t; };

    People(People &&another) noexcept = default;

    People &operator=(People &&another) noexcept = default;

    ~People() {};
    People *next;
    int tCome;

    void add(int t) {
        if (this->next != nullptr) {
            this->next->add(t);
        } else {
            this->next = new People(t);
        }
    }
};

class Peoples {
public:
    Peoples() {
        this->countPeople = 0;
        this->waitBigData = 0;
        this->countBigData = 0;
    }

    Peoples(Peoples &&another) noexcept = default;

    Peoples &operator=(Peoples &&another) noexcept = default;

    ~Peoples() {
    }

    People *root;
    int countPeople;
    int countBigData;
    int waitBigData;

    void remove(int t) {
        if (this->root == nullptr) { return; }
        People *tmp = this->root->next;
        this->countBigData++;
        this->countPeople--;
        this->waitBigData = this->waitBigData + (t - this->root->tCome);
        cout << t - this->root->tCome << " (" << this->waitBigData << " ) , ";
        delete this->root;
        this->root = tmp;

    }

    void away(int t, int c) {
        cout << "\n\t + left:  ";
        for (int i = 0; i < c; i++) {
            this->remove(t);
        }

    }

    void add(int t) {
        if (this->root != nullptr) {
            this->root->add(t);
        } else {
            this->root = new People(t);
        }
        this->countPeople++;

    }

    void comeToBusStop(int t, int dt) {
        int k = getIntervalByPartDay(t);
        cout << "\n\t ! came to a stop " << k;
        for (int i = 0; i < k; i++) {
            this->add(t);
        }

    }

    int getIntervalByPartDay(int t) {
        int min, max;
        PART_OF_DAY vs;
        if (0 < t && t < 420) {
            vs = Night;
        } else if (420 < t && t < 720) {
            vs = Morning;
        } else if (720 < t && t < 1020) {
            vs = Day;
        } else {
            vs = Evening;
        }
        switch (vs) {
            case Night:
                min = 0;
                max = 2;
                break;
            case Morning:
                min = 1;
                max = 5;
                break;
            case Day:
                min = 2;
                max = 5;
                break;
            case Evening:
                min = 3;
                max = 5;
                break;

        }
        return rand() % max + min;
    }
};

class Bus {

    int interval[4];
    int waitTime;
    int max;
    int number;
public:
    Bus() {
        this->waitTime = 5;
    }

    Bus(Bus &&another) noexcept = default;

    Bus &operator=(Bus &&another) noexcept = default;

    ~Bus() {}

    void changeData(int num, int interval[4]) {
        for (int i = 0; i < 4; i++) {
            this->interval[i] = interval[i];
        }
        this->number = num;
        this->max = rand() % 10 + 10;
    }

    int getIntervalByPartDay(int t) {
        int interval;
        PART_OF_DAY vs;
        if (0 < t && t < 420) {
            vs = Night;
        } else if (420 < t && t < 720) {
            vs = Morning;
        } else if (720 < t && t < 1020) {
            vs = Day;
        } else {
            vs = Evening;
        }
        switch (vs) {
            case Night:
                interval = this->interval[Night];
                break;
            case Morning:
                interval = this->interval[Morning];
                break;
            case Day:
                interval = this->interval[Day];
                break;
            case Evening:
                interval = this->interval[Evening];
                break;
        }
        return interval;
    }

    int getNumber() { return this->number; }

    int comeToBusStop(int t, int dt) {
        this->waitTime = this->waitTime-dt;
        if (this->waitTime > 0)
            return 0;
        this->waitTime = this->getIntervalByPartDay(t);
        return rand() % this->max + 1;
    }
};

class BusStop {
public:

    BusStop() {
        this->peoples = new Peoples;
    }

    BusStop(BusStop &&another) noexcept = default;

    BusStop &operator=(BusStop &&another) noexcept = default;

    ~BusStop() {}

    void CreateBus(int count) {
        int in[4];
        this->bus = new Bus[count];
        for (int i = 0; i < count; i++) {
            in[0] = rand() % 30 + 30;
            in[1] = rand() % 10 + 10;
            in[2] = rand() % 10 + 15;
            in[3] = rand() % 10 + 10;
        }
        this->countBus = count;
    }

    Bus *bus;
    int countBus;
    Peoples *peoples;

    void mainLoop() {
        int mest;
        for (int t = 1; t < 14; t++) {
            this->peoples->comeToBusStop(t, 1);
            for (int b = 0; b < countBus; b++) {
                mest = this->bus[b].comeToBusStop(t, 1);
                if (mest > 0) {
                    cout << "\n" << t << "--> Bus № " << this->bus[b].getNumber() << " Empty seats " << mest <<
                         " At the bus stop " << this->peoples->countPeople;
                    this->peoples->away(t, mest);
                    cout << "/" << " Left " << this->peoples->countPeople;
                }
            }
        }
        cout << "\n\n_____________________Statistics__________________";
        cout << "\n Passengers carried: " << this->peoples->countBigData;
        cout << "\n People lost minutes  " << this->peoples->waitBigData;
        cout << "\n Average waiting time : " << (double) this->peoples->waitBigData / this->peoples->countBigData;
    }


};

