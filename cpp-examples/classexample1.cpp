#include <iostream>
using namespace std;

class myRectangle {
    int *width,*height;
    public:
    myRectangle(int, int);
    ~myRectangle();
    void set_values(int,int);
    int area();
};

myRectangle::myRectangle(int a, int b) {
    width = new int;
    height = new int;
    *width = a;
    *height = b;
}

myRectangle::~myRectangle() {
    delete width;
    delete height;
}

void myRectangle::set_values(int a, int b) {
    width=a;
    height=b;
}

int myRectangle::area(void) {
    return((*width)*(*height));
}

int main() {
    int a =1;
    int b = 2;
    myRectangle rect(a,b);
    rect.set_values(3,4);
    cout << "area: " << rect.area() << endl;
    return 0;
}
