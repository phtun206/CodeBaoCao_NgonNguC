#include <iostream>
#include <array>

// Hằng số với const
const int bufferSize = 128;
// Hằng số với constexpr
constexpr int maxConnections = 10;

// Hàm constexpr
constexpr int calculateBufferSize(int multiplier) {
    return maxConnections * multiplier;
}

// Sử dụng constexpr để khai báo kích thước mảng
constexpr int computedSize = calculateBufferSize(20); // 10 * 20 = 200

int main() {
    // Mảng tĩnh với kích thước biết tại biên dịch
    std::array<char, computedSize> buffer; 
    
    std::cout << "bufferSize (const): " << bufferSize << "\n";
    std::cout << "maxConnections (constexpr): " << maxConnections << "\n";
    std::cout << "computedSize (constexpr function): " << computedSize << "\n";
    std::cout << "Buffer size in bytes: " << buffer.size() << "\n";
    
    return 0;
}