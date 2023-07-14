// Copyright (C) 2023 Matheus Fernandes Bigolin <mfrdrbigolin@disroot.org>
// SPDX-License-Identifier: MIT

// Day Six, Probably a Fire Hazard.

#include <array>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

enum class InstructionType { OFF = 0, ON = 1, TOGGLE = 2 };

using Instruction =
    std::tuple<InstructionType, std::pair<int, int>, std::pair<int, int>>;

static int solve1(const std::vector<Instruction> instructions) {
  std::array<bool, 1000 * 1000> grid{};
  auto area{ 0 };

  for (const auto &[type, range1, range2] : instructions) {
    const auto [x1, y1]{ range1 };
    const auto [x2, y2]{ range2 };

    for (auto i{ x1 }; i <= x2; ++i) {
      for (auto j{ y1 }; j <= y2; ++j) {
        const auto grid_index{ 1000 * i + j };

        switch (type) {
        case InstructionType::OFF:
          area -= grid[grid_index];
          grid[grid_index] = false;
          break;
        case InstructionType::TOGGLE:
          area += grid[grid_index] ? -1 : 1;
          grid[grid_index] ^= true;
          break;
        case InstructionType::ON:
          area += !grid[grid_index];
          grid[grid_index] = true;
        }
      }
    }
  }

  return area;
}

static int solve2(const std::vector<Instruction> instructions) {
  std::array<int, 1000 * 1000> grid{};
  auto area{ 0 };

  for (const auto &[type, range1, range2] : instructions) {
    const auto [x1, y1]{ range1 };
    const auto [x2, y2]{ range2 };

    area += static_cast<int>(type) * (x2 - x1 + 1) * (y2 - y1 + 1);

    for (auto i{ x1 }; i <= x2; ++i) {
      for (auto j{ y1 }; j <= y2; ++j) {
        const auto grid_index{ 1000 * i + j };

        if (type != InstructionType::OFF) {
          grid[grid_index] += static_cast<int>(type);
        } else {
          area -= grid[grid_index] > 0;
          grid[grid_index] -= grid[grid_index] > 0;
        }
      }
    }
  }

  return area;
}

const std::map<std::string, InstructionType> INSTR_KEYWORD_TYPE{
  { "turn off", InstructionType::OFF },
  { "turn on", InstructionType::ON },
  { "toggle", InstructionType::TOGGLE }
};

const std::regex INSTRUCTION_REGEX{
  R"((\w+ ?\w*) (\d+),(\d+) through (\d+),(\d+))"
};

static std::vector<Instruction>
parse_instructions(const std::string raw_instrs) {
  std::vector<Instruction> instructions{};

  std::istringstream ss{ raw_instrs };
  std::string line{};
  while (std::getline(ss, line)) {
    std::smatch match_instr{};
    if (std::regex_match(line, match_instr, INSTRUCTION_REGEX)) {
      const auto instr_type{ INSTR_KEYWORD_TYPE.at(match_instr[1].str()) };
      const std::pair<int, int> range1{ std::stoi(match_instr[2].str()),
                                        std::stoi(match_instr[3].str()) };
      const std::pair<int, int> range2{ std::stoi(match_instr[4].str()),
                                        std::stoi(match_instr[5].str()) };

      instructions.push_back({ instr_type, range1, range2 });
    }
  }

  return instructions;
}

void day06(const std::string input_file) {
  const auto instructions{ parse_instructions(input_file) };

  const auto sol1{ solve1(instructions) };
  const auto sol2{ solve2(instructions) };

  std::cout << sol1 << std::endl;
  std::cout << sol2 << std::endl;
}
