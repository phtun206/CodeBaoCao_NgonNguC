#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    // Constructor mặc định
    Point() : x(0), y(0) {}
    // Constructor có tham số
    Point(int xVal, int yVal) : x(xVal), y(yVal) {}
    
    // Hàm setter
    void set(int xVal, int yVal) {
        x = xVal;
        y = yVal;
    }
    
    // Hàm getter (nên có để lấy giá trị)
    int getX() const { return x; }
    int getY() const { return y; }
    
    // In ra tọa độ (tùy chọn)
    void print() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

// Ví dụ sử dụng
int main() {
    Point p;
    p.set(3, 4);
    p.print(); // Output: (3, 4)
    Point p2(5, 6);
    p2.print(); // Output: (5, 6)
    return 0;
}
