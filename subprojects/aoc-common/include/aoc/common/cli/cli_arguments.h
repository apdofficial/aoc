#pragma once

#include <filesystem>
#include <string>
#include <variant>

namespace aoc {

struct CliArguments {
  using InputFilePath = std::filesystem::path;
  using InputNetworkToken = std::string;
  unsigned day{};
  std::variant<InputFilePath, InputNetworkToken> input{};
};

}  // namespace aoc