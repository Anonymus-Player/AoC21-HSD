#include <Io.hpp>

void test_day_6(char part, hsd::usize days)
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

    hsd_println("Part{}. The number of fishes is: {}", part, total);
}

int main()
{
    test_day_6('1', 80);
    test_day_6('2', 256);
    return 0;
}