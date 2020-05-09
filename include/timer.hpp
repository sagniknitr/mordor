
#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
typedef LARGE_INTEGER timeval;
#else
#include <sys/time.h>
#endif

namespace mordor {

class mordorTimer {
public:
  mordorTimer() {}
  ~mordorTimer() {}
  void init();
  void destoy();
  int64_t get_time_in_ms();

private:
  timeval tv_start;
  timeval tv_end;
};

typedef mordorTimer Timer;

} // namespace mordor
