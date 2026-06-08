#include <iostream>
#include <random>

int main() {
  int guess_range = 0;
  std::cout << "Pick a range of numbers to guess: ";
  std::cin >> guess_range;
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please enter a number" << std::endl;
  }

  int lives = 0;
  std::cout << "Pick number of lives: ";
  std::cin >> lives;
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Please enter a number" << std::endl;
  } else if (lives > guess_range) {
    lives = guess_range;
  }

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(1, guess_range);

  int secret_num = dist(gen);

  int guess = 0;

  bool running = true;

  while (running) {
    if (lives > 0) {
      std::cout << "Take a guess: ";
      std::cin >> guess;
      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number" << std::endl;
        continue;
      }
      if (guess < secret_num) {
        std::cout << "Too low" << std::endl;
        lives--;
        std::cout << lives << " Lives left" << std::endl;
      } else if (guess > secret_num) {
        std::cout << "Too high" << std::endl;
        lives--;
        std::cout << lives << " Lives left" << std::endl;
      } else {
        std::cout << "Correct!, you win!" << std::endl;
        running = false;
      }
    } else {
      std::cout << "Game Over" << std::endl;
      running = false;
    }
  }

  return 0;
}
