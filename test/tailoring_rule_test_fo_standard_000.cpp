
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
            data::fo::standard_collation_tailoring(),
            "fo::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, fo_standard_000_001)
{
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0044),
        std::vector<uint32_t>(1, 0x0111),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0044),
        std::vector<uint32_t>(1, 0x0111),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0111),
        std::vector<uint32_t>(1, 0x0110),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0111),
        std::vector<uint32_t>(1, 0x0110),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0110),
        std::vector<uint32_t>(1, 0x00f0),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0110),
        std::vector<uint32_t>(1, 0x00f0),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f0),
        std::vector<uint32_t>(1, 0x00d0),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f0),
        std::vector<uint32_t>(1, 0x00d0),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0074, 0x0068},
        std::vector<uint32_t>(1, 0x00fe),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0074, 0x0068},
        std::vector<uint32_t>(1, 0x00fe),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0054, 0x0048},
        std::vector<uint32_t>(1, 0x00de),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0054, 0x0048},
        std::vector<uint32_t>(1, 0x00de),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0059),
        std::vector<uint32_t>{0x0075, 0x0308},
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0059),
        std::vector<uint32_t>{0x0075, 0x0308},
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0075, 0x0308},
        std::vector<uint32_t>{0x0055, 0x0308},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0075, 0x0308},
        std::vector<uint32_t>{0x0055, 0x0308},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0055, 0x0308},
        std::vector<uint32_t>{0x0075, 0x030b},
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0055, 0x0308},
        std::vector<uint32_t>{0x0075, 0x030b},
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0075, 0x030b},
        std::vector<uint32_t>{0x0055, 0x030b},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0075, 0x030b},
        std::vector<uint32_t>{0x0055, 0x030b},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e6),
        std::vector<uint32_t>(1, 0x00c6),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e6),
        std::vector<uint32_t>(1, 0x00c6),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00c6),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00c6),
        std::vector<uint32_t>(1, 0x00e4),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00c6),
        std::vector<uint32_t>(1, 0x00e4),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00e4),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e4),
        std::vector<uint32_t>(1, 0x00c4),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e4),
        std::vector<uint32_t>(1, 0x00c4),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00c4),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00c4),
        std::vector<uint32_t>{0x0065, 0x0328},
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00c4),
        std::vector<uint32_t>{0x0065, 0x0328},
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>{0x0065, 0x0328},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0065, 0x0328},
        std::vector<uint32_t>{0x0045, 0x0328},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0065, 0x0328},
        std::vector<uint32_t>{0x0045, 0x0328},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>{0x0045, 0x0328},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0045, 0x0328},
        std::vector<uint32_t>(1, 0x00f8),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00f8),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f8),
        std::vector<uint32_t>(1, 0x00d8),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f8),
        std::vector<uint32_t>(1, 0x00d8),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00d8),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00d8),
        std::vector<uint32_t>(1, 0x00f6),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00d8),
        std::vector<uint32_t>(1, 0x00f6),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00f6),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f6),
        std::vector<uint32_t>(1, 0x00d6),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f6),
        std::vector<uint32_t>(1, 0x00d6),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00d6),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00d6),
        std::vector<uint32_t>(1, 0x0151),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00d6),
        std::vector<uint32_t>(1, 0x0151),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x0151),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0151),
        std::vector<uint32_t>(1, 0x0150),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0151),
        std::vector<uint32_t>(1, 0x0150),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x0150),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0150),
        std::vector<uint32_t>(1, 0x0153),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0150),
        std::vector<uint32_t>(1, 0x0153),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x0153),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0153),
        std::vector<uint32_t>(1, 0x0152),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0153),
        std::vector<uint32_t>(1, 0x0152),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x0152),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0152),
        std::vector<uint32_t>(1, 0x00e5),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00e5),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e5),
        std::vector<uint32_t>(1, 0x00c5),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e5),
        std::vector<uint32_t>(1, 0x00c5),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00c5),
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00c5),
        std::vector<uint32_t>{0x0061, 0x0061},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00c5),
        std::vector<uint32_t>{0x0061, 0x0061},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>{0x0061, 0x0061},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0061, 0x0061},
        std::vector<uint32_t>{0x0041, 0x0061},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0061, 0x0061},
        std::vector<uint32_t>{0x0041, 0x0061},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>{0x0041, 0x0061},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0041, 0x0061},
        std::vector<uint32_t>{0x0041, 0x0041},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0041, 0x0061},
        std::vector<uint32_t>{0x0041, 0x0041},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>{0x0041, 0x0041},
        table(), collation_strength::quaternary),
        1);
}
