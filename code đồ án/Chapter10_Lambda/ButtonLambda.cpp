#include <functional>
#include <cstdio>

// Giả lập các class phần cứng để code có thể biên dịch được (Mocking)
namespace hal {
    enum class port_a {};
    enum class pin { p4, p5 };
    
    template <typename Port>
    class gpio_stm32 {
    public:
        gpio_stm32(pin p, const std::function<void()>& callback) {
            // Giả lập đăng ký callback
            this->callback_ = callback;
        }
        // Hàm giả lập việc nhấn nút để test
        void simulatePress() {
            if(callback_) callback_();
        }
    private:
        std::function<void()> callback_;
    };
}

// --- Phần Code chính trong báo cáo ---

// Class quản lý GPIO
class gpio {
public:
    gpio(const std::function<void()>& on_press) : on_press_(on_press) {
        // gpio_interrupt_manager::register_interrupt_handler(this); // Comment lại vì thiếu thư viện thực tế
    }
    void execute_interrupt_handler() const {
        if (is_interrupt_generated()) {
            clear_interrupt_flag();
            if (on_press_) on_press_();
        }
    }
private:
    virtual bool is_interrupt_generated() const = 0;
    virtual void clear_interrupt_flag() const = 0;
    std::function<void()> on_press_ = nullptr;
};

// --- Phần Bài tập thực hành Chương 10 ---

int main() {
    // Khởi tạo button 1 với Lambda
    hal::gpio_stm32<hal::port_a> button1(hal::pin::p4, []() {
        printf("Button1 pressed!\n");
    });

    // Khởi tạo button 2 với Lambda
    hal::gpio_stm32<hal::port_a> button2(hal::pin::p5, []() {
        printf("Button2 pressed!\n");
    });

    // Giả lập sự kiện nhấn (để kiểm chứng kết quả)
    printf("Simulating button presses...\n");
    button1.simulatePress();
    button2.simulatePress();

    return 0;
}