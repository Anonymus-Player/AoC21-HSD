#include <Io.hpp>

void first_part()
{
    hsd::isize fuel[2000] = {}, min_pos = 0, index = 0;
    auto input_file = hsd::io::load_file("Input.txt").unwrap();
    auto& input_stream = input_file.read_line().unwrap();
    index = hsd::cstring::parse<hsd::isize>(input_stream.c_str());

    for (hsd::isize i = 0; i < 2000; ++i)
    {
        fuel[i] += hsd::math::abs(i - index);
    }

    for (auto* str = input_stream.c_str(); *str != '\0'; ++str)
    {
        if (*str == ',')
        {
            index = hsd::cstring::parse<hsd::isize>(str + 1);
            
            for (hsd::isize i = 0; i < 2000; ++i)
            {
                fuel[i] += hsd::math::abs(i - index);
            }
        }
    }

    for (hsd::usize i = 0; i < 2000; ++i)
    {
        if (fuel[i] < fuel[min_pos])
        {
            min_pos = i;
        }
    }

    hsd_println("Part1. The fuel consumed is: {}", fuel[min_pos]);
}

void second_part()
{
    hsd::isize fuel[2000] = {}, min_pos = 0, index = 0;
    auto input_file = hsd::io::load_file("Input.txt").unwrap();
    auto& input_stream = input_file.read_line().unwrap();
    index = hsd::cstring::parse<hsd::isize>(input_stream.c_str());

    for (hsd::isize i = 0; i < 2000; ++i)
    {
        fuel[i] += (hsd::math::abs(i - index) * (hsd::math::abs(i - index) + 1)) / 2;
    }

    for (auto* str = input_stream.c_str(); *str != '\0'; ++str)
    {
        if (*str == ',')
        {
            index = hsd::cstring::parse<hsd::isize>(str + 1);
            
            for (hsd::isize i = 0; i < 2000; ++i)
            {
                fuel[i] += (hsd::math::abs(i - index) * (hsd::math::abs(i - index) + 1)) / 2;
            }
        }
    }

    for (hsd::usize i = 0; i < 2000; ++i)
    {
        if (fuel[i] < fuel[min_pos])
        {
            min_pos = i;
        }
    }

    hsd_println("Part2. The fuel consumed is: {}", fuel[min_pos]);
}

int main()
{
    first_part();
    second_part();
    return 0;
}