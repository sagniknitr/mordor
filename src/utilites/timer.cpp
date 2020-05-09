#include "utils.h"

#include <cinttypes>
#include <cstddef>

namespace draco {
void mordorTimer::Start() { gettimeofday(&tv_start, NULL); }

void mordorTimer::Stop() { gettimeofday(&tv_end, NULL); }

int64_t mordorTimer::GetInMs() {

  const int64_t seconds = (tv_end.tv_sec - tv_start.tv_sec) * 1000;
  const int64_t milliseconds = (tv_end.tv_usec - tv_start.tv_usec) / 1000;
  return seconds + milliseconds;
}

} // namespace draco
