#include "func.cpp"

int main(){
    BigInt a("91448a895cfd0200f098e2effaf19391c4a837ff199610c9bd4241b1a226effbc0ba1e4c9f81cd703a4212c02f96767adbc1e336b9d2cc5eccc98bd202bddc8fa5011f2df252fbb1843b3422db8f63129bad292c3b42a24");
    BigInt b("320736a58fe16964aa40fbafbcb63175b370f70823dd4212ff42bfbc778478b757e15cb8f9eb1bc33ae07f2366f07c6bade3f8cb1745bd0622073c835d9ed17b9897730a542ab333ec3f25e91a36787064d30eb8c5a396d5345f580b8104249d9d90cf6a85a2ce2e09a2ef2df9308cc0c9f57ff7727e6b0f56294dafff4c3b994");
    cout<<a<<" "<<a.size()<<endl;
    cout<< endl;
    BigInt sum = a + b;
    cout<< sum;
    //cin.get();
    return 0;
}