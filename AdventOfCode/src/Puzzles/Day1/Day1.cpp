#include "pch.h"
#include "Day1.h"

#include <fmt/core.h>

#include "Common/FileUtils.h"

namespace Day1
{
	void Run()
	{
		fmt::print("=====[ AdventOfCode Day 1 ]=====\n");


		std::vector<std::string> lines{};
		Common::ReadFileSync("src/Puzzles/Day1/input.txt", lines);

		// Convert strings to ints
		const auto numView = lines | std::ranges::views::transform([](auto&& str) { return std::stoi(str); });
		const std::vector<i32> numbers{ numView.begin(), numView.end() };


		// Calculate the amount of times that the depth increases.
		fmt::print("\n-----[ Part 1 ]-----\n");

		i32 amountOfDepthIncreases{};
		for (size_t i = 1; i < numbers.size(); i++)
		{
			if (numbers[i] > numbers[i - 1])
				amountOfDepthIncreases++;
		}

		fmt::print("The depth increased {} times!\n", amountOfDepthIncreases);

		// Calculate in groups.
		fmt::print("\n-----[ Part 2 ]-----\n");

		amountOfDepthIncreases = 0;
		for (size_t i = 1; i < numbers.size() - 2; i++)
		{
			const i32 currentSum = numbers[i] + numbers[i + 1] + numbers[i + 2];
			const i32 prevSum = numbers[i - 1] + numbers[i] + numbers[i + 1];

			if (currentSum > prevSum)
				amountOfDepthIncreases++;
		}

		fmt::print("The depth increased {} times!\n", amountOfDepthIncreases);
	}
}
