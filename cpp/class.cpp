#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;

    public:
        Rectangle(){
            length = breadth = 1;
        }

        Rectangle(int l, int b){
            length = l;
            breadth = b;
        }

        int area() {
            return length*breadth;
        }

        int perimeter(){
            return length+breadth;
        }

        void setLength(int newLength){
            length = newLength;
        }
        
        int getLength(){
            return length;
        }
};

int main(){

    Rectangle r(5, 2);

    cout << "area : " << r.area() << endl;

    cout << "perimeter : " << r.perimeter() << endl;
        
    r.setLength(10);
    
    cout << "updated Length : " << r.getLength() << endl;

    return 0;
}