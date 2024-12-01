#include <aoc/common/puzzle/puzzle_file_reader.h>
#include <aoc/common/puzzle/puzzle_reader_factory.h>

namespace aoc {

std::unique_ptr<aoc::IPuzzleReader> PuzzleReaderFactory(
    aoc::CliArguments const& arguments) {
  std::unique_ptr<aoc::IPuzzleReader> reader;
  std::visit(
      [&reader](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, aoc::CliArguments::InputFilePath>)
          reader = std::make_unique<aoc::PuzzleFileReader>(arg);
        else if constexpr (std::is_same_v<T,
                                          aoc::CliArguments::InputNetworkToken>)
          throw std::invalid_argument(
              "TODO: implement network cookie token access over HTTP GET");
        else
          static_assert(false, "non-exhaustive visitor!");
      },
      arguments.input);
  return reader;
}

}  // namespace aoc::aoc2022