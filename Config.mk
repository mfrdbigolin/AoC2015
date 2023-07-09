# Configuration for the Makefile
# Copyright (C) 2023 Matheus Fernandes Bigolin <mfrdrbigolin@disroot.org>
# SPDX-License-Identifier: MIT

MAKENAME = "Advent"

MAIN = advent
DAYS = $(patsubst $(SRC_DIR)/%.cc,%,$(wildcard $(SRC_DIR)/day*.cc))
MODULES = utils $(DAYS)

SRC_DIR = src
INCL_DIR = include
BUILD_DIR = build
BIN_DIR = bin

CC = g++
PPFLAGS = $(patsubst day%,-D DAY%,$(DAYS))
CCFLAGS = -Wall -pedantic -std=c++17 -O2
LDFLAGS = -lm
