#include "header.h"

int BigInt::size(){
    return int(data.size());
}

ostream& operator<< (ostream &out, BigInt &num){
    for(size_t i = num.data.size() ; i>0 ; i=i-1){
        string sub = tostring(num.data[i-1]);
        out << sub;
    }
    return out;
}

uint32_t fromstring(string &hexstring){
    uint32_t result;
    stringstream ss;
    ss << hex << hexstring;
    ss >> result;
    return result;
}

string tostring(uint32_t num){
    stringstream ss;
    ss << hex << uppercase; 
    ss << setw(8) << setfill('0') << num; 
    return ss.str(); 
}

BigInt::BigInt(){

}

BigInt::BigInt(string hexstring){
    BigInt result;
    size_t s = hexstring.length();  
    for(size_t i=s; i>7; i=i-8){
        string sub = hexstring.substr(i-8,8);
        uint32_t cap = fromstring(sub);
        result.data.push_back(cap);
    }
    s = s % 8;
    if(s==0){
    }
    else{
    string sub = hexstring.substr(0,s);
    uint32_t cap = fromstring(sub);
    result.data.push_back(cap);
    }
    data = result.data;
}

BigInt BigInt::operator+(const BigInt &other) const {
    BigInt result;
    size_t siz = max(data.size(), other.data.size());
    result.data.resize(siz);
    uint64_t carry=0;
    for(size_t i=0; i<siz; i++){
        uint64_t sum = carry;
        if(i<data.size()) sum = sum + data[i];
        if(i<other.data.size()) sum = sum + other.data[i];
        result.data[i] = sum & BASE;
        carry = sum >> base;
    }
    if(carry) result.data.push_back(carry);
    return result;
}

BigInt BigInt::operator-(const BigInt &other) const{
    BigInt result;
    size_t siz = max(data.size(), other.data.size());
    result.data.resize(siz);        
    int64_t borrow = 0;
    for(size_t i = 0; i<siz; i++){
        int64_t diff = - borrow;
        if(i<data.size()) diff = diff + data[i];    
        if(i<other.data.size()) diff = diff - other.data[i];
        if(diff<0){
            diff = diff + BASE + 1;
            borrow = 1;
        }
        else{
            borrow = 0;
        }
        result.data[i] = diff;
    }
    if(borrow){
        result.data[0] = BASE - result.data[0] + 1;
        for(size_t i=1; i<result.data.size(); i++){
         result.data[i] = BASE - result.data[i]; 
        }
        //cout<<"ALARMYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYDDDDDDDDDDDD!!"<<endl;
    }
    result.trim();
    return result;
}

BigInt BigInt::MulOneDigit(string nums){
    BigInt result;
    uint32_t num = fromstring(nums);
    result.data.resize(data.size());
    uint64_t carry = 0;
    for(size_t i = 0; i<data.size(); i++){
        uint64_t mul = data[i];
        mul = mul*num + carry; 
        result.data[i] = mul & BASE;
        carry = mul >> base;
    }
    if(carry) result.data.push_back(carry);
    return result;
}

BigInt BigInt::MulOneDigit(uint32_t num){
    BigInt result;
    result.data.resize(data.size());
    uint64_t carry = 0;
    for(size_t i = 0; i<data.size(); i++){
        uint64_t mul = data[i];
        mul = mul*num + carry; 
        result.data[i] = mul & BASE;
        carry = mul >> base;
    }
    if(carry) result.data.push_back(carry);
    return result;
}

BigInt BigInt::LongShiftDigitsToHigh(int value){
    BigInt result;
    result.data = data;
    for(int j = 0; j<value; j++){
        result.data.insert(result.data.begin(), 0);
    }
    return result;
}

BigInt BigInt::operator*(const BigInt &other) const{
    BigInt result, copy;
    copy.data = data;
    for(size_t i=0; i<other.data.size(); i++){
        //uint32_t value = other.data[i];
        BigInt mul = copy.MulOneDigit(other.data[i]);
        //cout<< mul<<" "<<mul.size()<< endl;
        mul = mul.LongShiftDigitsToHigh(i);
        result = result + mul;
        //cout<< mul<<" "<<mul.size()<< endl;
        //cout<< endl;
    }
    return result;
}

bool BigInt::operator>(const BigInt &other) const {
    int a = data.size();
    while (a > 0 && data[a - 1] == 0) {
        a--;
    }
    int b = other.data.size();
    while (b > 0 && other.data[b - 1] == 0) {
        b--;
    }
    if (a > b) return true;   
    if (a < b) return false; 
    for (int i = a - 1; i >= 0; i--) {
        if (data[i] > other.data[i]) return true;   
        if (data[i] < other.data[i]) return false;  
    }
    return false; 
}

bool BigInt::operator>=(const BigInt &other) const {
    int a = data.size();
    while (a > 0 && data[a - 1] == 0) {
        a--;
    }
    int b = other.data.size();
    while (b > 0 && other.data[b - 1] == 0) {
        b--;
    }
    if (a > b) return true;   
    if (a < b) return false; 
    for (int i = a - 1; i >= 0; i--) {
        if (data[i] > other.data[i]) return true;   
        if (data[i] < other.data[i]) return false;  
    }
    return true; 
}

bool BigInt::operator<(const BigInt &other) const {
    int a = data.size();
    while (a > 0 && data[a - 1] == 0) {
        a--;
    }
    int b = other.data.size();
    while (b > 0 && other.data[b - 1] == 0) {
        b--;
    }
    if (a < b) return true;   
    if (a > b) return false; 
    for (int i = a - 1; i >= 0; i--) {
        if (data[i] < other.data[i]) return true;   
        if (data[i] > other.data[i]) return false;  
    }
    return false; 
}

bool BigInt::operator<=(const BigInt &other) const {
    int a = data.size();
    while (a > 0 && data[a - 1] == 0) {
        a--;
    }
    int b = other.data.size();
    while (b > 0 && other.data[b - 1] == 0) {
        b--;
    }
    if (a < b) return true;   
    if (a > b) return false; 
    for (int i = a - 1; i >= 0; i--) {
        if (data[i] < other.data[i]) return true;   
        if (data[i] > other.data[i]) return false;  
    }
    return true; 
}

bool BigInt::operator==(const BigInt &other) const{
    int a = data.size();
    while (a > 0 && data[a - 1] == 0) {
        a--;
    }
    int b = other.data.size();
    while (b > 0 && other.data[b - 1] == 0) {
        b--;
    }
    if (a < b) return false;   
    if (a > b) return false; 
    for (int i = a - 1; i >= 0; i--) {
        if (data[i] < other.data[i]) return false;   
        if (data[i] > other.data[i]) return false;  
    }
    return true; 
}

void BigInt::random(const int siz){
    data.clear();
    //string values = "0123456789abcdf";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, BASE);
    uniform_int_distribution<> distrib1(1, BASE);
    uniform_int_distribution<> sizee(1, siz);
    data.resize(sizee(gen));
    int size = data.size();
    for (int i = 0; i < size - 1; i++) {
         data[i] = distrib(gen);
    }
    data[size - 1] = distrib1(gen);
}

void BigInt::random(const int siz1, const int siz2){
    data.clear();
    //string values = "0123456789abcdf";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, BASE);
    uniform_int_distribution<> distrib1(1, BASE);
    uniform_int_distribution<> sizee(siz1, siz2);
    data.resize(sizee(gen));
    int size = data.size();
    for (int i = 0; i < size - 1; i++) {
         data[i] = distrib(gen);
    }
    data[size - 1] = distrib1(gen);
}

void BigInt::printBinary() const{
    for(size_t i = data.size(); i>0; i--){
        bitset<32> binary(data[i-1]);
        cout << binary<<" ";
    }
}

BigInt BigInt::LongShiftBitsToHigh(int value){
    if (value <= 0) return *this; 

    BigInt result;
    result.data.resize(data.size() + (value / 32) + 1, 0); 
    uint32_t carry = 0; 

    for (size_t i = 0; i < data.size(); i++) {
        uint32_t current = data[i]; 
        result.data[i + (value / 32)] |= (current << (value % 32)); 

        if (value % 32 > 0 && i + (value / 32) + 1 < result.data.size()) {
            result.data[i + (value / 32) + 1] |= (current >> (32 - (value % 32))); 
        }
    }

    while (result.data.size() > 1 && result.data.back() == 0) {
        result.data.pop_back();
    }

    return result;
}

BigInt BigInt::operator>>(const uint32_t other) const {
    if (other == 0) return *this;

    BigInt result = *this;

    int blockShift = other / 32; 
    int bitShift = other % 32;  

    if (blockShift > 0) {
        if (blockShift >= (int)result.data.size()) {
            result.data.clear();
            result.data.push_back(0);
            return result;
        }
        result.data.erase(result.data.begin(), result.data.begin() + blockShift);
    }

    if (bitShift > 0) {
        uint32_t carry = 0; 
        for (size_t i = result.data.size(); i > 0; i--) {
            uint32_t current = result.data[i - 1];
            result.data[i - 1] = (current >> bitShift) | (carry << (32 - bitShift));
            carry = current & ((1U << bitShift) - 1); 
        }
    }

     while (result.data.size() > 1 && result.data.back() == 0) {
        result.data.pop_back();
    }
    return result;
}

BigInt BigInt::operator<<(const uint32_t other) const {
    if (other <= 0) return *this; 

    BigInt result;
    result.data.resize(data.size() + (other / 32) + 1, 0); 
    uint32_t carry = 0; 

    for (size_t i = 0; i < data.size(); i++) {
        uint32_t current = data[i]; 
        result.data[i + (other / 32)] |= (current << (other % 32)); 

        if (other % 32 > 0 && i + (other / 32) + 1 < result.data.size()) {
            result.data[i + (other / 32) + 1] |= (current >> (32 - (other % 32))); 
        }
    }

    while (result.data.size() > 1 && result.data.back() == 0) {
        result.data.pop_back();
    }

    return result;
}

BigInt gcdBinary(const BigInt& a, const BigInt& b) {
    if (a == 0) return b;
    if (b == 0) return a;

    BigInt aCopy = a;
    BigInt bCopy = b;

    BigInt d = 1;

    while (aCopy.isEven() && bCopy.isEven()) {
        aCopy = aCopy >> 1;
        bCopy = bCopy >> 1;
        d = d << 1;
    }

    while (aCopy.isEven()) {
        aCopy = aCopy >> 1;
    }
    bool bzero = bCopy.isZero();
    while (!bzero) {
        while (bCopy.isEven()) {
            bCopy = bCopy >> 1;
        }

        if (aCopy > bCopy) {
            swap(aCopy, bCopy);
        }
        bCopy = bCopy - aCopy; 
        bzero = bCopy.isZero();
    }

    return d*aCopy; 
}

BigInt lcm(const BigInt& a, const BigInt& b){
    BigInt result;
    result = (a*b) / gcdBinary(a,b);
    return result;
}

BigInt BigInt::operator/(const BigInt &other) const{
    if(other.isZero()) throw invalid_argument("Division by zero");
    BigInt Q("0"); 
    BigInt R,B;
    B.data = other.data;
    R.data = data; 
    if (R < B) {
        return BigInt(0);
    }
    size_t k = B.bitLength();
    while(R>=B){ 
        size_t t = R.bitLength();
        BigInt C = B.LongShiftBitsToHigh(t-k);
        if(C>R){
            t=t-1;
            C = B.LongShiftBitsToHigh(t-k);
        }
        //cout<<"Q:"<< Q <<" R:"<<R<<" B:"<<B<<" C: "<<C<<" t:"<<t<<" k:"<<k<<" "<<bool(R>C)<<endl;
        R = R - C;
        BigInt Qc("1");
        Qc = Qc.LongShiftBitsToHigh(t-k);
        Q = Q + Qc;
       // cout<<Qc<<endl;
        //cout<<"Q:"<< Q <<" R:"<<R<<" B:"<<B<<" C: "<<C<<" t:"<<t<<" k:"<<k<<endl;
        //cout<<"RAfter: "<<R<<endl;
    }
    return Q;
}

BigInt BigInt::operator%(const BigInt &other) const{
    if(other.isZero()) throw invalid_argument("Division by zero");
    BigInt Q("0"); 
    BigInt R,B;
    B.data = other.data;
    R.data = data; 
    if (R < B) {
        return BigInt(R);
    }
    size_t k = B.bitLength();
    while(R>=B){ 
        size_t t = R.bitLength();
        BigInt C = B.LongShiftBitsToHigh(t-k);
        if(C>R){
            t=t-1;
            C = B.LongShiftBitsToHigh(t-k);
        }
       // cout<<"Q:"<< Q <<" R:"<<R<<" B:"<<B<<" C: "<<C<<" t:"<<t<<" k:"<<k<<" "<<bool(R>C)<<endl;
        R = R - C;
        BigInt Qc("1");
        Qc = Qc.LongShiftBitsToHigh(t-k);
        Q = Q + Qc;
       // cout<<Qc<<endl;
        //cout<<"Q:"<< Q <<" R:"<<R<<" B:"<<B<<" C: "<<C<<" t:"<<t<<" k:"<<k<<endl;
        //cout<<"RAfter: "<<R<<endl;
    }
    return R;
}

BigInt BigInt::pow(const BigInt &other) const{
    BigInt bas, exp, result("1");
    bas.data = data;
    exp.data = other.data;
    //exp.printBinary();
    //cout<<endl;
    //cout<< exp.bitLength() << endl;
    for(size_t i=exp.bitLength(); i>0; i--){
        result = result * result;
        if(((exp.data[(i-1)/32]>>((i-1)%32)) & 1) == 1) result = result * bas;
    }
    return result;
}

/**
BigInt BigInt::Barrett(const BigInt &other) const{
    BigInt x, n = other;
    x.data = data;
    int k = n.size();
    if(x.size()<=2*k){
        x = x.LongShiftDigitsToHigh(2*k-x.size());
    }
    else{
        n = n.LongShiftDigitsToHigh((x.size()-2*k)/2);
    }
    uint64_t B = (1ULL<<32);
    uint32_t u = 
    //BigInt q = x.KillLastDigits() 
}
*/

BigInt BigInt::KillLastDigits(int value){
    BigInt result;
    result.data = data;
    if (value < result.data.size()) {
        result.data.erase(result.data.begin(), result.data.begin() + value);
    } else {
        result.data.clear();
        result.data.push_back(0); 
    }
    return result;
}


BigInt BigInt::Barrett(const BigInt &n, const BigInt &u) {
    size_t k = n.data.size(); 
    BigInt x;
    x.data = data;
    if (n.data.size() < 2*x.data.size()) {
        return x % n; 
    }

    BigInt q;
    q = x.KillLastDigits(k-1) * u;
    q = q * u;

    q = q.KillLastDigits(k+1);

    BigInt r = x - (q * n);

    while (r >= n) {
        r = r - n;
    }

    return r;
}

BigInt BigInt::addMod(const BigInt &b, const BigInt &mod) const{
    BigInt a = *this;
    BigInt result = a + b;
    BigInt beta(1);
    beta = beta << (2 * mod.data.size() * 32); 
    BigInt mu = beta / mod;
    return result.Barrett(mod, mu);
}

BigInt BigInt::subMod(const BigInt &b, const BigInt &mod) const{
    BigInt a = *this;
    BigInt result = a - b;
    BigInt beta(1);
    beta = beta << (2 * mod.data.size() * 32); 
    BigInt mu = beta / mod;
    return result.Barrett(mod, mu);
}

BigInt BigInt::mulMod(const BigInt &b, const BigInt &mod) const{
    BigInt a = *this;
    BigInt result = a * b;
    BigInt beta(1);
    beta = beta << (2 * mod.data.size() * 32); 
    BigInt mu = beta / mod;
    return result.Barrett(mod, mu);
}

BigInt BigInt::powMod(const BigInt &exp, const BigInt &mod) const{
    BigInt result = BigInt(1); 
    BigInt base = *this;
    BigInt beta(1);
    beta = beta << (2 * mod.data.size() * 32); 
    BigInt mu = beta / mod;

    BigInt x = base.Barrett(mod, mu); 

    
    for (int i = exp.bitLength() - 1; i >= 0; i--) {
        result = result.mulMod(result, mod); 
        if (exp.getbit(i)) {              
            result = result.mulMod(x, mod);
        }
    }
    return result;
}

