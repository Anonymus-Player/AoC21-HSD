#include <Io.hpp>

struct bingo_table_entry
{
    hsd::usize value = 0;
    bool is_marked = false;
};

void second_part()
{
    hsd::usize last_score, table_size = 0;
    hsd::usize numbers_size = 1, numbers[200] = {};
    bingo_table_entry table[100][5][5] = {};
    bool was_bingo[100] = {};

    auto input_file = hsd::io::load_file("Input.txt").unwrap();
    auto& line_stream = input_file.read_line().unwrap();
    numbers[0] = hsd::cstring::parse<hsd::usize>(line_stream.c_str());
    
    for (auto* str = line_stream.c_str(); *str != '\0'; str++)
    {
        if (*str == ',')
        {
            numbers[numbers_size++] = hsd::cstring::parse<hsd::usize>(str + 1);
        }
    }
    while (input_file.is_eof() == false)
    {
        input_file.read_line().unwrap();
        
        if (line_stream.c_str()[0] != '\n')
        {
            for (hsd::usize index = 0; index < 5; index++)
            {
                line_stream.set_data(
                    table[table_size][index][0].value,
                    table[table_size][index][1].value,
                    table[table_size][index][2].value,
                    table[table_size][index][3].value,
                    table[table_size][index][4].value
                ).unwrap();
                
                input_file.read_line().unwrap();
            }
            
            table_size++;
        }
    }
    
    for (hsd::usize num_index = 0; num_index < numbers_size; num_index++)
    {
        for (hsd::usize table_index = 0; table_index < table_size; table_index++)
        {
            if (was_bingo[table_index] == false)
            {
                for (hsd::usize row_index = 0; row_index < 5; row_index++)
                {
                    bool is_row_bingo = true, is_column_bingo = true;

                    for (hsd::usize column_index = 0; column_index < 5; column_index++)
                    {
                        if (table[table_index][row_index][column_index].value == numbers[num_index])
                        {
                            table[table_index][row_index][column_index].is_marked = true;
                        }
                        if (table[table_index][row_index][column_index].is_marked == false)
                        {
                            is_row_bingo = false;
                        }
                        if (table[table_index][column_index][row_index].is_marked == false)
                        {
                            is_column_bingo = false;
                        }
                    }
                    if (is_row_bingo == true || is_column_bingo == true)
                    {
                        was_bingo[table_index] = true;
                    }
                }
                if (was_bingo[table_index] == true)
                {
                    hsd::usize unmarked_sum = 0;

                    for (hsd::usize row_index2 = 0; row_index2 < 5; row_index2++)
                    {
                        for (hsd::usize column_index2 = 0; column_index2 < 5; column_index2++)
                        {
                            if (table[table_index][row_index2][column_index2].is_marked == false)
                            {
                                unmarked_sum += table[table_index][row_index2][column_index2].value;
                            }
                        }
                    }

                    last_score = numbers[num_index] * unmarked_sum;
                }
            }
        }
    }

    hsd_println("Part2. Final score is {}", last_score);
}

void first_part()
{
    hsd::usize unmarked_sum = 0, table_size = 0, numbers_size = 1, numbers[200] = {};
    bingo_table_entry table[100][5][5] = {};
    auto input_file = hsd::io::load_file("Input.txt").unwrap();
    auto& line_stream = input_file.read_line().unwrap();
    numbers[0] = hsd::cstring::parse<hsd::usize>(line_stream.c_str());

    for (auto* str = line_stream.c_str(); *str != '\0'; str++)
    {
        if (*str == ',')
        {
            numbers[numbers_size++] = hsd::cstring::parse<hsd::usize>(str + 1);
        }
    }

    while (input_file.is_eof() == false)
    {
        input_file.read_line().unwrap();

        if (line_stream.c_str()[0] != '\n')
        {
            for (hsd::usize index = 0; index < 5; index++)
            {
                line_stream.set_data(
                    table[table_size][index][0].value,
                    table[table_size][index][1].value,
                    table[table_size][index][2].value,
                    table[table_size][index][3].value,
                    table[table_size][index][4].value
                ).unwrap();

                input_file.read_line().unwrap();
            }

            table_size++;
        }
    }

    for (hsd::usize num_index = 0; num_index < numbers_size; num_index++)
    {
        for (hsd::usize table_index = 0; table_index < table_size; table_index++)
        {
            for (hsd::usize row_index = 0; row_index < 5; row_index++)
            {
                bool is_row_bingo = true, is_column_bingo = true;
                
                for (hsd::usize column_index = 0; column_index < 5; column_index++)
                {
                    if (table[table_index][row_index][column_index].value == numbers[num_index])
                    {
                        table[table_index][row_index][column_index].is_marked = true;
                    }
                    if (table[table_index][row_index][column_index].is_marked == false)
                    {
                        is_row_bingo = false;
                    }
                    if (table[table_index][column_index][row_index].is_marked == false)
                    {
                        is_column_bingo = false;
                    }
                }
                if (is_row_bingo == true || is_column_bingo == true)
                {
                    for (hsd::usize row_index2 = 0; row_index2 < 5; row_index2++)
                    {
                        for (hsd::usize column_index2 = 0; column_index2 < 5; column_index2++)
                        {
                            if (table[table_index][row_index2][column_index2].is_marked == false)
                            {
                                unmarked_sum += table[table_index][row_index2][column_index2].value;
                            }
                        }
                    }

                    hsd_println("Part1. Final score is {}", unmarked_sum * numbers[num_index]);
                    return;
                }
            }
        }
    }
}

int main()
{
    first_part();
    second_part();
    return 0;
}