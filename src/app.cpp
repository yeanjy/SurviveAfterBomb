#include "app.hpp"

app::app(){};

void app::run()
{
  survivor dad("Robson", 35, 'm', 10, 10);
  survivor mom("Marta", 31, 'f',10 ,10);
  survivor son("Erick", 14, 'm', 10, 10);
  survivor daughter("Laura", 17, 'f', 10, 10);

  while (this->isRun) {
  std::cout << "hello world" << std::endl;
}
};
