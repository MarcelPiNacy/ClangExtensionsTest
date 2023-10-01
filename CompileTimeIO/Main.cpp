#include <array>
#include <cstdio>



constexpr char source_path[] = SOURCE_PATH;
constexpr char build_path[] = BUILD_PATH;



int main()
{
    constexpr char test_text[] =
        "A\n"
        "B\n"
        "C\n"
        "D\n";
    
    constexpr char path[] = SOURCE_PATH "/test_file.txt";
    constexpr auto path_size = sizeof(path) - 1;

    if constexpr (!__builtin_file_exists(path, path_size))
        (void)__builtin_file_write(path, path_size, test_text, sizeof(test_text) - 1);
    
    constexpr auto read_text = [=]() consteval
    {
        if constexpr (__builtin_file_exists(path, path_size))
        {
            constexpr auto size = __builtin_file_size(path, path_size);
            std::array<char, size> data = { };
            __builtin_file_read(path, path_size, data.data(), data.size());
            return data;
        }
        else
        {
            return std::array<char, 0>();
        }
    }();

    fwrite(read_text.data(), 1, read_text.size(), stdout);

    return 0;
}
