#include "iostream"
#include "vector"
#include "string"

using namespace std;

template <class T>
class Rectangle{
    private:
        T length;
        T breadth;

    public:
        Rectangle(){
            length = breadth = 1;
        }

        Rectangle(T l, T b){
            length = l;
            breadth = b;
        }

        T area() {
            return length*breadth;
        }

        T perimeter(){
            return length+breadth;
        }

        void setLength(T newLength){
            length = newLength;
        }
        
        T getLength(){
            return length;
        }
};

int main(){

    Rectangle<float> r(5.45, 2.65);

    cout << "area : " << r.area() << endl;

    cout << "perimeter : " << r.perimeter() << endl;
        
    r.setLength(10);
    
    cout << "updated Length : " << r.getLength() << endl;

    return 0;
}