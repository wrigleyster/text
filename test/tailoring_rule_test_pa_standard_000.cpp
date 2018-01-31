
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
            data::pa::standard_collation_tailoring(),
            "pa::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, pa_standard_000_001)
{
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0a71),
        std::vector<uint32_t>(1, 0x0a70),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0a71),
        std::vector<uint32_t>(1, 0x0a70),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0a70),
        std::vector<uint32_t>(1, 0x0a02),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0a70),
        std::vector<uint32_t>(1, 0x0a02),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0a02),
        std::vector<uint32_t>(1, 0x0a01),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0a02),
        std::vector<uint32_t>(1, 0x0a01),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0a01),
        std::vector<uint32_t>(1, 0x0a3c),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0a01),
        std::vector<uint32_t>(1, 0x0a3c),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0a5c),
        std::vector<uint32_t>(1, 0x0a4d),
        table(), collation_strength::primary),
        -1);
}
