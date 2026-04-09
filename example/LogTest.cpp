#include "Logger.hpp"

void func(){
    for(int i = 0; i < 10; ++i) {
        LOG_TRACE << "This is a trace log message." << i;
        LOG_DEBUG << "This is a debug log message." << i;
        LOG_INFO  << "This is an info log message." << i;
        LOG_WARN  << "This is a warn log message." << i;
        LOG_ERROR << "This is an error log message." << i;
        if (i == 5) {
            LOG_FATAL << "This is a fatal log message." << i;
        }
    }
}
int main()
{
    //logsys::Logger::SetLogLevel(logsys::LOG_LEVEL::DEBUG); // 设置日志等级为 DEBUG
    func();
    return 0;
}