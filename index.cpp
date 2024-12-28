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

void live_die()
{
  for (int i = 1; i < SIZE; i++)
  {
    for (int j = 1; j < SIZE; j++)
    {
      board[i][j] = should_live(board[i][j], j, i);
    }
  }
}

bool should_live(bool current_status, int x_axis, int y_axis)
{
  int neighbors{0};

  if (board[y_axis][x_axis + 1] == 1)
    neighbors++;
  if (board[y_axis][x_axis - 1] == 1)
    neighbors++;
  if (board[y_axis - 1][x_axis] == 1)
    neighbors++;
  if (board[y_axis + 1][x_axis] == 1)
    neighbors++;
  if (board[y_axis + 1][x_axis + 1] == 1)
    neighbors++;
  if (board[y_axis - 1][x_axis + 1] == 1)
    neighbors++;
  if (board[y_axis + 1][x_axis - 1] == 1)
    neighbors++;
  if (board[y_axis - 1][x_axis - 1] == 1)
    neighbors++;

  if (current_status)
  {
    if (neighbors < 2 || neighbors > 3)
      return false;
    return true;
  }
  else
  {
    if (neighbors == 3)
      return true;
    return false;
  }
}

void print()
{
  for (const auto &row : board)
  {
    for (const auto &cell : row)
    {
      std::cout << (cell ? '#' : ' ');
    }
    std::cout << '\n';
  }
  std::cout << "\n";
}
