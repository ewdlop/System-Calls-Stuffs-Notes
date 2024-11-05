#include <iostream>
#include <variant>
#include <thread>
#include <vector>
#include <coroutine>
#include <future>

using MyDataType = std::variant<int, std::string, float>;

// Coroutine promise type
struct Generator {
    struct promise_type {
        MyDataType value;
        std::suspend_always yield_value(MyDataType v) {
            value = v;
            return {};
        }
        std::suspend_never return_void() { return {}; }
        static auto get_return_object_on_allocation_failure() { return Generator{nullptr}; }
        Generator get_return_object() { return Generator{this}; }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void unhandled_exception() { std::exit(1); }
    };
    promise_type* coro;
    Generator(promise_type* p) : coro(p) {}
    Generator(Generator&& rhs) : coro(std::exchange(rhs.coro, nullptr)) {}
    ~Generator() { if (coro) coro->destroy(); }

    MyDataType next() {
        coro->resume();
        return coro->value;
    }
};

// Coroutine generator function
Generator dataGenerator() {
    co_yield 42;
    co_yield std::string("Hello World");
    co_yield 3.14f;
}

// Function to process the item
void processItem(MyDataType item) {
    if (std::holds_alternative<int>(item)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate async work
        std::cout << "Integer: " << std::get<int>(item) << std::endl;
    } else if (std::holds_alternative<std::string>(item)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(300)); // Simulate async work
        std::cout << "String: " << std::get<std::string>(item) << std::endl;
    } else if (std::holds_alternative<float>(item)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulate async work
        std::cout << "Float: " << std::get<float>(item) << std::endl;
    }
}

// Run the parallel processing
int main() {
    Generator gen = dataGenerator();
    std::vector<std::future<void>> futures;
    
    for (int i = 0; i < 3; ++i) {
        MyDataType item = gen.next();
        futures.push_back(std::async(std::launch::async, processItem, item));
    }

    for (auto& f : futures) {
        f.get();
    }

    return 0;
}
