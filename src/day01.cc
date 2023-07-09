// Copyright (C) 2023 Matheus Fernandes Bigolin <mfrdrbigolin@disroot.org>
// SPDX-License-Identifier: MIT

// Day One, Not Quite Lisp.

#include <iostream>
#include <numeric>
#include <string>
#include <vector>

static int solve1(const std::vector<int> instructions) {
  const auto floor{ std::reduce(instructions.begin(), instructions.end()) };

  return floor;
}

static decltype(std::vector<int>().size())
solve2(const std::vector<int> instructions, const int desired_floor) {
  auto floor{ 0 };
  for (decltype(instructions.size()) i{ 0 }; i < instructions.size(); ++i) {
    floor += instructions[i];

    if (floor == desired_floor) {
      return i + 1;
    }
  }

  return -1;
}

static std::vector<int> parse_input(const std::string raw_data) {
  std::vector<int> input_data{};

  for (const auto &ins : raw_data) {
    input_data.push_back(ins == '(' ? 1 : -1);
  }

  return input_data;
}

void day01(std::string input_file) {
  auto input_data{ parse_input(input_file) };

  auto sol1{ solve1(input_data) };
  auto sol2{ solve2(input_data, -1) };

  std::cout << sol1 << std::endl;
  std::cout << sol2 << std::endl;
}
