#include <Io.hpp>

#define CONSTEXPR_SOLUTION

#if !defined(CONSTEXPR_SOLUTION)
auto test_day_6(hsd::usize days)
{
    hsd::usize fishes[10] = {}, total = 0;
    auto input_file = hsd::io::load_file("Input.txt").unwrap();
    auto& input_stream = input_file.read_line().unwrap();
    fishes[hsd::cstring::parse<hsd::uchar>(input_stream.c_str())]++;
    
    for (auto* str = input_stream.c_str(); *str != '\0'; ++str)
    {
        if (*str == ',')
        {
            fishes[hsd::cstring::parse<hsd::uchar>(str + 1)]++;
        }
    }

    for (hsd::usize day = 0; day < days; day++)
    {
        hsd::usize next = fishes[0];

        for (hsd::usize index = 0; index < 9; index++)
        {
            fishes[index] = fishes[index + 1];
        }

        fishes[6] += next;
        fishes[8] = next;
    }

    for (hsd::usize index = 0; index < 9; index++)
    {
        total += fishes[index];
    }

    return total;
}
#else
template <hsd::usize Days, hsd::basic_string_literal input>
consteval auto test_day_6()
{
    hsd::usize fishes[10] = {}, total = 0;
    fishes[hsd::cstring::parse<hsd::uchar>(input.data)]++;
    
    for (auto* str = input.data; *str != '\0'; ++str)
    {
        if (*str == ',')
        {
            fishes[hsd::cstring::parse<hsd::uchar>(str + 1)]++;
        }
    }

    for (hsd::usize day = 0; day < Days; day++)
    {
        hsd::usize next = fishes[0];

        for (hsd::usize index = 0; index < 9; index++)
        {
            fishes[index] = fishes[index + 1];
        }

        fishes[6] += next;
        fishes[8] = next;
    }

    for (hsd::usize index = 0; index < 9; index++)
    {
        total += fishes[index];
    }

    return total;
}
#endif

int main()
{
    #if !defined(CONSTEXPR_SOLUTION)
    hsd_println("Part1. The number of fishes is: {}", test_day_6(80));
    hsd_println("Part2. The number of fishes is: {}", test_day_6(256));
    #else
    constexpr hsd::basic_string_literal input = 
        "1,1,3,5,1,1,1,4,1,5,1,1,1,1,1,1,1,3,1,1,1,1,2,5,1,1,1,1,1,2,1,4,1"
        ",4,1,1,1,1,1,3,1,1,5,1,1,1,4,1,1,1,4,1,1,3,5,1,1,1,1,4,1,5,4,1,1,"
        "2,3,2,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,5"
        ",1,1,1,3,4,1,1,1,1,3,1,1,1,1,1,4,1,1,3,1,1,3,1,1,1,1,1,3,1,5,2,3,"
        "1,2,3,1,1,2,1,2,4,5,1,5,1,4,1,1,1,1,2,1,5,1,1,1,1,1,5,1,1,3,1,1,1"
        ",1,1,1,4,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,3,2,1,1,1,1,2,2,1,2,1,1,1,"
        "5,5,1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,4,2,1,4,1,1,1,1,1,1,1,2,1,2,1"
        ",1,1,1,1,1,1,1,1,1,1,1,1,2,2,1,5,1,1,1,1,1,1,1,1,3,1,1,3,3,1,1,1,"
        "3,5,1,1,4,1,1,1,1,1,4,1,1,3,1,1,1,1,1,1,1,1,2,1,5,1,1,1,1,1,1,1,1"
        ",1,1,4,1,1,1,1";

    hsd_println("Part1. The number of fishes is: {}", test_day_6<80, input>());
    hsd_println("Part2. The number of fishes is: {}", test_day_6<256, input>());
    #endif
    return 0;
}