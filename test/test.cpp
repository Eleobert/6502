#include <gtest/gtest.h>

#include <run.hpp>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <errno.h>
#include <ios>
#include <cstring>
#include <numeric>


auto read_file(const std::string& name)
{
    std::ifstream ifs(name, std::ios::binary | std::ios::ate);

    if(not ifs.good())
    {
        std::fprintf(stderr, "%s: %s\n", name.c_str(), std::strerror(errno));
        std::exit(errno);
    }

    auto pos = ifs.tellg();

    auto result = std::vector<uint8_t>(pos);
    auto* ptr = reinterpret_cast<char*>(result.data());

    ifs.seekg(0, std::ios::beg);
    ifs.read(ptr, pos);
    result.resize(0xffff, 0xff);

    return result;
}

auto run_program(status& s, std::vector<uint8_t>& text) 
{
    using namespace std::literals;

    auto ncycles = 0;

    while(true)
    {
        std::tie(s, ncycles) = run(s, text.data());

        if(text[s.regs.pc] == 0xff)
        {
            return;
        }
    }
}


TEST(TEST6502, FASTX10)
{
    status s;
    auto text = read_file("../examples/fastx10");
    run_program(s, text);

    EXPECT_EQ(s.regs.a, 0x32);
}


TEST(TEST6502, CLEARMEM)
{
    status s;
    auto text = read_file("../examples/clearmem");
    run_program(s, text);
    EXPECT_EQ(std::accumulate(&text[15], &text[25], 0), 0);
    EXPECT_EQ(std::accumulate(&text[0], &text[25], 0), 2223);
}


TEST(TEST6502, DOW)
{
    status s;
    auto text = read_file("../examples/dow");
    run_program(s, text);

    EXPECT_EQ(s.regs.a, 0x04);
}


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}