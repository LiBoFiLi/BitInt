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
    
    public:
    BigInt();
    BigInt(string hexstring);
    int size();
    friend ostream& operator<< (ostream &out, BigInt &num);
};