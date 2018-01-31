
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
            data::ee::standard_collation_tailoring(),
            "ee::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, ee_standard_000_001)
{
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x030c),
        std::vector<uint32_t>(1, 0x0302),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x030c),
        std::vector<uint32_t>(1, 0x0302),
        table(), collation_strength::primary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0044),
        std::vector<uint32_t>{0x0064, 0x007a},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0064, 0x007a},
        std::vector<uint32_t>{0x0044, 0x007a},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0064, 0x007a},
        std::vector<uint32_t>{0x0044, 0x007a},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0044, 0x007a},
        std::vector<uint32_t>{0x0044, 0x005a},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0044, 0x007a},
        std::vector<uint32_t>{0x0044, 0x005a},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0044, 0x005a},
        std::vector<uint32_t>(1, 0x0256),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0256),
        std::vector<uint32_t>(1, 0x0189),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0256),
        std::vector<uint32_t>(1, 0x0189),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0045),
        std::vector<uint32_t>(1, 0x025b),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x025b),
        std::vector<uint32_t>(1, 0x0190),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x025b),
        std::vector<uint32_t>(1, 0x0190),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0046),
        std::vector<uint32_t>(1, 0x0192),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0192),
        std::vector<uint32_t>(1, 0x0191),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0192),
        std::vector<uint32_t>(1, 0x0191),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0047),
        std::vector<uint32_t>{0x0067, 0x0062},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0067, 0x0062},
        std::vector<uint32_t>{0x0047, 0x0062},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0067, 0x0062},
        std::vector<uint32_t>{0x0047, 0x0062},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0047, 0x0062},
        std::vector<uint32_t>{0x0047, 0x0042},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0047, 0x0062},
        std::vector<uint32_t>{0x0047, 0x0042},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0047, 0x0042},
        std::vector<uint32_t>(1, 0x0263),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0263),
        std::vector<uint32_t>(1, 0x0194),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0263),
        std::vector<uint32_t>(1, 0x0194),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0048),
        std::vector<uint32_t>(1, 0x0078),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0078),
        std::vector<uint32_t>(1, 0x0058),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0078),
        std::vector<uint32_t>(1, 0x0058),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004b),
        std::vector<uint32_t>{0x006b, 0x0070},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006b, 0x0070},
        std::vector<uint32_t>{0x004b, 0x0070},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006b, 0x0070},
        std::vector<uint32_t>{0x004b, 0x0070},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004b, 0x0070},
        std::vector<uint32_t>{0x004b, 0x0050},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004b, 0x0070},
        std::vector<uint32_t>{0x004b, 0x0050},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004e),
        std::vector<uint32_t>{0x006e, 0x0079},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0079},
        std::vector<uint32_t>{0x004e, 0x0079},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0079},
        std::vector<uint32_t>{0x004e, 0x0079},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0079},
        std::vector<uint32_t>{0x004e, 0x0059},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0079},
        std::vector<uint32_t>{0x004e, 0x0059},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0059},
        std::vector<uint32_t>(1, 0x014b),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x014b),
        std::vector<uint32_t>(1, 0x014a),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x014b),
        std::vector<uint32_t>(1, 0x014a),
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004f),
        std::vector<uint32_t>(1, 0x0254),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0254),
        std::vector<uint32_t>(1, 0x0186),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0254),
        std::vector<uint32_t>(1, 0x0186),
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
        std::vector<uint32_t>(1, 0x0056),
        std::vector<uint32_t>(1, 0x028b),
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x028b),
        std::vector<uint32_t>(1, 0x01b2),
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x028b),
        std::vector<uint32_t>(1, 0x01b2),
        table(), collation_strength::secondary),
        0);
}
