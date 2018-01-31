
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
            data::vi::standard_collation_tailoring(),
            "vi::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, vi_standard_000_001)
{
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0300),
        std::vector<uint32_t>(1, 0x0309),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0300),
        std::vector<uint32_t>(1, 0x0309),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0309),
        std::vector<uint32_t>(1, 0x0303),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0309),
        std::vector<uint32_t>(1, 0x0303),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0303),
        std::vector<uint32_t>(1, 0x0301),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0303),
        std::vector<uint32_t>(1, 0x0301),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0301),
        std::vector<uint32_t>(1, 0x0323),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0301),
        std::vector<uint32_t>(1, 0x0323),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0061),
        std::vector<uint32_t>(1, 0x0103),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0103),
        std::vector<uint32_t>(1, 0x0102),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0103),
        std::vector<uint32_t>(1, 0x0102),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0102),
        std::vector<uint32_t>(1, 0x00e2),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e2),
        std::vector<uint32_t>(1, 0x00c2),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e2),
        std::vector<uint32_t>(1, 0x00c2),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0064),
        std::vector<uint32_t>(1, 0x0111),
        table(), collation_strength::primary),
        -1);
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
        std::vector<uint32_t>(1, 0x0065),
        std::vector<uint32_t>(1, 0x00ea),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00ea),
        std::vector<uint32_t>(1, 0x00ca),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00ea),
        std::vector<uint32_t>(1, 0x00ca),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x006f),
        std::vector<uint32_t>(1, 0x00f4),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f4),
        std::vector<uint32_t>(1, 0x00d4),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f4),
        std::vector<uint32_t>(1, 0x00d4),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00d4),
        std::vector<uint32_t>(1, 0x01a1),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01a1),
        std::vector<uint32_t>(1, 0x01a0),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01a1),
        std::vector<uint32_t>(1, 0x01a0),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0075),
        std::vector<uint32_t>(1, 0x01b0),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01b0),
        std::vector<uint32_t>(1, 0x01af),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01b0),
        std::vector<uint32_t>(1, 0x01af),
        table(), collation_strength::secondary),
        0);
}
