#include <iostream>
#include <array>
#include <chrono>
#include <cstdlib>

void live_die();
void print();
bool should_live(bool current_status, int x_axis, int y_axis);

const int SIZE{100};
std::array<std::array<bool, SIZE>, SIZE> board;

int main(int argc, char *argv[])
{
  std::srand(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));
  int row{0};
  int column{0};

  for (int i = 0; i < 1000; i++)
  {
    row = rand() % (SIZE - 1) + 1;
    column = rand() % (SIZE - 1) + 1;

    board[column][row] = true;
  }

  for (;;)
  {
    print();
    live_die();
  }

  return 0;
}
