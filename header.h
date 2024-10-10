#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <sstream>
#include <iomanip>

using namespace std;

uint32_t fromstring(string &hexstring);
string tostring(uint32_t num);

class BigInt{
    private:
    vector<uint32_t> data;
    static const int base = 32;
    static const uint64_t BASE = (1ULL<<32) -1;
    
    public:
    BigInt();
    BigInt(string hexstring);
    BigInt operator+(const BigInt &other) const;
    BigInt operator-(const BigInt &other) const;
    BigInt MulOneDigit(string nums);
    BigInt MulOneDigit(uint32_t num);
    BigInt LongShiftDigitsToHigh(int i);
    BigInt operator*(const BigInt &other) const;
    int size();
    friend ostream& operator<< (ostream &out, BigInt &num);
};