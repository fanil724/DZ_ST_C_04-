#include <iostream>
#include <new>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include <sstream>


template<typename T>
class Queue {
public:
    Queue() : SIZE(0), arr(NULL), counter(0) {}
    Queue(int SIZE) {
        try {
            this->SIZE = SIZE;
            arr = new T[this->SIZE]();
            counter = 0;
        }
        catch (std::bad_alloc &memoryAllocationException) {
            std::cerr << "Exception occured: [ERROR MEMORY]" << memoryAllocationException.what() << std::endl;
        }
    }
    ~Queue() {
        delete[] arr;
        arr = NULL;
    }
    void addElement(T Element) {
        if (this->checkQueue() != false) {
            this->arr[this->counter] = Element;
            this->counter++;
        }
    }
    void deleteElementQueue() {
        if (this->counter != 0) {
            T *buf = new T[this->counter]();
            for (size_t i = 0; i < this->counter; i++) {
                buf[i] = this->arr[i];
                this->arr[i] = 0;
            }
            for (size_t i = 0; i < this->counter - 1; i++) {
                this->arr[i] = buf[i + 1];
            }
            this->counter--;
            delete[] buf;
        } else {
            this->checkQueue();
        }
    }
   void deleteElementQueueRing() {
        if (this->counter != 0) {
            T temp = this->arr[0];
            for (size_t i = 1; i < this->counter; i++) {
                this->arr[i - 1] = this->arr[i];
            }
            this->arr[this->counter - 1] = temp;
        } else {
            this->checkQueue();
        }
    }
    void deleteElementQueuePriority() {
        if (this->counter != 0) {
            T *buf = new T[this->counter - 1];
            T temp = this->arr[0];
            size_t count = 0, valueSameElements = 0;
            for (size_t i = 0; i < this->counter; i++) {
                if (temp < arr[i]) {
                    temp = arr[i];
                }
            }
            for (size_t i = 0; i < this->counter; i++) {
                if (arr[i] == temp)
                    valueSameElements++;
            }
            for (size_t i = 0; i < this->counter; i++) {
                if (this->arr[i] != temp) {
                    buf[count] = this->arr[i];
                    count++;
                }
                if (this->arr[i] == temp && valueSameElements > 1) {
                    buf[count] = this->arr[i];
                    count++;
                    valueSameElements--;
                }
            }
            for (size_t i = 0; i < this->counter - 1; i++) {
                this->arr[i + 1] = buf[i];
            }
            this->arr[0] = temp;
            deleteElementQueue();
            delete[] buf;
            count = 0;
        } else {
            this->checkQueue();
        }
    }
    bool checkQueue() {
        if (this->counter < this->SIZE) {
            return true;
        } else {
            return false;
        }
    }
    void showQueue() {
        this->checkQueue();
        for (size_t i = 0; i < this->counter; i++) {
            std::cout << this->arr[i] << "\t";
        }
        std::cout << std::endl;
    }
    T GetFirst() {
        return this->arr[0];
    }
    T GetLast() {}
    void queueRand(int min, int max) {
        for (size_t i = 0; i < this->SIZE; i++) {
            this->arr[i] = min + rand() % (max - min + 1);
        }
        this->counter = this->SIZE;
    }

    void deleteQueue() {
        for (size_t i = 0; i < this->counter; i++) {
            arr[i] = 0;
        }
        this->counter = 0;
    }

    int sizeQueue() {
        std::cout << "Size queue -> " << this->SIZE << std::endl;
        std::cout << "Elements in queue -> " << this->counter << std::endl;
        return this->SIZE;
    }
private:
    T *arr;
    int SIZE;
    int counter;
};

class Time {
public:
    Time() : minutes(0), hours(0), seconds(0) {}

    Time(int h, int m, int s) {
        this->hours = h;
        this->minutes = m;
        this->seconds = s;
    }
    void show() { std::cout << "Time -> " << hours << ":" << minutes << ":" << seconds << std::endl; }

    void setHours(int h) { if (h <= 12 && h >= 0 || h <= 24 && h >= 0) this->hours = h; }

    void setMinutes(int m) { if (m <= 60 && m >= 0) this->minutes = m; }

    void setSeconds(int s) { if (s <= 60 && s >= 0) this->seconds = s; }

    int getHours() { return this->hours; }

    int getMinutes() { return this->minutes; }

    int getSeconds() { return this->seconds; }

private:
    int minutes;
    int hours;
    int seconds;
};

class Users {
public:
    Users() : age(0), numberSheets(0) {}
    Users(std::string name, std::string surname, int age, int numberSheets, Time *time, int priority) {
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->numberSheets = numberSheets;
        this->time = time;
        this->priority = priority;
    }
    void show() {
        std::cout << "User" << std::endl;
        std::cout << "Name -> " << this->getName() << std::endl;
        std::cout << "Surname -> " << this->getSurname() << std::endl;
        std::cout << "Age -> " << this->getAge() << std::endl;
        std::cout << "Sent to printer -> " << this->getNumberSheets() << std::endl;
        this->time->show();
        std::cout << "Priority -> " << this->getPriority() << std::endl;
    }
    void setName(std::string name) {
        this->name = name;
    }
    std::string getName() {
        return this->name;
    }
    void setSurname(std::string surname) {
        this->surname = surname;
    }
    std::string getSurname() {
        return this->surname;
    }
    void setAge(int age) {
        this->age = age;
    }
    int getAge() {
        return this->age;
    }
    void setNumberSheets(int numberSheets) {
        this->numberSheets = numberSheets;
    }
    int getNumberSheets() {
        return this->numberSheets;
    }
    void setTime(int h, int m, int s) {
        this->time->setHours(h);
        this->time->setMinutes(m);
        this->time->setSeconds(s);
    }
    Time &getTime() {
        return *time;
    }
    void setPriority(int priority) {
        this->priority = priority;
    }
    int getPriority() {
        return this->priority;
    }
private:
    std::string name;
    std::string surname;
    int age;
    int numberSheets;
    Time *time;
    int priority;
};

