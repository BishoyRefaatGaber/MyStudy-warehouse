#include "OperatingSystem.hpp"
#include "Scheduler.hpp"
#include <iostream>

int main() {
  // ThreadScheduler_Implementation
  // std::shared_ptr<ThreadScheduler_Implementation> ThrdSkdlrImplmnt;
  std::shared_ptr<ThreadScheduler> UnixPTS =
      std::make_shared<PreemptiveThreadScheduler>(std::make_unique<Unix>());
  std::shared_ptr<ThreadScheduler> WindowsTSTS =
      std::make_shared<TimeSlicedThreadScheduler>(std::make_unique<Windows>());
  UnixPTS->PerformScheduler().OS();
  std::cout << std::endl;
  WindowsTSTS->PerformScheduler().OS();

  return 0;
}