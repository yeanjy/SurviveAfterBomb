#include <memory>
#include "app.hpp"

int main(){
  std::unique_ptr<app> mApp = std::make_unique<app>();
  mApp->run();
  return 0;
}
