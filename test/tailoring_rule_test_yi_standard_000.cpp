
// Warning! This file is autogenerated.
#include <boost/text/collation_tailoring.hpp>
#include <boost/text/collate.hpp>
#include <boost/text/data/all.hpp>

#include <gtest/gtest.h>

using namespace boost::text;

auto const error = [](string const & s) { std::cout << s; };
auto const warning = [](string const & s) {};

tailored_collation_element_table const & table()
{
    static tailored_collation_element_table retval =
        make_tailored_collation_element_table(
            data::yi::standard_collation_tailoring(),
            "yi::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, yi_standard_000_001)
{
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x05d1),
        std::vector<uint32_t>{0x05d1, 0x05bf},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x05d5),
        std::vector<uint32_t>{0x05d5, 0x05bc},
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x05d5),
        std::vector<uint32_t>{0x05d5, 0x05bc},
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x05d5, 0x05bc},
        std::vector<uint32_t>{0x05d5, 0x05d5},
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x05d5, 0x05bc},
        std::vector<uint32_t>{0x05d5, 0x05d5},
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x05d5, 0x05d5},
        std::vector<uint32_t>{0x05d5, 0x05d9},
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x05d5, 0x05d5},
        std::vector<uint32_t>{0x05d5, 0x05d9},
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x05d9),
        std::vector<uint32_t>{0x05d9, 0x05b4},
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x05d9),
        std::vector<uint32_t>{0x05d9, 0x05b4},
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x05d9, 0x05b4},
        std::vector<uint32_t>{0x05d9, 0x05d9},
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x05d9, 0x05b4},
        std::vector<uint32_t>{0x05d9, 0x05d9},
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x05d9, 0x05d9},
        std::vector<uint32_t>{0x05f2, 0x05b7},
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x05d9, 0x05d9},
        std::vector<uint32_t>{0x05f2, 0x05b7},
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x05e4, 0x05bf},
        std::vector<uint32_t>(1, 0x05e3),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x05e4, 0x05bf},
        std::vector<uint32_t>(1, 0x05e3),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x05e9),
        std::vector<uint32_t>{0x05e9, 0x05c2},
        table(), collation_strength::primary),
        -1);
}
