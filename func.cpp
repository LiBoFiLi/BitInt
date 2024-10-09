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
    }
    return result;
}