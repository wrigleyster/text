
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
            data::uz::standard_collation_tailoring(),
            "uz::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, uz_standard_000_001)
{
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006f, 0x02bb},
        std::vector<uint32_t>{0x006f, 0x2018},
        table(), collation_strength::identical),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006f, 0x02bb},
        std::vector<uint32_t>{0x006f, 0x2018},
        table(), collation_strength::quaternary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x006f, 0x2018},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006f, 0x2018},
        std::vector<uint32_t>{0x006f, 0x0027},
        table(), collation_strength::identical),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006f, 0x2018},
        std::vector<uint32_t>{0x006f, 0x0027},
        table(), collation_strength::quaternary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x006f, 0x0027},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006f, 0x0027},
        std::vector<uint32_t>{0x004f, 0x02bb},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006f, 0x0027},
        std::vector<uint32_t>{0x004f, 0x02bb},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x004f, 0x02bb},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004f, 0x02bb},
        std::vector<uint32_t>{0x004f, 0x2018},
        table(), collation_strength::identical),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004f, 0x02bb},
        std::vector<uint32_t>{0x004f, 0x2018},
        table(), collation_strength::quaternary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x004f, 0x2018},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004f, 0x2018},
        std::vector<uint32_t>{0x004f, 0x0027},
        table(), collation_strength::identical),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004f, 0x2018},
        std::vector<uint32_t>{0x004f, 0x0027},
        table(), collation_strength::quaternary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x004f, 0x0027},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004f, 0x0027},
        std::vector<uint32_t>{0x0067, 0x02bb},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x0067, 0x02bb},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0067, 0x02bb},
        std::vector<uint32_t>{0x0067, 0x2018},
        table(), collation_strength::identical),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0067, 0x02bb},
        std::vector<uint32_t>{0x0067, 0x2018},
        table(), collation_strength::quaternary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x0067, 0x2018},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0067, 0x2018},
        std::vector<uint32_t>{0x0067, 0x0027},
        table(), collation_strength::identical),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0067, 0x2018},
        std::vector<uint32_t>{0x0067, 0x0027},
        table(), collation_strength::quaternary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x0067, 0x0027},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0067, 0x0027},
        std::vector<uint32_t>{0x0047, 0x02bb},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0067, 0x0027},
        std::vector<uint32_t>{0x0047, 0x02bb},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x0047, 0x02bb},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0047, 0x02bb},
        std::vector<uint32_t>{0x0047, 0x2018},
        table(), collation_strength::identical),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0047, 0x02bb},
        std::vector<uint32_t>{0x0047, 0x2018},
        table(), collation_strength::quaternary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x0047, 0x2018},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0047, 0x2018},
        std::vector<uint32_t>{0x0047, 0x0027},
        table(), collation_strength::identical),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0047, 0x2018},
        std::vector<uint32_t>{0x0047, 0x0027},
        table(), collation_strength::quaternary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x0047, 0x0027},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0047, 0x0027},
        std::vector<uint32_t>{0x0073, 0x0068},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x0073, 0x0068},
        table(), collation_strength::quaternary),
        1);
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
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x0053, 0x0068},
        table(), collation_strength::quaternary),
        1);
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
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x0053, 0x0048},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0053, 0x0048},
        std::vector<uint32_t>{0x0063, 0x0068},
        table(), collation_strength::primary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x0063, 0x0068},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0063, 0x0068},
        std::vector<uint32_t>{0x0043, 0x0068},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0063, 0x0068},
        std::vector<uint32_t>{0x0043, 0x0068},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x0043, 0x0068},
        table(), collation_strength::quaternary),
        1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0043, 0x0068},
        std::vector<uint32_t>{0x0043, 0x0048},
        table(), collation_strength::tertiary),
        -1);
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0043, 0x0068},
        std::vector<uint32_t>{0x0043, 0x0048},
        table(), collation_strength::secondary),
        0);
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>{0x0043, 0x0048},
        table(), collation_strength::quaternary),
        1);
}
