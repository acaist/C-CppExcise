#include <iostream>
#include <thread>
#include <vector>

// Function to perform work on a partition of the data
void processPartition(const std::vector<int>& data, int start, int end) {
    for (int i = start; i < end; ++i) {
        // Perform some work on data[i]
        std::cout << "Processing element at index " << i << ": " << data[i] << std::endl;
    }
}


void printThreadId() {
    printf("Thread ID: %ld\n", std::this_thread::get_id());
}

int lanchthread() {
    std::thread threads[4];

    // Launch 4 threads
    for (int i = 0; i < 4; ++i) {
        threads[i] = std::thread(printThreadId);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 4; ++i) {
        threads[i].join();
    }

    return 0;
}

int main() {
    
    lanchthread();


    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int numThreads = 4;  // Number of threads to use
    int partitionSize = data.size() / numThreads;  // Size of each partition

    std::vector<std::thread> threads;

    // Create and launch threads
    for (int i = 0; i < numThreads; ++i) {
        int start = i * partitionSize;
        int end = (i == numThreads - 1) ? data.size() : (i + 1) * partitionSize;

        threads.emplace_back(processPartition, std::ref(data), start, end);
        std::cout<<"i am thread "<<threads[0].get_id()<<std::endl;
        
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}