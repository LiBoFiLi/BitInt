#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <sstream>
#include <iomanip>
#include <bitset>

using namespace std;

uint32_t fromstring(string &hexstring);
string tostring(uint32_t num);

class BigInt{
    private:
    vector<uint32_t> data;
    static const int base = 32;
    static const uint64_t BASE = (1ULL<<32) -1;
    bool isZero() const {
        return data.empty() || (data.size() == 1 && data[0] == 0);
    }
    void trim() {
    while (data.size() > 1 && data.back() == 0) {
        data.pop_back();  
    }
    }
    
    
    public:
    BigInt();
    BigInt(string hexstring);
    BigInt operator+(const BigInt &other) const;
    BigInt operator-(const BigInt &other) const;
    BigInt MulOneDigit(string nums);
    BigInt MulOneDigit(uint32_t num);
    BigInt LongShiftDigitsToHigh(int i);
    BigInt LongShiftBitsToHigh(int value);
    BigInt operator*(const BigInt &other) const;
    BigInt operator/(const BigInt &other) const;
    BigInt operator%(const BigInt &other) const;
    BigInt pow(const BigInt &other) const;
    bool operator>(const BigInt &other) const;
    bool operator>=(const BigInt &other) const;
    bool operator<(const BigInt &other) const;
    bool operator<=(const BigInt &other) const;
    int size();
    friend ostream& operator<< (ostream &out, BigInt &num);
    void printBinary() const;
    BigInt(uint32_t num) {
        data.push_back(num);
    }
    size_t bitLength() const {
       size_t length = data.size() * 32;
       if (data.empty()) return 0;
       length = length - 32;
       uint32_t highest = data.back();
       while (highest) {
           highest = highest >> 1;
           length++;
    }
       return length;
    }
    
};