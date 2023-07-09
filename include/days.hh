// Copyright (C) 2023 Matheus Fernandes Bigolin <mfrdrbigolin@disroot.org>
// SPDX-License-Identifier: MIT

#ifndef DAYS_HH
#define DAYS_HH

#include <functional>
#include <map>
#include <string>

// This is the most sane away I have found to do this.  Basically, if a day was
// built by Make, a macro with the day number is defined.  This way, everything
// is automatic and I don’t need to modify this file ever again.
//
// However, it would be dope if C++ had a for-generate statement like VHDL.

#ifdef DAY01
void day01(std::string);
#endif
#ifdef DAY02
void day02(std::string);
#endif
#ifdef DAY03
void day03(std::string);
#endif
#ifdef DAY04
void day04(std::string);
#endif
#ifdef DAY05
void day05(std::string);
#endif
#ifdef DAY06
void day06(std::string);
#endif
#ifdef DAY07
void day07(std::string);
#endif
#ifdef DAY08
void day08(std::string);
#endif
#ifdef DAY09
void day09(std::string);
#endif
#ifdef DAY10
void day10(std::string);
#endif
#ifdef DAY11
void day11(std::string);
#endif
#ifdef DAY12
void day12(std::string);
#endif
#ifdef DAY13
void day13(std::string);
#endif
#ifdef DAY14
void day14(std::string);
#endif
#ifdef DAY15
void day15(std::string);
#endif
#ifdef DAY16
void day16(std::string);
#endif
#ifdef DAY17
void day17(std::string);
#endif
#ifdef DAY18
void day18(std::string);
#endif
#ifdef DAY19
void day19(std::string);
#endif
#ifdef DAY20
void day20(std::string);
#endif
#ifdef DAY21
void day21(std::string);
#endif
#ifdef DAY22
void day22(std::string);
#endif
#ifdef DAY23
void day23(std::string);
#endif
#ifdef DAY24
void day24(std::string);
#endif
#ifdef DAY25
void day25(std::string);
#endif

using Day = std::function<void(std::string)>;

const std::map<std::string, Day> DAYS{
#ifdef DAY01
  { "01", day01 },
#endif
#ifdef DAY02
  { "02", day02 },
#endif
#ifdef DAY03
  { "03", day03 },
#endif
#ifdef DAY04
  { "04", day04 },
#endif
#ifdef DAY05
  { "05", day05 },
#endif
#ifdef DAY06
  { "06", day06 },
#endif
#ifdef DAY07
  { "07", day07 },
#endif
#ifdef DAY08
  { "08", day08 },
#endif
#ifdef DAY09
  { "09", day09 },
#endif
#ifdef DAY10
  { "10", day10 },
#endif
#ifdef DAY11
  { "11", day11 },
#endif
#ifdef DAY12
  { "12", day12 },
#endif
#ifdef DAY13
  { "13", day13 },
#endif
#ifdef DAY14
  { "14", day14 },
#endif
#ifdef DAY15
  { "15", day15 },
#endif
#ifdef DAY16
  { "16", day16 },
#endif
#ifdef DAY17
  { "17", day17 },
#endif
#ifdef DAY18
  { "18", day18 },
#endif
#ifdef DAY19
  { "19", day19 },
#endif
#ifdef DAY20
  { "20", day20 },
#endif
#ifdef DAY21
  { "21", day21 },
#endif
#ifdef DAY22
  { "22", day22 },
#endif
#ifdef DAY23
  { "23", day23 },
#endif
#ifdef DAY24
  { "24", day24 },
#endif
#ifdef DAY25
  { "25", day25 }
#endif
};

#endif /* !DAYS_HH  */
