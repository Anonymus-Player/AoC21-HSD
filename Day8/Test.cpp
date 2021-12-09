#include <Io.hpp>
#include <UnorderedMap.hpp>
#include <StringParser.hpp>
#include <Algorithm.hpp>

void first_part()
{
    hsd::usize digits = 0;
    auto input_file = hsd::io::load_file("Input.txt").unwrap();

    while (input_file.is_eof() == false)
    {
        auto strings = hsd::parse_string<
            "{} {} {} {} {} {} {} {} {} {} | {} {} {} {}\n", 14
        >(
            input_file.read_line().unwrap().c_str()
        ).unwrap();

        for (hsd::usize index = 10; index < 14; index++)
        {
            switch (strings[index].to_string().length())
            {
                case 2:
                case 3:
                case 4:
                case 7:
                {
                    digits++;
                    break;
                }

                default:
                    break;
            }
        }
    }

    hsd_println("Part1. Amount of 1, 4, 7, 8 is: {}", digits);
}

void second_part()
{
    hsd::usize digits = 0;
    hsd::vector<hsd::string> nums;
    hsd::unordered_map<char, char> segment_map;
    auto input_file = hsd::io::load_file("Input.txt").unwrap();

    while (input_file.is_eof() == false)
    {
        auto strings = hsd::parse_string<
            "{} {} {} {} {} {} {} {} {} {} | {} {} {} {}\n", 14
        >(
            input_file.read_line().unwrap().c_str()
        ).unwrap();

        for (hsd::usize index = 10; index < 14; index++)
        {
            auto str = strings[index].to_string();

            switch (str.length())
            {
                case 2:
                {
                    if (segment_map.size() == 0)
                    {
                        segment_map[str[0]] = 'c';
                        segment_map[str[1]] = 'f';
                    }
                    break;
                }
                case 3:
                {
                    if (segment_map.size() == 2)
                    {
                        hsd::radix_sort(
                            str, [](char v1, char v2) { return v1 > v2; }
                        );

                        segment_map[str[2]] = 'a';
                    }

                    break;
                }
                case 4:
                {
                    if (nums.size() == 0)
                    {
                        hsd::radix_sort(
                            str, [](char v1, char v2) { return v1 > v2; }
                        );

                        nums.emplace_back(move(str));
                    }
                    else if (nums.size() == 5)
                    {
                        for (auto chr : str)
                        {
                            if (segment_map.at(chr).is_ok() == false && chr != '\0')
                            {
                                segment_map[chr] = 'b'; 
                            }
                        }

                        nums.emplace_back();
                    }

                    break;
                }
                case 5:
                {
                    if (nums.size() < 4 && nums.size() >= 1)
                    {
                        bool is_not_included = true;

                        hsd::radix_sort(
                            str, [](char v1, char v2) { return v1 > v2; }
                        );

                        for (auto& num : nums)
                        {
                            if (str == num)
                            {
                                is_not_included = false;
                                break;
                            }
                        }

                        if (is_not_included == true)
                            nums.emplace_back(move(str));
                    }

                    break;
                }
                case 7:
                {
                    break;
                }
            }

            if (nums.size() == 4)
            {
                char max_index = 0, freq[7] = {};

                for (auto& num : nums)
                {
                    for (auto chr : num)
                    {
                        if (chr != '\0')
                        {
                            freq[chr - 'a']++;

                            if (freq[chr - 'a'] > freq[max_index])
                            {
                                max_index = chr - 'a';
                            }
                        }
                    }
                }

                segment_map[max_index + 'a'] = 'd';
                nums.emplace_back();
            }
            else if (nums.size() == 6)
            {
                char max_val = 0, freq[7] = {};

                for (hsd::usize index = 1; index < 4; index++)
                {
                    for (auto chr : nums[index])
                    {
                        if (chr != '\0')
                        {
                            freq[chr - 'a']++;

                            if (freq[chr - 'a'] > max_val)
                            {
                                max_val = freq[chr - 'a'];
                            }
                        }
                    }
                }

                for (hsd::usize index = 0; index < 7; index++)
                {
                    if (freq[index] == max_val && segment_map.at(freq[index] + 'a').is_ok() == false)
                    {
                        segment_map[freq[index] + 'a'] = 'g';
                    }
                }

                nums.emplace_back();
            }
            else if (nums.size() == 7)
            {
                for (hsd::usize index = 1; index < 4; index++)
                {
                    for (auto chr : nums[index])
                    {
                        if (segment_map.at(chr).is_ok() == false && chr != '\0')
                        {
                            segment_map[chr] = 'e';
                        }
                    }
                }
            }
        }
    }

    input_file.close();
    hsd::usize sum = 0;
    using namespace hsd::string_literals;
    input_file = input_file.load_file("Input.txt").unwrap();

    const hsd::unordered_map<hsd::string, hsd::usize> num_map = {{
        {"abcefg"_s, 0u},
        {"cf"_s, 1u},
        {"acdeg"_s, 2u},
        {"acdfg"_s, 3u},
        {"bcdf"_s, 4u},
        {"abdfg"_s, 5u},
        {"abdefg"_s, 6u},
        {"acf"_s, 7u},
        {"abcdefg"_s, 8u},
        {"abcdfg"_s, 9u}
    }};

    while (input_file.is_eof() == false)
    {
        hsd::usize num = 0;
        auto strings = hsd::parse_string<
            "{} {} {} {} {} {} {} {} {} {} | {} {} {} {}\n", 14
        >(
            input_file.read_line().unwrap().c_str()
        ).unwrap();

        for (hsd::usize index = 10; index < 14; index++)
        {
            auto str = strings[index].to_string();
            hsd::for_each(str, [&](char& val){ val = segment_map[val]; });
            hsd::radix_sort(str, [](char v1, char v2){ return v1 > v2; });
            num *= 10;
            num += num_map[str];
        }

        sum += num;
    }

    //hsd_println("Part1. Amount of 1, 4, 7, 8 is: {}", digits);
}

int main()
{
    first_part();
    //second_part();
    return 0;
}