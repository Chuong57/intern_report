#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<int> createRandomVector(int size) {
    vector<int> vec;
    vec.reserve(size);

    srand(time(0));
    for (int i = 0; i < size; ++i) {
        vec.push_back(rand() % 100);  
    }

    return vec;
}

double measureExecutionTime(clock_t start, clock_t end) {
    return double(end - start) / CLOCKS_PER_SEC * 1000.0; 
}

int readValue(const vector<int>& vec, int index) {
    return vec[index];
}

void writeValue(vector<int>& vec, int index, int value) {
    vec[index] = value;
}

void updateValue(vector<int>& vec, int index, int increment) {
    vec[index] += increment;
}

int main() {
    const int vectorSize = 10000;
    vector<int> myVector = createRandomVector(vectorSize);

    clock_t startRead = clock();
    int readResult = readValue(myVector, 5000);  
    clock_t endRead = clock();
    cout << "Read value: " << readResult << ", Time: " << measureExecutionTime(startRead, endRead) << " ms" << endl;

    clock_t startWrite = clock();
    writeValue(myVector, 5000, 42);  
    clock_t endWrite = clock();
    cout << "Write value, Time: " << measureExecutionTime(startWrite, endWrite) << " ms" << endl;

    clock_t startUpdate = clock();
    updateValue(myVector, 5000, 10);  
    clock_t endUpdate = clock();
    cout << "Update value, Time: " << measureExecutionTime(startUpdate, endUpdate) << " ms" << endl;

    return 0;
}
