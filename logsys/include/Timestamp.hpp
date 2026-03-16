#include <stdint.h>
#include <string>

#ifndef LOGSYS_TIMESTAMP_HPP
#define LOGSYS_TIMESTAMP_HPP

namespace logsys {

    // 时间戳类
    // 封装了微秒级的时间戳，提供获取当前时间、格式化输出等功能。
    // 内部使用 int64_t 存储从 1970-01-01 00:00:00 UTC 开始的微秒数。
    class Timestamp {
    private:
        int64_t microSec; // 从 1970年1月1日 00:00:00 到现在的微秒数
    public:
    
        // 创建一个无效的时间戳（microSec = 0）
        Timestamp();
        Timestamp(const int64_t ms);
        ~Timestamp();

        // 交换两个 Timestamp 对象
        void swap(Timestamp& other);

        // 判断时间戳是否有效
        bool vaild() const;

        // 转换为字符串
        // 格式: 秒[.微秒]
        std::string toString() const;

        // 转换为格式化字符串
        // showMic 是否显示微秒部分
        // 格式: YYYY/MM/DD HH:MM:SS[.微秒]
        std::string toFormattedString(bool showMic = true) const;

        // 转换为适合文件名的字符串
        // 格式: YYYYMMDD-HHMMSS[.微秒]
        std::string toFileString() const;

        // 获取微秒数
        int64_t getMicroSec() const;

        // 获取秒数
        time_t getSeconds() const;

    public:
        static const int kMicroSecPerSecond = 1000*1000; // 每秒的微秒数

        // 获取当前时间戳
        static Timestamp Now();

        // 获取一个无效的时间戳
        static Timestamp invalid();
    };

    // 计算两个时间戳之间的差值，返回秒数
    inline time_t diffSeconds(const Timestamp& high, const Timestamp& low) {
        return high.getSeconds() - low.getSeconds();
    }
    // 计算两个时间戳之间的差值，返回微秒数
    inline int64_t diffMicroSeconds(const Timestamp& high, const Timestamp& low) {
        return high.getMicroSec() - low.getMicroSec();
    }
    // 在一个时间戳的基础上增加指定秒数，返回新的时间戳
    inline Timestamp addTime(const Timestamp& timestamp, double seconds) {
        int64_t delta = static_cast<int64_t>(seconds * Timestamp::kMicroSecPerSecond);
        return Timestamp(timestamp.getMicroSec() + delta);
    }
}
#endif // LOGSYS_TIMESTAMP_HPP