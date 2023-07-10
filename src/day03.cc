// Copyright (C) 2023 Matheus Fernandes Bigolin <mfrdrbigolin@disroot.org>
// SPDX-License-Identifier: MIT

// Day Three, Perfectly Spherical Houses in a Vacuum.

#include "utils.hh"

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

enum class Move : char { UP = '^', DOWN = 'v', RIGHT = '>', LEFT = '<' };
const std::map<Move, std::pair<int, int>> MOVE_COORDS{
  { Move::UP, { 0, 1 } },
  { Move::DOWN, { 0, -1 } },
  { Move::RIGHT, { 1, 0 } },
  { Move::LEFT, { -1, 0 } }
};

static int solve(const std::vector<Move> moves, const int helpers = 0) {
  std::set<int> visited_houses{ pairing(0, 0) };

  std::vector<std::pair<int, int>> positions(1 + helpers, { 0, 0 });
  for (const auto &move : moves) {
    auto [di, dj] = MOVE_COORDS.at(move);
    positions[0].first += di;
    positions[0].second += dj;

    const auto paired_move = pairing(positions[0].first, positions[0].second);
    visited_houses.insert(paired_move);
    std::rotate(positions.begin(), positions.begin() + 1, positions.end());
  }

  return visited_houses.size();
}

static std::vector<Move> parse_input(const std::string raw_moves) {
  std::vector<Move> moves(raw_moves.size());

  std::transform(raw_moves.cbegin(), raw_moves.cend(), moves.begin(),
                 [](const char &mv) { return static_cast<Move>(mv); });

  return moves;
}

void day03(std::string input_file) {
  const auto input_data{ parse_input(input_file) };

  const auto sol1{ solve(input_data) };
  const auto sol2{ solve(input_data, 1) };

  std::cout << sol1 << std::endl;
  std::cout << sol2 << std::endl;
}
