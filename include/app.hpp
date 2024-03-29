#include "survivor.hpp"

class app{
public:
  app() = default;
  void run();

  bool isRun = true;
  survivor dad();
  survivor mon();
  survivor son();
  survivor daughter();
};
