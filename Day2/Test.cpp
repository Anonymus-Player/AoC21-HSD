#include <Io.hpp>

int main()
{
    using namespace hsd::string_literals;
    const auto down = "down"_s;
    const auto up = "up"_s;
    const auto forward = "forward"_s;

    // Part 1
    {
        hsd::string key_value = {};
        hsd::usize depth = 0, forward_pos = 0, current_value = 0;
        auto input_file = hsd::io::load_file("Input.txt").unwrap();

        while (input_file.is_eof() == false)
        {
            input_file
            .read_line()
            .unwrap()
            .set_data(key_value, current_value)
            .unwrap();

            if (key_value == down)
            {
                depth += current_value;
            }
            else if (key_value == up)
            {
                depth -= current_value;
            }
            else if (key_value == forward)
            {
                forward_pos += current_value;
            }
        }

        hsd_println("Part1. The final position is: {}", forward_pos * depth);
    }

    // Part 2
    {
        hsd::string key_value = {};
        hsd::usize depth = 0, h_pos = 0, aim = 0, current_value = 0;
        auto input_file = hsd::io::load_file("Input.txt").unwrap();

        while (input_file.is_eof() == false)
        {
            input_file
            .read_line()
            .unwrap()
            .set_data(key_value, current_value)
            .unwrap();

            if (key_value == down)
            {
                aim += current_value;
            }
            else if (key_value == up)
            {
                aim -= current_value;
            }
            else if (key_value == forward)
            {
                h_pos += current_value;
                depth += aim * current_value;
            }
        }

        hsd_println("Part2. The final position is: {}", h_pos * depth);
    }
    return 0;
}