// Copyright (C) 2023 Matheus Fernandes Bigolin <mfrdrbigolin@disroot.org>
// SPDX-License-Identifier: MIT

// Day Five, Doesn't He Have Intern-Elves For This?

#include <array>
#include <functional>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

const std::set VOWELS{ 'a', 'e', 'i', 'o', 'u' };
const std::set DISALLOWED_LETTERS{ 'a', 'c', 'p', 'x' };

static bool is_nice1(const std::string str) {
  auto vowel_count{ 0 };
  auto letter_repeats{ false };
  auto contains_disallowed_string{ false };

  auto prev_letter{ '\0' };
  for (const auto letter : str) {
    if (VOWELS.find(letter) != VOWELS.cend()) {
      ++vowel_count;
    }

    letter_repeats |= letter == prev_letter;

    if (DISALLOWED_LETTERS.find(prev_letter) != DISALLOWED_LETTERS.cend() &&
        letter == prev_letter + 1) {
      contains_disallowed_string = true;
    }

    prev_letter = letter;
  }

  return vowel_count >= 3 && letter_repeats && !contains_disallowed_string;
}

static bool is_nice2(const std::string str) {
  if (str.size() < 4) {
    return false;
  }

  auto letter_pair_repeats{ false };
  auto letter_repeats_with_space{ false };

  // Stores the pairs of letters as a two-digit base-26 number.
  std::array<bool, 26 * 26> pairs{};
  // Use a on-hold variable to delay insertion and prevent letter overlaps.
  auto on_hold = 26 * (str[1] - 'a') + (str[0] - 'a');

  for (decltype(str.size()) i{ 2 }; i < str.size(); ++i) {
    const auto pair_value = 26 * (str[i] - 'a') + (str[i - 1] - 'a');

    letter_pair_repeats |= pairs[pair_value];
    letter_repeats_with_space |= str[i] == str[i - 2];

    pairs[on_hold] = true;
    on_hold = pair_value;
  }

  return letter_pair_repeats && letter_repeats_with_space;
}

static int solve(const std::vector<std::string> strings,
                 const std::function<int(std::string)> is_nice) {
  auto nice_count{ 0 };

  for (const auto &str : strings) {
    if (is_nice(str)) {
      ++nice_count;
    }
  }

  return nice_count;
}

static std::vector<std::string> parse_input(const std::string raw_data) {
  std::vector<std::string> strings{};

  std::istringstream ss{ raw_data };
  std::string str{};
  while (std::getline(ss, str)) {
    strings.push_back(str);
  }

  return strings;
}

void day05(const std::string input_file) {
  const auto input_data{ parse_input(input_file) };

  const auto sol1{ solve(input_data, is_nice1) };
  const auto sol2{ solve(input_data, is_nice2) };

  std::cout << sol1 << std::endl;
  std::cout << sol2 << std::endl;
}
