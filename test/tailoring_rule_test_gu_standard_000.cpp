
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
            data::gu::standard_collation_tailoring(),
            "gu::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, gu_standard_000_001)
{
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0ad0),
        std::vector<uint32_t>(1, 0x0a82),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0a82),
        std::vector<uint32_t>(1, 0x0a81),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0a82),
        std::vector<uint32_t>(1, 0x0a81),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0a81),
        std::vector<uint32_t>(1, 0x0a83),
        table(), collation_strength::primary),
        -1);
}
