#include <Io.hpp>

void first_part()
{
    hsd::string values[3] = {};
    hsd::isize coords[2][2], coord_mat[1000][1000] = {}, overlaps = 0;
    auto input_file = hsd::io::load_file("Input.txt").unwrap();

    while (input_file.is_eof() == false)
    {
        input_file
        .read_line()
        .unwrap()
        .set_data(
            values[0], values[1], values[2]
        ).unwrap();
        
        coords[0][0] = hsd::cstring::parse<hsd::isize>(values[0].c_str());
        coords[1][0] = hsd::cstring::parse<hsd::isize>(values[2].c_str()); 

        coords[0][1] = hsd::cstring::parse<hsd::isize>(
            values[0].c_str() + values[0].find(',') + 1
        );
        
        coords[1][1] = hsd::cstring::parse<hsd::isize>(
            values[2].c_str() + values[2].find(',') + 1
        );

        if (coords[0][0] == coords[1][0] && coords[0][1] == coords[1][1])
        {
            coord_mat[coords[0][0]][coords[0][1]]++;
        }
        else if (coords[0][0] == coords[1][0] || coords[0][1] == coords[1][1])
        {
            coord_mat[coords[0][0]][coords[0][1]]++;
            coord_mat[coords[1][0]][coords[1][1]]++;

            for (hsd::isize x = coords[0][0] + 1; x < coords[1][0]; x++)
            {
                coord_mat[x][coords[0][1]]++;
            }
            for (hsd::isize x = coords[0][0] - 1; x > coords[1][0]; x--)
            {
                coord_mat[x][coords[0][1]]++;
            }
            for (hsd::isize y = coords[0][1] + 1; y < coords[1][1]; y++)
            {
                coord_mat[coords[0][0]][y]++;
            }
            for (hsd::isize y = coords[0][1] - 1; y > coords[1][1]; y--)
            {
                coord_mat[coords[0][0]][y]++;
            }
        }
    }

    for (hsd::isize x = 0; x < 1000; x++)
    {
        for (hsd::isize y = 0; y < 1000; y++)
        {
            if (coord_mat[y][x] > 1)
            {
                overlaps++;
            }
        }
    }

    hsd_println("Part1. Overlaps: {}", overlaps);
}

void second_part()
{
    hsd::string values[3] = {};
    hsd::isize coords[2][2], coord_mat[1000][1000] = {}, overlaps = 0;
    auto input_file = hsd::io::load_file("Input.txt").unwrap();

    while (input_file.is_eof() == false)
    {
        input_file
        .read_line()
        .unwrap()
        .set_data(
            values[0], values[1], values[2]
        ).unwrap();
        
        coords[0][0] = hsd::cstring::parse<hsd::isize>(values[0].c_str());
        coords[1][0] = hsd::cstring::parse<hsd::isize>(values[2].c_str()); 

        coords[0][1] = hsd::cstring::parse<hsd::isize>(
            values[0].c_str() + values[0].find(',') + 1
        );
        
        coords[1][1] = hsd::cstring::parse<hsd::isize>(
            values[2].c_str() + values[2].find(',') + 1
        );

        if (coords[0][0] == coords[1][0] && coords[0][1] == coords[1][1])
        {
            coord_mat[coords[0][0]][coords[0][1]]++;
        }
        else if (coords[0][0] == coords[1][0] || coords[0][1] == coords[1][1])
        {
            coord_mat[coords[0][0]][coords[0][1]]++;
            coord_mat[coords[1][0]][coords[1][1]]++;

            for (hsd::isize x = coords[0][0] + 1; x < coords[1][0]; x++)
            {
                coord_mat[x][coords[0][1]]++;
            }
            for (hsd::isize x = coords[0][0] - 1; x > coords[1][0]; x--)
            {
                coord_mat[x][coords[0][1]]++;
            }
            for (hsd::isize y = coords[0][1] + 1; y < coords[1][1]; y++)
            {
                coord_mat[coords[0][0]][y]++;
            }
            for (hsd::isize y = coords[0][1] - 1; y > coords[1][1]; y--)
            {
                coord_mat[coords[0][0]][y]++;
            }
        }
        else if (coords[0][0] - coords[1][0] == coords[0][1] - coords[1][1])
        {
            hsd::isize amount = (coords[0][0] - coords[1][0] < 0) ? -1 : 1;

            for (hsd::isize x = 0; x != (coords[0][0] - coords[1][0] + amount); x += amount)
            {
                coord_mat[coords[0][1] - x][coords[0][0] - x]++;
            }
        }
        else if (coords[0][0] - coords[1][0] == coords[1][1] - coords[0][1])
        {
            hsd::isize amount = (coords[0][0] - coords[1][0] < 0) ? -1 : 1;

            for (hsd::isize x = 0; x != (coords[0][0] - coords[1][0] + amount); x += amount)
            {
                coord_mat[coords[0][1] + x][coords[0][0] - x]++;
            }
        }
    }

    for (hsd::isize x = 0; x < 1000; x++)
    {
        for (hsd::isize y = 0; y < 1000; y++)
        {
            if (coord_mat[y][x] > 1)
            {
                overlaps++;
            }
        }
    }

    hsd_println("Part2. Overlaps: {}", overlaps);
}

int main()
{
    first_part();
    second_part();
    return 0;
}