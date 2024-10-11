#include "func.cpp"

int main(){
    BigInt a("28a895cfd0200f098e2effaf19391c4a837ff199610c9bd4241b1a226effbc0ba1e4c9f81cd703a4212c02f9677");
    BigInt b("f098e2effaf19391c4a837ff199610c9bd4241b1a226effbc0ba1e4c9f81cd703a4212c02f96760");
    cout<<"a:      "<<a<<" "<<a.size()<<endl;
    cout<< endl;
    cout<<"b:      "<<b<<" "<<b.size()<<endl;
    cout<< endl;
    BigInt sum = a + b;
    cout<<"sum:    "<< sum << endl;
    cout<< endl;
    BigInt diff = a - b;
    cout<<"diff:   "<< diff << endl;
    cout<< endl;
    BigInt mulone = a.MulOneDigit("FFFF");
    cout<<"mulone: "<< mulone << endl;
    cout<< endl;
    BigInt shift = a.LongShiftDigitsToHigh(1);
    cout<<"shift1: "<< shift<<" "<<shift.size()<< endl;
    cout<< endl;
    BigInt mul = a * b;
    cout<<"mul:    "<< mul << endl;
    cout<< endl;
    BigInt div = a / b;
    cout<<"div:    "<< div << endl;
    cout<< endl;
    BigInt R = a % b;
    cout<<"R:      "<< R << endl;
    cout<< endl;
    return 0;
}