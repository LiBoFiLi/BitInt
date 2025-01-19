#include "func.cpp"

int main(){
    BigInt siz("28a895cfd01f98784949f1575804d0b34693049e8aa36312806fe6b5ce5a06e58534365a8c4853b84b25");
    //BigInt bb("1eb1ff6b3f043882d2a5e8b84d090d13d89e3c46fcde03f9a1275156fe22ea42336bcab5c9f52aeb46060a819989e83b1611c3aeb5088687dbcb06862b2283fa0be2b580ee96ad2f4013654163b642f373d3dd0f35cac93b0502383dff5ea213d303e3cc444fbab8f686a7738d57060563ca7da30d5af189e9447862b29b1902");
    //BigInt aa("3a15c04294ad5b6b54fd4d577f922957b18f78766aea085849c8cdb38cecc7271fe85cac2d75e636a5fa9942ea7d549c8b498b7e7c4011e3627291d39e0741f821459d40b9d37c1ab8642e02145cec0e28799e153c91f5885d9c0c785687c2ab37ca13314d65e1d32f8448a3cb93686d2136019521203d65fbcd90874b7fb601ac413730abaf2a388ce5523b3971f28951ef557a01e6fcdc546d61be42acac72d3a8703b1ff7253d4f5dab44ca1aefda039441f96f20d073b7cb46a6093abfd8da3701525f05b57c7d2e3187642b39d65753018997d2242f184fec391f66fa7a9c8f7ea01295e8dda0a28003163c0e8dce4e34699ac46cb2bc348d412cf00e19");

    //BigInt a("28a895cfd0200f098e2effaf19391c4a837ff199610c9bd4241b1a226effbc0ba1e4c9f81cd703a4212c02f9677");
   // BigInt b("f098e2effaf19391c4a837ff199610c9bd4241b1a226effbc0ba1e4c9f81cd703a4212c02f96760");

    BigInt a("28a895cfd01f98784949f1575804d0b34693049e8aa36312806fe6b5ce5a06e58534365a8c4853b84b25e43fcc0");
    BigInt b("f098e2effaf19391c4a837ff199610c9bd4241b1a226effbc0ba1e4c9f81cd703a4212c02f96760");
    cout<<"a:      "<<a<<" "<<a.size()<<"\n\n";
    cout<<"b:      "<<b<<" "<<b.size()<<"\n\n";
    BigInt sum = a + b;
    cout<<"sum:    "<< sum << "\n\n";
    BigInt diff = a - b;
    cout<<"diff:   "<< diff << "\n\n";
    BigInt mulone = a.MulOneDigit("FFFF");
    cout<<"mul on FFFF: "<< mulone << "\n\n";
    BigInt shift = a.LongShiftDigitsToHigh(1);
    cout<<"shift1: "<< shift<<" "<<shift.size()<< "\n\n";
    BigInt mul = a * b;
    cout<<"mul:    "<< mul << "\n\n";
    BigInt div = a / b;
    cout<<"div:    "<< div << "\n\n";
    BigInt R = a % b;
    cout<<"R:      "<< R << "\n\n";
    BigInt gcd = gcdBinary(a,b);
    cout<<"gcd:      "<< gcd << "\n\n";
    BigInt lcm1 = lcm(a,b);
    cout<<"lcm:      "<< lcm1 << "\n\n";
    BigInt admod = a.addMod(b, BigInt("28a895cfd01f98784949f1575804d0b34693049e8aa36312806fe6b5ce5a06e58534365a8c4853b84b25"));
    cout<<"addmod:      "<< admod << "\n\n";
    BigInt sumod = a.subMod(b, BigInt("28a895cfd01f98784949f1575804d0b34693049e8aa36312806fe6b5ce5a06e58534365a8c4853b84b25"));
    cout<<"sumod:      "<< sumod << "\n\n";
    BigInt mumod = a.mulMod(b, BigInt("28a895cfd01f98784949f1575804d0b34693049e8aa36312806fe6b5ce5a06e58534365a8c4853b84b25"));
    cout<<"mumod:      "<< mumod << "\n\n";
    BigInt pomod = a.powMod(b, BigInt("28a895cfd01f98784949f1575804d0b34693049e8aa36312806fe6b5ce5a06e58534365a8c4853b84b25"));
    cout<<"pomod:      "<< pomod << "\n\n";

   // BigInt binary = a >> 6;
    //cout<<"binary a:      ";
    //a.printBinary();
   // cout<< "\n\n";
   // cout<<"binary 'binary'";
   // binary.printBinary();
    //cout<< "\n\n";
    //cout<< binary.getbit(2);

    //BigInt exp = a.pow(b);
    //cout<<"exp:    "<< exp << "\n";
    

    BigInt A,B,C,N1,N2,N3,N,SUM;
    A.random(32);
    B.random(32);
    C.random(32);
    //N.random(32);
    N = 1000;
    SUM = A;
    for(BigInt i("1"); i<N; i = i + 1){
        SUM = SUM + A;
    }
    
    cout<<"Tests: "<< bool((A+B)*C == C*(A+B)) <<" "<< bool(C*(A+B) == A*C + B*C)<<" "<< bool(A*N == SUM);
    //cin.get();
    return 0;
}