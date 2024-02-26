#include <iostream>
#include <map>
#include <chrono>
#include <cstdlib>

std::map<int, int> createRandomMap(int size) {
    std::map<int, int> myMap;

    srand(time(0));
    for (int i = 0; i < size; ++i) {
        myMap[i] = rand() % 100;  
    }

    return myMap;
}

template<typename T>
double measureExecutionTime(T start, T end) {
    return std::chrono::duration<double, std::milli>(end - start).count();
}

int readValue(const std::map<int, int>& myMap, int index) {
    return myMap.at(index);
}

void writeValue(std::map<int, int>& myMap, int index, int value) {
    myMap[index] = value;
}

void updateValue(std::map<int, int>& myMap, int index, int increment) {
    myMap[index] += increment;
}

int main() {
    const int mapSize = 10000;
    std::map<int, int> myMap = createRandomMap(mapSize);

    auto startRead = std::chrono::high_resolution_clock::now();
    int readResult = readValue(myMap, 5000);  
    auto endRead = std::chrono::high_resolution_clock::now();
    std::cout << "Read value: " << readResult << ", Time: " << measureExecutionTime(startRead, endRead) << " ms" << std::endl;

    auto startWrite = std::chrono::high_resolution_clock::now();
    writeValue(myMap, 5000, 42);  
    auto endWrite = std::chrono::high_resolution_clock::now();
    std::cout << "Write value, Time: " << measureExecutionTime(startWrite, endWrite) << " ms" << std::endl;

    auto startUpdate = std::chrono::high_resolution_clock::now();
    updateValue(myMap, 5000, 10);  
    auto endUpdate = std::chrono::high_resolution_clock::now();
    std::cout << "Update value, Time: " << measureExecutionTime(startUpdate, endUpdate) << " ms" << std::endl;

    return 0;
}
