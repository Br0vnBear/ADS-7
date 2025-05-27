// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
  unsigned int rand_seed = static_cast<unsigned int>(time(0));

  std::cout << "N,Operations" << std::endl;

  std::vector<int> n_val;
  for (int n = 10; n <= 200; n += 10) {
    n_val.push_back(n);
  }

  for (int num : n_val) {
    if (num <= 0) continue;

    Train train;
    for (int i = 0; i < num; ++i) {
      train.addCar(rand_r(&rand_seed) % 2 == 1);
    }

    train.getLength();
    int op = train.getOpCount();

    std::cout << num << "," << op << std::endl;
  }

  std::cout << "\n--- Original Prompt Example";
  std::cout << " (60 wagons, all lights off) ---" << std::endl;
  Train train1;
  int cnt = 60;

  for (int i = 0; i < cnt; ++i) {
    train1.addCar(false);
  }
  std::cout << "Calculated length for example: "
            << train1.getLength() << std::endl;
  std::cout << "Operations for example: "
            << train1.getOpCount() << std::endl;

  return 0;
}
