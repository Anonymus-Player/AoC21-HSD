#include <Io.hpp>

int main()
{
    // Part 1
    {
        hsd::string input = {}; hsd::usize bits[2][12] = {};
        hsd::usize gamma_rate = 0, epsilon_rate = 0, multiplier = 1;
        auto input_file = hsd::io::load_file("Input.txt").unwrap();

        while (input_file.is_eof() == false)
        {
            input_file.read_line().unwrap().set_data(input).unwrap();

            for (hsd::usize index = 0; auto bit : input)
            {
                bits[bit - '0'][index]++;
                index++;
            }
        }

        for (hsd::usize index = 12; index > 0; index--)
        {
            if (bits[0][index - 1] > bits[1][index - 1])
            {
                epsilon_rate += multiplier;
            }
            else
            {
                gamma_rate += multiplier;
            }

            multiplier *= 2;
        }
        
        hsd_println("Part1. The power compsumtion is: {}", gamma_rate * epsilon_rate);
    }

    // Part 2
    {
        hsd::string input = {}; char bits[2][12] = {};
        hsd::usize oxi_rate = 0, co2_rate = 0, multiplier = 2048;
        
        for (hsd::usize index = 0; index < 12; index++)
        {
            hsd::string input_copy[2] = {};
            hsd::usize zero_bits[2] = {}, one_bits[2] = {}, freq[2] = {};
            auto input_file = hsd::io::load_file("Input.txt").unwrap();

            while (input_file.is_eof() == false)
            {
                input_file.read_line().unwrap().set_data(input).unwrap();

                if (hsd::cstring::compare(input.c_str(), bits[0], index) == 0)
                {
                    freq[0]++;
                    input_copy[0] = input;

                    if (input[index] == '0')
                    {
                        zero_bits[0]++;
                    }
                    else
                    {
                        one_bits[0]++;
                    }
                }
                if (hsd::cstring::compare(input.c_str(), bits[1], index) == 0)
                {
                    freq[1]++;
                    input_copy[1] = input;

                    if (input[index] == '0')
                    {
                        zero_bits[1]++;
                    }
                    else
                    {
                        one_bits[1]++;
                    }
                }
            }

            if (freq[0] != 1)
            {
                bits[0][index] = one_bits[0] >= zero_bits[0] ? '1' : '0';
            }
            else
            {
                for (hsd::usize copy_idx = 0; copy_idx < 12; copy_idx++)
                {
                    bits[0][copy_idx] = input_copy[0][copy_idx];
                }
            }

            if (freq[1] != 1)
            {
                bits[1][index] = one_bits[1] >= zero_bits[1] ? '0' : '1';
            }
            else
            {
                for (hsd::usize copy_idx = 0; copy_idx < 12; copy_idx++)
                {
                    bits[1][copy_idx] = input_copy[1][copy_idx];
                }
            }
        }

        for (hsd::usize index = 0; index < 12; index++)
        {
            oxi_rate += (bits[0][index] - '0') * multiplier;
            co2_rate += (bits[1][index] - '0') * multiplier;
            multiplier /= 2;
        }
        
        hsd_println("Part2. The life support rating is: {}", oxi_rate * co2_rate);
    }

    return 0;
}