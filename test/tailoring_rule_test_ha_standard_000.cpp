
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
            data::ha::standard_collation_tailoring(),
            "ha::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, ha_standard_000_001)
{
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0042),
        std::vector<uint32_t>(1, 0x0253),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0253),
        std::vector<uint32_t>(1, 0x0181),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0253),
        std::vector<uint32_t>(1, 0x0181),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0044),
        std::vector<uint32_t>(1, 0x0257),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0257),
        std::vector<uint32_t>(1, 0x018a),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0257),
        std::vector<uint32_t>(1, 0x018a),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004b),
        std::vector<uint32_t>(1, 0x0199),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0199),
        std::vector<uint32_t>(1, 0x0198),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0199),
        std::vector<uint32_t>(1, 0x0198),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0053),
        std::vector<uint32_t>{0x0073, 0x0068},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0073, 0x0068},
        std::vector<uint32_t>{0x0053, 0x0068},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0073, 0x0068},
        std::vector<uint32_t>{0x0053, 0x0068},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0053, 0x0068},
        std::vector<uint32_t>{0x0053, 0x0048},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0053, 0x0068},
        std::vector<uint32_t>{0x0053, 0x0048},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0054),
        std::vector<uint32_t>{0x0074, 0x0073},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0074, 0x0073},
        std::vector<uint32_t>{0x0054, 0x0073},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0074, 0x0073},
        std::vector<uint32_t>{0x0054, 0x0073},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0054, 0x0073},
        std::vector<uint32_t>{0x0054, 0x0053},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0054, 0x0073},
        std::vector<uint32_t>{0x0054, 0x0053},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0059),
        std::vector<uint32_t>(1, 0x01b4),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01b4),
        std::vector<uint32_t>{0x02bc, 0x0079},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01b4),
        std::vector<uint32_t>{0x02bc, 0x0079},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x02bc, 0x0079},
        std::vector<uint32_t>{0x0027, 0x0079},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x02bc, 0x0079},
        std::vector<uint32_t>{0x0027, 0x0079},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0027, 0x0079},
        std::vector<uint32_t>(1, 0x01b3),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0027, 0x0079},
        std::vector<uint32_t>(1, 0x01b3),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01b3),
        std::vector<uint32_t>{0x02bc, 0x0059},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01b3),
        std::vector<uint32_t>{0x02bc, 0x0059},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x02bc, 0x0059},
        std::vector<uint32_t>{0x0027, 0x0059},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x02bc, 0x0059},
        std::vector<uint32_t>{0x0027, 0x0059},
        table(), collation_strength::secondary),
        0);
}
