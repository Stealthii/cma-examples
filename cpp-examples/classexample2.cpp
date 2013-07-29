#include <iostream>
using namespace std;
class myRectangle {
    int x,y;
    public:
    myRectangle(int, int);
    myRectangle();
    void set_values(int,int);
    int *get_values();
    int area();
};

myRectangle::myRectangle (int a, int b) {
    x = a;
    y = b;
}
myRectangle::myRectangle() {
    x = 1;
    y = 1;
}


void myRectangle::set_values(int a, int b) {
    x = a;
    y = b;
}

int myRectangle::area(void) {
    return(x * y);
}

int * myRectangle::get_values() {
        (int * values)[2]; 
        (*values)[0] = x;
        (*values)[1]=y;
        return(values);
}

int main() {
    myRectangle rect(1,2);
    myRectangle rect1;
    cout << "area: "  << rect.area() << endl;
    rect.set_values(3,4);
    cout << "area: "  << rect.area() << endl;
    return(0);
}





