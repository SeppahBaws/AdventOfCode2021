#include "pch.h"
#include "Day2.h"

#include <fmt/core.h>

#include "Common/FileUtils.h"

namespace Day2
{
	struct Command
	{
		std::string input;
		i32 amount;
	};

	void Run()
	{
		fmt::print("=====[ AdventOfCode Day 2 ]=====\n");

		std::vector<std::string> lines;
		Common::ReadFileSync("src/Puzzles/Day02/input.txt", lines);

		// Parse file.
		const auto commands = lines | std::views::transform([](std::string& line)
		{
			const size_t idx = line.find(' ');
			const std::string input = line.substr(0, idx);
			const i32 amount = std::stoi(line.substr(idx + 1, 1));

			return Command{ input, amount };
		});


		fmt::print("\n-----[ Part 1 ]-----\n");
		i32 horizontal{}, vertical{};

		for (const Command& cmd : commands)
		{
			switch (cmd.input[0])
			{
			case 'f':
				horizontal += cmd.amount;
				break;
			case 'u':
				vertical -= cmd.amount;
				break;
			case 'd':
				vertical += cmd.amount;
				break;
			default:
				fmt::print("Unknown command '{}'", cmd.input);
				break;
			}
		}

		fmt::print("total horizontal: {} - vertical: {} - multiplied: {}\n", horizontal, vertical, horizontal * vertical);



		fmt::print("\n-----[ Part 2 ]-----\n");
		horizontal = 0;
		vertical = 0;
		i32 aim{};

		for (const Command& cmd : commands)
		{
			switch (cmd.input[0])
			{
			case 'd':
				aim += cmd.amount;
				break;
			case 'u':
				aim -= cmd.amount;
				break;

			case 'f':
				horizontal += cmd.amount;
				vertical += aim * cmd.amount;
				break;

			default:
				fmt::print("Unknown command '{}'", cmd.input);
				break;
			}
		}

		fmt::print("total horizontal: {} - vertical: {} - multiplied: {}\n", horizontal, vertical, horizontal * vertical);
	}
}
