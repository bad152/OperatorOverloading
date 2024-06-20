#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Timer {

    friend std::ostream& operator << (std::ostream&, const Timer&);

public:
    Timer() {
        counter = 0;
    }

    void setTime(int _counter) {
        counter = _counter;
    }

    void reset() {
        counter = 0;
    }

    void start() {
        if (counter == 0) {
            cout << "Установите таймер" << endl;
            return;
        }
        begin_time = clock();
    }

    void stop() {
        if (counter == 0) {
            cout << "Установите таймер" << endl;
            return;
        }
        auto time_delta = float(clock() - begin_time) / CLOCKS_PER_SEC;
        counter = time_delta >= counter ? 0 : counter - time_delta;

        cout << "Прошло: " << time_delta << " секунд" << endl;
        cout << *this << endl;
    }


private:
    int counter;
    clock_t begin_time;
};


std::ostream& operator << (ostream& cout, const Timer& t) {
    cout << "Осталось: " << t.counter << " секунд";
    return cout;
}


int main() {

    Timer timer;
    timer.start();

    timer.setTime(30);
    timer.start();
    timer.stop();

    timer.start();
    timer.stop();

    timer.start();
    timer.stop();

    return 0;
}