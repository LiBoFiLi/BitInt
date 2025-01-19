#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <random>

using namespace std;

uint32_t fromstring(string &hexstring);
string tostring(uint32_t num);

class BigInt{
    private:
    vector<uint32_t> data;
    static const int base = 32;
    static const uint64_t BASE = (1ULL<<32) -1;
    BigInt Barrett(const BigInt &n, const BigInt &u);
    
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
    BigInt KillLastDigits(int value);
    BigInt operator*(const BigInt &other) const;
    BigInt operator/(const BigInt &other) const;
    BigInt operator%(const BigInt &other) const;
    BigInt operator>>(const uint32_t other) const;
    BigInt operator<<(const uint32_t other) const;
    BigInt pow(const BigInt &other) const;
    BigInt addMod(const BigInt &b, const BigInt &mod) const;
    BigInt subMod(const BigInt &b, const BigInt &mod) const;
    BigInt mulMod(const BigInt &b, const BigInt &mod) const;
    BigInt powMod(const BigInt &exp, const BigInt &mod) const;
    bool operator>(const BigInt &other) const;
    bool operator>=(const BigInt &other) const;
    bool operator<(const BigInt &other) const;
    bool operator<=(const BigInt &other) const;
    bool operator==(const BigInt &other) const;
    int size();
    friend ostream& operator<< (ostream &out, BigInt &num);
    void printBinary() const;
    void random(const int siz);
    void random(const int siz1, const int siz2);
    BigInt& operator=(const BigInt& other) {
        if (this == &other) return *this;
        data = other.data;
        return *this;
    }
    BigInt& operator=(const uint32_t other) {
        data.clear();
        data.push_back(other);
        return *this;
    }
    BigInt(uint32_t num) {
        data.push_back(num);
    }
    bool isZero() const {
        return data.empty() || (data.size() == 1 && data[0] == 0);
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
    
    bool getbit(int val) const {
       size_t length = data.size() * 32;
       if (data.empty()) return 0;
       length = length - 32;
       uint32_t highest = data.back();
       while (highest) {
           highest = highest >> 1;
           length++;
    }
       if(val>length){
        return 0;
       }
       else{
        return (data[val/32]>>(val%32)) & 1;
       }
    }

    bool isEven() const {
    return (data[0] & 1) == 0;
    }
    bool isOdd() const {
    return (data[0] & 1) == 1; 
} 
    
};