// Copyright (C) 2023 Matheus Fernandes Bigolin <mfrdrbigolin@disroot.org>
// SPDX-License-Identifier: MIT

// Day Two, I Was Told There Would Be No Math.

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using Dimension = std::array<int, 3>;

static long long solve1(std::vector<Dimension> dimensions) {
  const auto total_paper{ std::transform_reduce(
      dimensions.cbegin(), dimensions.cend(), 0LL, std::plus{},
      [](const Dimension &dim) {
        const auto &[l, w, h] = dim;
        const auto a1{ l * w }, a2{ w * h }, a3{ l * h };

        return 2 * (a1 + a2 + a3) + std::min({ a1, a2, a3 });
      }) };

  return total_paper;
}

static long long solve2(std::vector<Dimension> dimensions) {
  const auto total_ribbon{ std::transform_reduce(
      dimensions.cbegin(), dimensions.cend(), 0LL, std::plus{},
      [](const Dimension &dim) {
        const auto &[l, w, h] = dim;
        const auto smallest_perimeter{ 2 * l + 2 * w + 2 * h -
                                       2 * std::max({ l, w, h }) };

        return smallest_perimeter + l * w * h;
      }) };

  return total_ribbon;
}

const std::regex DIMENSION_REGEX{ R"((\d+)x(\d+)x(\d+))" };

static std::vector<Dimension> parse_input(const std::string raw_data) {
  std::vector<Dimension> dimensions{};

  std::istringstream ss{ raw_data };
  std::string line{};
  while (std::getline(ss, line)) {
    auto l{ -1 }, w{ -1 }, h{ -1 };

    std::smatch match_dimension{};
    if (std::regex_match(line, match_dimension, DIMENSION_REGEX)) {
      l = std::stoi(match_dimension[1].str());
      w = std::stoi(match_dimension[2].str());
      h = std::stoi(match_dimension[3].str());
    }

    dimensions.push_back(Dimension{ l, w, h });
  }

  return dimensions;
}

void day02(std::string input_file) {
  const auto input_data{ parse_input(input_file) };

  const auto sol1{ solve1(input_data) };
  const auto sol2{ solve2(input_data) };

  std::cout << sol1 << std::endl;
  std::cout << sol2 << std::endl;
}
