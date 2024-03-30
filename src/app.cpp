#include "app.hpp"

app::app(){};

void app::run()
{
  while (this->isRun) {
  std::cout << "hello world" << std::endl;
}
};
