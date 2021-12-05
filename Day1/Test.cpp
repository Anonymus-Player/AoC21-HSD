#include <Io.hpp>

int main()
{
    // Part 1
    {
        hsd::usize increases = 0, base_value = 0, current_value = 0;
        auto input_file = hsd::io::load_file("Input.txt").unwrap();

        input_file.read_line().unwrap().set_data(base_value).unwrap();

        while (input_file.is_eof() == false)
        {
            input_file.read_line().unwrap().set_data(current_value).unwrap();

            if (current_value > base_value)
            {
                increases++;
            }

            base_value = current_value;    
        }

        hsd_println("Part1. The number of increases is: {}", increases);
    }

    // Part 2
    {
        hsd::usize increases = 0, base_value[3] = {}, sum_value[2], current_value = 0;
        auto input_file = hsd::io::load_file("Input.txt").unwrap();

        input_file
        .read_line()
        .unwrap()
        .set_data(base_value[0])
        .unwrap();
        
        input_file
        .read_line()
        .unwrap()
        .set_data(base_value[1])
        .unwrap();
        
        input_file
        .read_line()
        .unwrap()
        .set_data(base_value[2])
        .unwrap();
        
        sum_value[0] = base_value[0] + base_value[1] + base_value[2];

        while (input_file.is_eof() == false)
        {
            input_file
            .read_line()
            .unwrap()
            .set_data(current_value)
            .unwrap();
            
            sum_value[1] = base_value[1] + base_value[2] + current_value;

            if (sum_value[0] < sum_value[1])
            {
                increases++;
            }

            sum_value[0] = sum_value[1];
            base_value[0] = base_value[1];
            base_value[1] = base_value[2];
            base_value[2] = current_value;
        }

        hsd_println("Part2. The number of increases is: {}", increases);
    }

    return 0;
}
    