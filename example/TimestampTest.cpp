#include "Timestamp.hpp"
#include <iostream>
// Linux 下使用 usleep，Windows 下使用 Sleep，注意参数单位不同
#ifdef _WIN32
#include <windows.h>
#define Sleep(ms) Sleep(ms)
#else
#include <unistd.h>
#define Sleep(ms) usleep((ms) * 1000)
#endif
#include "LogMessage.hpp"
#include "Logger.hpp"
// write to log file
FILE *fp = nullptr;

void outputFile(const std::string &msg) { size_t n = fwrite(msg.c_str(), sizeof(char), msg.size(), fp); }
void flushFile() { fflush(fp); }

int main() {
    fp = fopen("shanchuan.log", "w");
    if (!fp) {
        std::cerr << "Failed to open log file." << std::endl;
        return 1;
    }
    logsys::Logger::SetOuput(outputFile);
    logsys::Logger::SetFlush(flushFile); {
        logsys::Logger log(logsys::LOG_LEVEL::INFO, __FILE__, __FUNCTION__, __LINE__);
    }
    fclose(fp);
    fp = nullptr;
    std::cout << "Log message written to file." << std::endl;
    return 0;
}

#define TIMESTAMP_TEST 0
#define LOGMESSAGE_TEST 0

#if LOGMESSAGE_TEST
void testLogMessage() {
    logsys::LogMessage log(logsys::LOG_LEVEL::DEBUG, __FILE__, __FUNCTION__, __LINE__);
    log << "This is a test log message for func.";
    std::cout << log.toString() << std::endl;
}
int main() {
    logsys::LogMessage log(logsys::LOG_LEVEL::INFO, __FILE__, __FUNCTION__, __LINE__);
    log << "This is a test log message.";
    std::cout << log.toString() << std::endl;
    testLogMessage();
    return 0;
}
#endif
#if TIMESTAMP_TEST
class Test
{
public:
    Test() {
        std::cout << "Test constructor" << std::endl;
        start = logsys::Timestamp::Now();
    }
    ~Test() {
        std::cout << "Test destructor" << std::endl;
        end = logsys::Timestamp::Now();
        std::cout << "Elapsed time: " << diffMicroSeconds(end, start) << std::endl;
    }
private:
    logsys::Timestamp start;
    logsys::Timestamp end;
};
int main() {
    logsys::Timestamp test;
    test = logsys::Timestamp::Now();
    std::cout << test.toString() << std::endl;
    std::cout << test.toFormattedString() << std::endl;
    std::cout << test.toFileString() << std::endl; {
        Test t;
        Sleep(200); // 模拟耗时操作
    }
    return 0;
}
#endif