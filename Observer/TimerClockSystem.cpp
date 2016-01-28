#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef enum {
        AM, PM
} Meridiem;

class Observer {
        public:
                Observer() {}
                virtual ~Observer() {}
                virtual void Update() = 0; // Observer should be Abstract class
};

class Subject {
        private:
                vector<Observer*> observers;
        public:
                Subject() {}
                virtual ~Subject() {}
                // Take care of notification
                void Notify() {
                        for (auto x: observers) {
                                x->Update();
                        }
                }
                void Register(Observer *x) {
                        observers.push_back(x);
                }
                void Unregister(Observer *x) {
                        auto iter = find(observers.begin(), observers.end(), x);
                        observers.erase(iter);
                }
};

class Timer: public Subject {
        protected:
                int hour;
                int minute;
                int second;
        public:
                Timer() {}
                virtual ~Timer() {}
                // Take care of time keeping
                void Tick() {
                        // get time from somewhere
                        // update internal time keeping states
                        Notify(); // push notifications to all observers
                        // other cleanup stuff...
                };
                virtual int GetHour() {
                        return hour;
                }
                int GetMinute() {
                        return minute;
                }
                int GetSecond() {
                        return second;
                }
                virtual Meridiem AMPM() {
                        return GetHour() > 12 ? PM : AM; 
                }
};

/**
 * If we put the responsibility of time zone to the Timer,
 * then we may end up with one special timer for each time zone.
 */
class TimerEST: public Timer {
        public:
                TimerEST() {}
                ~TimerEST() {}
                // Return different hour data
                virtual int GetHour() { 
                        return hour + 4;
                }
                virtual Meridiem AMPM() {
                        return GetHour() > 16 ? PM : AM;
                }
};

class TimerCST: public Timer {
        public:
                TimerCST() {}
                ~TimerCST() {}
                // Return different hour data
                virtual int GetHour() { 
                        return hour + 5;
                }
                virtual Meridiem AMPM() {
                        return GetHour() > 17 ? PM : AM;
                }
};

class Clock: public Observer {
        protected:
                Timer *timer;
        public:
                Clock() {} // Consist with Observer's constructor
                /**
                 * Register/unregister observer in
                 * constructor/destructor
                 */
                Clock(Timer *source): timer(source) {
                        timer->Register(this);
                }
                virtual ~Clock() {
                        timer->Unregister(this);
                }
                virtual void Update() = 0;
                /**
                 * Override to display different format
                 */
                virtual string DisplayTime() = 0;
};

/**
 * Clock with different precision
 */
class HourClock: public Clock {
        private:
                int hour;
        public:
                HourClock(Subject *source) {}
                virtual ~HourClock() {}
                virtual void Update() {
                        hour = timer->GetHour();
                        DisplayTime();
                }
                virtual string DisplayTime() {
                        return to_string(hour) + " o'clock";
                }
};

class MinuteClock: public Clock {
        private:
                int hour;
                int minute;
        public:
                MinuteClock(Subject *source) {}
                virtual ~MinuteClock() {}
                virtual void Update() {
                        hour = timer->GetHour();
                        minute = timer->GetMinute();
                        DisplayTime();
                }
                virtual string DisplayTime() {
                        return to_string(hour) + ":" +
                                to_string(minute);
                }
};

class SecondClock: public Clock {
        private:
                int hour;
                int minute;
                int second;
        public:
                SecondClock() {}
                SecondClock(Subject *source) {}
                virtual ~SecondClock() {}
                virtual void Update() {
                        /**
                         * Retrieve all information from timer
                         */
                        hour = timer->GetHour();
                        minute = timer->GetMinute();
                        second = timer->GetSecond();
                        DisplayTime(); 
                }
                virtual string DisplayTime() {
                        return to_string(hour) + ":" +
                                to_string(minute) + ":" +
                                to_string(second);       
                };
};

class DigitalClock: public SecondClock {
        public:
                DigitalClock(Subject *source) {}
                virtual ~DigitalClock() {}
                virtual string DisplayTime() {
                        
                }
};

class AnalogClock: public SecondClock {
        public:
                AnalogClock(Subject *source) {}
                virtual ~AnalogClock() {}
                virtual string DisplayTime() {

                }
};

int main() {
        TimerEST *timer_est = new TimerEST();
        TimerCST *timer_cst = new TimerCST();

        DigitalClock *digital_est = new DigitalClock(timer_est);
        AnalogClock *analog_cst = new AnalogClock(timer_cst); 

        while (1) {
                timer_est->Tick();
                timer_cst->Tick();
        }
        
        // first delete clock because we need to unregister from timer
        delete digital_est;
        delete analog_cst;
        // delete timer at last
        delete timer_est;
        delete timer_cst;
}


