// Copyright (C) 2023 Matheus Fernandes Bigolin <mfrdrbigolin@disroot.org>
// SPDX-License-Identifier: MIT

#include "days.hh"
#include "utils.hh"

#include <charconv>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>

int main(int argc, char *argv[]) {
  const auto program_path = std::filesystem::canonical(argv[0]);
  // Go from /bin/advent to /.
  const auto root_path = program_path.parent_path().parent_path();

  std::filesystem::current_path(root_path);

  if (argc <= 1 || argc > 3) {
    std::cerr << "usage: advent <day_id> [<input_extension>]" << std::endl;

    return EXIT_FAILURE;
  }

  const std::string_view day_string{ argv[1] };
  auto day_number{ -1 };
  const auto [ptr, ec] =
      std::from_chars(day_string.begin(), day_string.end(), day_number);

  if (ec == std::errc::result_out_of_range) {
    std::cerr << "advent: The day typed is too large." << std::endl;

    return EXIT_FAILURE;
  }
  if (ec == std::errc::invalid_argument || ptr != day_string.end() ||
      day_number < 0) {
    std::cerr << "advent: Please type a whole number as the day." << std::endl;

    return EXIT_FAILURE;
  }

  const auto day = day_number < 10 ? "0" + std::to_string(day_number)
                                   : std::to_string(day_number);

  if (DAYS.find(day) == DAYS.end()) {
    std::cerr << "advent: Day " << day_number
              << " was not compiled or currently does not exist." << std::endl;

    return EXIT_FAILURE;
  }

  const std::string input_extension{ argc > 2 ? argv[2] : "" };
  const auto input_filename =
      "./inputs/day" + day + (argc > 2 ? "." + input_extension : "") + ".txt";

  std::string input_data{ "" };
  try {
    input_data = read_file(input_filename);
  } catch (const std::runtime_error &e) {
    std::cerr << "advent: " << e.what() << '.' << std::endl;

    return EXIT_FAILURE;
  }

  DAYS.at(day)(input_data);

  return EXIT_SUCCESS;
}
