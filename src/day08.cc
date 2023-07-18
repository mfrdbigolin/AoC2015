// Copyright (C) 2023 Matheus Fernandes Bigolin <mfrdrbigolin@disroot.org>
// SPDX-License-Identifier: MIT

// Day Eight, Matchsticks.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int solve1(const std::vector<std::string> strings) {
  auto count{ 2 * strings.size() };

  for (const auto &str : strings) {
    for (decltype(str.size()) i{ 0 }; i < str.size(); ++i) {
      if (str[i] == '\\') {
        if (str[i + 1] == 'x') {
          i += 3;
          count += 3;
        } else {
          i += 1;
          count += 1;
        }
      }
    }
  }

  return count;
}

int solve2(const std::vector<std::string> strings) {
  auto count{ 2 * strings.size() };

  for (const auto &str : strings) {
    for (const auto chr : str) {
      if (chr == '\\' || chr == '\"') {
        count += 1;
      }
    }
  }

  return count;
}

std::vector<std::string> parse_strings(const std::string string_file) {
  std::vector<std::string> strings{};

  std::istringstream ss{ string_file };
  std::string line{};
  while (std::getline(ss, line)) {
    strings.push_back(line);
  }

  return strings;
}

void day08(const std::string input_file) {
  const auto strings{ parse_strings(input_file) };

  const auto sol1{ solve1(strings) };
  const auto sol2{ solve2(strings) };

  std::cout << sol1 << std::endl;
  std::cout << sol2 << std::endl;
}
