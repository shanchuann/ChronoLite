#include "Timestamp.hpp"
#include <iostream>
#if 0
int main()
{
    // Simple test for Timestamp class and the new functions
    logsys::Timestamp t1(1625079045123456); // Example timestamp in microseconds
    logsys::Timestamp t2(1625079056123456); // Another example timestamp in microseconds

    std::cout << "Timestamp 1: " << t1.toFormattedString() << std::endl;
    std::cout << "Timestamp 2: " << t2.toFormattedString() << std::endl;

    time_t diffSec = logsys::diffSeconds(t2, t1);
    int64_t diffMicroSec = logsys::diffMicroSeconds(t2, t1);

    std::cout << "Difference in seconds: " << diffSec << " seconds" << std::endl;
    std::cout << "Difference in microseconds: " << diffMicroSec << " microseconds" << std::endl;

    double addSeconds = 10.5; // Add 10.5 seconds
    logsys::Timestamp t3 = logsys::addTime(t1, addSeconds);
    std::cout << "Timestamp 1 after adding " << addSeconds << " seconds: " << t3.toFormattedString() << std::endl;

    return 0;
}

// Simple test for Timestamp class
int main()
{
    logsys::Timestamp test;
    test = logsys::Timestamp::Now();
    std::cout << test.toString() << std::endl;
    std::cout << test.toFormattedString() << std::endl;
    std::cout << test.toFileString() << std::endl;
}
#endif