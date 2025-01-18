// Threading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <variant>
#include <vector>
#include <thread>
#include <future>
#include <chrono>

// Define a variant type to represent various types
using MyDataType = std::variant<int, std::string, float>;

// Function to process each item
void processItem(const MyDataType& item) {
    std::visit(overloaded{
        [](int i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulating async work
            std::cout << "Integer: " << i << std::endl;
        },
        [](const std::string& s) {
            std::this_thread::sleep_for(std::chrono::milliseconds(300)); // Simulating async work
            std::cout << "String: " << s << std::endl;
        },
        [](float f) {
            std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulating async work
            std::cout << "Float: " << f << std::endl;
        }
    }, item);
}

// Helper for std::visit with lambda overloads
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

int main() {
    std::cout << "Hello World!\n";
    // Define a sequence of various types
    std::vector<MyDataType> asyncSequence = {42, std::string("Hello World"), 3.14f};

    // Process the sequence in parallel
    std::vector<std::future<void>> futures;
    for (const auto& item : asyncSequence) {
        futures.emplace_back(std::async(std::launch::async, processItem, item));
    }

    // Wait for all tasks to complete
    for(auto &fut : futures) {
        fut.get();
    }

    return 0;
}
