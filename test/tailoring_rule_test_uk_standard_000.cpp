
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
            data::uk::standard_collation_tailoring(),
            "uk::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, uk_standard_000_001)
{
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0413),
        std::vector<uint32_t>(1, 0x0491),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0491),
        std::vector<uint32_t>(1, 0x0490),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0491),
        std::vector<uint32_t>(1, 0x0490),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xa647),
        std::vector<uint32_t>(1, 0x0457),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0457),
        std::vector<uint32_t>(1, 0xa676),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0457),
        std::vector<uint32_t>(1, 0xa676),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xa676),
        std::vector<uint32_t>(1, 0x0407),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xa676),
        std::vector<uint32_t>(1, 0x0407),
        table(), collation_strength::secondary),
        0);
}
