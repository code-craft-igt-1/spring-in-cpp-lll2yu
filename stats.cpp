#include "stats.h"

namespace Statistics {

Stats ComputeStatistics(const std::vector<float>& data) {
    Stats stats;
    if (data.empty()) {
        stats.average = std::numeric_limits<float>::quiet_NaN();
        stats.min = std::numeric_limits<float>::quiet_NaN();
        stats.max = std::numeric_limits<float>::quiet_NaN();
        return stats;
    }

    float sum = 0.0;
    stats.min = std::numeric_limits<float>::max();
    stats.max = std::numeric_limits<float>::lowest();

    for (auto num : data) {
        sum += num;
        if (num < stats.min) {
            stats.min = num;
        }
        if (num > stats.max) {
            stats.max = num;
        }
    }

    stats.average = sum / data.size();
    return stats;
}

}