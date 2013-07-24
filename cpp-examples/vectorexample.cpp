#include <iostream>

using namespace std;

class myVector {
    int x;
    int y;
    public:
    myVector();
    myVector(int,int);
    myVector operator+(myVector);
    friend ostream& operator<<(ostream &, myVector);


};

ostream& operator<<(ostream& os, myVector v1) {
    os << v1.x << " " << v1.y << endl;
}
myVector::myVector(int a, int b) {
    x = a;
    y = b;
}

myVector::myVector() {
    x = 0;
    y = 0;
}

myVector myVector::operator+ (myVector v2) {
    myVector v3;
    v3.x = x+ v2.x;
    v3.y = y + v2.y;
    return(v3);
}

int main(void) {

    myVector v1(2,3);
    myVector v2(3,4);
    myVector v3;

    v3 = v1 + v2;
    cout << v3;
}
