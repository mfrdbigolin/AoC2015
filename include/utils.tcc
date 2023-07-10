// Copyright (C) 2023 Matheus Fernandes Bigolin <mfrdrbigolin@disroot.org>
// SPDX-License-Identifier: MIT

#ifndef UTILS_TCC
#define UTILS_TCC

#include <type_traits>

// Szudzik’s pairing function: this function assigns to each coordinate in the
// cartesian plane a unique natural number.
template <typename T,
          class = typename std::enable_if<std::is_integral<T>::value>::type>
constexpr T pairing(const T x, const T y) noexcept {
  // Map each integer to an unique natural number.
  const auto px = x >= 0 ? 2 * x : (-2 * x - 1);
  const auto py = y >= 0 ? 2 * y : (-2 * y - 1);

  const auto paired = px < py ? py * py + px : px * (px + 1) + py;

  return paired;
}

#endif /* !UTILS_TCC  */