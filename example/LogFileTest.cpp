#include "LogFile.hpp"
#include "Logger.hpp"

logsys::LogFile * pfile = nullptr;

void fileOutput(const std::string &msg) { 
    pfile->append(msg);
}

void fileFlush() { 
    pfile->flush();
}

int main()
{
    logsys::Logger::SetOuput(fileOutput);
    logsys::Logger::SetFlush(fileFlush);
    pfile = new logsys::LogFile("logfile_test", 1024 * 128, 3, 30, true);
    for(int i = 0; i < 100; ++i) {
        LOG_TRACE << "This is a trace log message." << i;
        LOG_DEBUG << "This is a debug log message." << i;
        LOG_INFO  << "This is an info log message." << i;
        LOG_WARN  << "This is a warn log message." << i;
        LOG_ERROR << "This is an error log message." << i;
        if (i == 5) {
            LOG_FATAL << "This is a fatal log message." << i;
        }
    }
    delete pfile;
    return 0;
}