#include "LogMessage.hpp"
#include "Timestamp.hpp"
namespace logsys
{
    LogMessage::LogMessage(const logsys::LOG_LEVEL &level, const std::string &filename, const std::string &funcname, const int line)
        : header_{}, text_{}, level_(level)
    {
        std::stringstream sout;
        sout << logsys::Timestamp::Now().toFormattedString(false) << " "; // 2026/03/08 12:00:00
        sout << logsys::LLTOSTR[static_cast<int>(level_)] << " ";
        const size_t pos = filename.find_last_of('/');
        const std::string fname = filename.substr(pos + 1);
        sout << fname << " " << funcname << " " << line;
        header_ = sout.str();
    }
    LogMessage ::~LogMessage() {}
}