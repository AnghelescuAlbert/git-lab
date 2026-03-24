#include <iostream>
#include <cstdlib>      // rand()
#include <ctime>        // time()
#include <random>       // mt19937, uniform_int_distribution
#include <chrono>       // seed cu nanosec
#include <thread>       // pentru thread id

int main() {
    // 1️⃣ rand() + srand(time)
    srand(time(nullptr));
    int r1 = rand() % 100;
    std::cout << "Random 1: " << r1 << "\n";

    // 2️⃣ <random> mt19937 + random_device
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);
    int r2 = dis(gen);
    std::cout << "Random 2: " << r2 << "\n";

    // 3️⃣ chrono nanosec seed + mt19937
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 gen3(seed);
    std::uniform_int_distribution<> dis3(0, 99);
    int r3 = dis3(gen3);
    std::cout << "Random 3: " << r3 << "\n";

    // 4️⃣ rand() + thread id + time
    int r4 = (rand() + std::hash<std::thread::id>{}(std::this_thread::get_id())) % 100;
    std::cout << "Random 4: " << r4 << "\n";

    // 5️⃣ Linear Congruential Generator simplu
    unsigned long lcg = seed;
    lcg = (lcg * 1664525 + 1013904223) % 100;
    int r5 = static_cast<int>(lcg);
    std::cout << "Random 5: " << r5 << "\n";

    return 0;
}
