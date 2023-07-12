// Copyright (C) 2023 Matheus Fernandes Bigolin <mfrdrbigolin@disroot.org>
// SPDX-License-Identifier: MIT

// Day Four, The Ideal Stocking Stuffer.

#include <openssl/evp.h>

#include <iostream>
#include <limits>
#include <string>

using MD5Digest = unsigned char[EVP_MAX_MD_SIZE];

static unsigned char *MD5(EVP_MD_CTX *ctx, const std::string message) {
  static MD5Digest digest{};

  EVP_DigestInit_ex2(ctx, EVP_md5(), nullptr);
  EVP_DigestUpdate(ctx, message.c_str(), message.size());
  EVP_DigestFinal_ex(ctx, digest, nullptr);

  return digest;
}

static bool is_zero_prefixed(const MD5Digest digest, const int num_zeros) {
  auto is_valid{ true };

  for (auto i{ 0 }; i < num_zeros / 2; ++i) {
    is_valid &= digest[i] == 0;
  }

  if (num_zeros % 2 == 1) {
    is_valid &= (digest[num_zeros / 2] & 0xF0) == 0;
  }

  return is_valid;
}

static int solve(const std::string secret_key, const int num_zeros = 1) {
  auto ctx{ EVP_MD_CTX_new() };

  for (auto i{ 1 }; i < std::numeric_limits<int>::max(); ++i) {
    const auto message = secret_key + std::to_string(i);
    const auto digest{ MD5(ctx, message) };

    if (is_zero_prefixed(digest, num_zeros)) {
      return i;
    }
  }

  EVP_MD_CTX_free(ctx);
  return -1;
}

void day04(const std::string input_file) {
  const auto sol1{ solve(input_file, 5) };
  const auto sol2{ solve(input_file, 6) };

  std::cout << sol1 << std::endl;
  std::cout << sol2 << std::endl;
}