#ifndef _DATASTORE_HPP
#define _DATASTORE_HPP

#include <string>

using namespace std;


class DataStore {
        public:
                DataStore() {};
                virtual ~DataStore() {};
};

class DataStore1: public DataStore {
        private:
                string pin;
                string id;
                float balance;
                float temp_d;
                float temp_w;
                string temp_pin;
                string temp_id;
                float temp_balance;
        public:
                DataStore1() {};
                virtual ~DataStore1() {};

                void setPin(string p) {
                        pin = p;
                }
                void setId(string i) {
                        id = i;
                }
                void setBalance(float b) {
                        balance = b;
                }
                void setTempD(float d) {
                        temp_d = d;
                }
                void setTempW(float w) {
                        temp_w = w;
                }
                void setTempPin(string p) {
                        temp_pin = p;
                }
                void setTempId(string i) {
                        temp_id = i;
                }
                void setTempBalance(float b) {
                        temp_balance = b;
                }

                string getPin() {
                        return pin;
                }
                string getId() {
                        return id;
                }
                float getBalance() {
                        return balance;
                }
                float getTempD() {
                        return temp_d;
                }
                float getTempW() {
                        return temp_w;
                }
                string getTempPin() {
                        return temp_pin;
                }
                string getTempId() {
                        return temp_id;
                }
                float getTempBalance() {
                        return temp_balance;
                }
};

class DataStore2: public DataStore {
        private:
                int pin;
                int id;
                int balance;
                int temp_d;
                int temp_w;
                int temp_pin;
                int temp_id;
                int temp_balance;
        public:
                DataStore2() {};
                virtual ~DataStore2() {};
                
                void setPin(int p) {
                        pin = p;
                };
                void setId(int i) {
                        id = i;
                };
                void setBalance(int b) {
                        balance = b;
                };
                void setTempD(int d) {
                        temp_d = d;
                };
                void setTempW(int w) {
                        temp_w = w;
                };
                void setTempPin(int p) {
                        temp_pin = p;
                };
                void setTempId(int i) {
                        temp_id = i;
                };
                void setTempBalance(int b) {
                        temp_balance = b;
                };
                
                int getPin() {
                        return pin;
                };
                int getId() {
                        return id;
                };
                int getBalance() {
                        return balance;
                };
                int getTempD() {
                        return temp_d;
                };
                int getTempW() {
                        return temp_w;
                };
                int getTempPin() {
                        return temp_pin;
                };
                int getTempId() {
                        return temp_id;
                };
                int getTempBalance() {
                        return temp_balance;
                };
};

#endif

