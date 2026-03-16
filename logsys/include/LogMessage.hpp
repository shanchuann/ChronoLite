#include <string>
#include <sstream>

#include "LogCommon.hpp" // 日志等级

#ifndef LOGSYS_LOGMESSAGE_HPP
#define LOGSYS_LOGMESSAGE_HPP

namespace logsys
{
    class LogMessage
    {
    private:
        std::string header_;
        std::string text_;
        logsys::LOG_LEVEL level_;

    public:
        LogMessage(const logsys::LOG_LEVEL &level, const std::string &filename, const std::string &funcname, const int line);
        ~LogMessage();
        const logsys::LOG_LEVEL &getLogLevel() const
        {
            return level_;
        }
        void setLogLevel(const logsys::LOG_LEVEL &level)
        {
            level_ = level;
        }
        const std::string toString() const
        {
            return header_ + text_;
        }

        template <typename T>
        LogMessage &operator<<(const T &text)
        {
            std::stringstream sout;
            sout << ": " << text;
            text_ += sout.str();
            return *this;
        }
    };
}
#endif // LOGSYS_LOGMESSAGE_HPP