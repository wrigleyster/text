
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
            data::ln::phonetic_collation_tailoring(),
            "ln::phonetic_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, ln_phonetic_000_001)
{
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
        std::vector<uint32_t>(1, 0x004f),
        std::vector<uint32_t>(1, 0x0254),
        table(), collation_strength::secondary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004f),
        std::vector<uint32_t>(1, 0x0254),
        table(), collation_strength::primary),
        0);
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
        std::vector<uint32_t>(1, 0x0047),
        std::vector<uint32_t>{0x0067, 0x0062},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0067, 0x0062},
        std::vector<uint32_t>{0x0067, 0x0042},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0067, 0x0062},
        std::vector<uint32_t>{0x0067, 0x0042},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0067, 0x0042},
        std::vector<uint32_t>{0x0047, 0x0062},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0067, 0x0042},
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
        std::vector<uint32_t>(1, 0x004b),
        std::vector<uint32_t>{0x006b, 0x0070},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006b, 0x0070},
        std::vector<uint32_t>{0x006b, 0x0050},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006b, 0x0070},
        std::vector<uint32_t>{0x006b, 0x0050},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006b, 0x0050},
        std::vector<uint32_t>{0x004b, 0x0070},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006b, 0x0050},
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
        std::vector<uint32_t>(1, 0x004d),
        std::vector<uint32_t>{0x006d, 0x0062},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0062},
        std::vector<uint32_t>{0x006d, 0x0042},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0062},
        std::vector<uint32_t>{0x006d, 0x0042},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0042},
        std::vector<uint32_t>{0x004d, 0x0062},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0042},
        std::vector<uint32_t>{0x004d, 0x0062},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004d, 0x0062},
        std::vector<uint32_t>{0x004d, 0x0042},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004d, 0x0062},
        std::vector<uint32_t>{0x004d, 0x0042},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004d, 0x0042},
        std::vector<uint32_t>{0x006d, 0x0066},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0066},
        std::vector<uint32_t>{0x006d, 0x0046},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0066},
        std::vector<uint32_t>{0x006d, 0x0046},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0046},
        std::vector<uint32_t>{0x004d, 0x0066},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0046},
        std::vector<uint32_t>{0x004d, 0x0066},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004d, 0x0066},
        std::vector<uint32_t>{0x004d, 0x0046},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004d, 0x0066},
        std::vector<uint32_t>{0x004d, 0x0046},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004d, 0x0046},
        std::vector<uint32_t>{0x006d, 0x0070},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0070},
        std::vector<uint32_t>{0x006d, 0x0050},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0070},
        std::vector<uint32_t>{0x006d, 0x0050},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0050},
        std::vector<uint32_t>{0x004d, 0x0070},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0050},
        std::vector<uint32_t>{0x004d, 0x0070},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004d, 0x0070},
        std::vector<uint32_t>{0x004d, 0x0050},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004d, 0x0070},
        std::vector<uint32_t>{0x004d, 0x0050},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004d, 0x0050},
        std::vector<uint32_t>{0x006d, 0x0076},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0076},
        std::vector<uint32_t>{0x006d, 0x0056},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0076},
        std::vector<uint32_t>{0x006d, 0x0056},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0056},
        std::vector<uint32_t>{0x004d, 0x0076},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006d, 0x0056},
        std::vector<uint32_t>{0x004d, 0x0076},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004d, 0x0076},
        std::vector<uint32_t>{0x004d, 0x0056},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004d, 0x0076},
        std::vector<uint32_t>{0x004d, 0x0056},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004e),
        std::vector<uint32_t>{0x006e, 0x0064},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0064},
        std::vector<uint32_t>{0x006e, 0x0044},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0064},
        std::vector<uint32_t>{0x006e, 0x0044},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0044},
        std::vector<uint32_t>{0x004e, 0x0064},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0044},
        std::vector<uint32_t>{0x004e, 0x0064},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0064},
        std::vector<uint32_t>{0x004e, 0x0044},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0064},
        std::vector<uint32_t>{0x004e, 0x0044},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0044},
        std::vector<uint32_t>{0x006e, 0x0067},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0067},
        std::vector<uint32_t>{0x006e, 0x0047},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0067},
        std::vector<uint32_t>{0x006e, 0x0047},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0047},
        std::vector<uint32_t>{0x004e, 0x0067},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0047},
        std::vector<uint32_t>{0x004e, 0x0067},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0067},
        std::vector<uint32_t>{0x004e, 0x0047},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0067},
        std::vector<uint32_t>{0x004e, 0x0047},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0047},
        std::vector<uint32_t>{0x006e, 0x0067, 0x0062},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0067, 0x0062},
        std::vector<uint32_t>{0x006e, 0x0067, 0x0042},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0067, 0x0062},
        std::vector<uint32_t>{0x006e, 0x0067, 0x0042},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0067, 0x0042},
        std::vector<uint32_t>{0x006e, 0x0047, 0x0062},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0067, 0x0042},
        std::vector<uint32_t>{0x006e, 0x0047, 0x0062},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0047, 0x0062},
        std::vector<uint32_t>{0x006e, 0x0047, 0x0042},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0047, 0x0062},
        std::vector<uint32_t>{0x006e, 0x0047, 0x0042},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0047, 0x0042},
        std::vector<uint32_t>{0x004e, 0x0067, 0x0062},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0047, 0x0042},
        std::vector<uint32_t>{0x004e, 0x0067, 0x0062},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0067, 0x0062},
        std::vector<uint32_t>{0x004e, 0x0067, 0x0042},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0067, 0x0062},
        std::vector<uint32_t>{0x004e, 0x0067, 0x0042},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0067, 0x0042},
        std::vector<uint32_t>{0x004e, 0x0047, 0x0042},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0067, 0x0042},
        std::vector<uint32_t>{0x004e, 0x0047, 0x0042},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0047, 0x0042},
        std::vector<uint32_t>{0x006e, 0x006b},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x006b},
        std::vector<uint32_t>{0x006e, 0x004b},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x006b},
        std::vector<uint32_t>{0x006e, 0x004b},
        table(), collation_strength::secondary),
        0);
}

TEST(tailoring, ln_phonetic_000_002)
{
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x004b},
        std::vector<uint32_t>{0x004e, 0x006b},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x004b},
        std::vector<uint32_t>{0x004e, 0x006b},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x006b},
        std::vector<uint32_t>{0x004e, 0x004b},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x006b},
        std::vector<uint32_t>{0x004e, 0x004b},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x004b},
        std::vector<uint32_t>{0x006e, 0x0073},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0073},
        std::vector<uint32_t>{0x006e, 0x0053},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0073},
        std::vector<uint32_t>{0x006e, 0x0053},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0053},
        std::vector<uint32_t>{0x004e, 0x0073},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0053},
        std::vector<uint32_t>{0x004e, 0x0073},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0073},
        std::vector<uint32_t>{0x004e, 0x0053},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0073},
        std::vector<uint32_t>{0x004e, 0x0053},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0053},
        std::vector<uint32_t>{0x006e, 0x0074},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0074},
        std::vector<uint32_t>{0x006e, 0x0054},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0074},
        std::vector<uint32_t>{0x006e, 0x0054},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0054},
        std::vector<uint32_t>{0x004e, 0x0074},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0054},
        std::vector<uint32_t>{0x004e, 0x0074},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0074},
        std::vector<uint32_t>{0x004e, 0x0054},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0074},
        std::vector<uint32_t>{0x004e, 0x0054},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0054},
        std::vector<uint32_t>{0x006e, 0x0079},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0079},
        std::vector<uint32_t>{0x006e, 0x0059},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0079},
        std::vector<uint32_t>{0x006e, 0x0059},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0059},
        std::vector<uint32_t>{0x004e, 0x0079},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0059},
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
        std::vector<uint32_t>{0x006e, 0x007a},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x007a},
        std::vector<uint32_t>{0x006e, 0x005a},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x007a},
        std::vector<uint32_t>{0x006e, 0x005a},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x005a},
        std::vector<uint32_t>{0x004e, 0x007a},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x005a},
        std::vector<uint32_t>{0x004e, 0x007a},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x007a},
        std::vector<uint32_t>{0x004e, 0x005a},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x007a},
        std::vector<uint32_t>{0x004e, 0x005a},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0053),
        std::vector<uint32_t>{0x0073, 0x0068},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0073, 0x0068},
        std::vector<uint32_t>{0x0073, 0x0048},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0073, 0x0068},
        std::vector<uint32_t>{0x0073, 0x0048},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0073, 0x0048},
        std::vector<uint32_t>{0x0053, 0x0068},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0073, 0x0048},
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
        std::vector<uint32_t>{0x0074, 0x0053},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0074, 0x0073},
        std::vector<uint32_t>{0x0074, 0x0053},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0074, 0x0053},
        std::vector<uint32_t>{0x0054, 0x0073},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0074, 0x0053},
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
}
