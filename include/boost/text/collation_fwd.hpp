#ifndef BOOST_TEXT_COLLATION_FWD_HPP
#define BOOST_TEXT_COLLATION_FWD_HPP

#include <cstdint>


namespace boost { namespace text {

    /** Collation strength.

        \see https://www.unicode.org/reports/tr10/#Multi_Level_Comparison
    */
    enum class collation_strength {
        primary,
        secondary,
        tertiary,
        quaternary,
        identical
    };

    /** Collation variable weighting.

        \see https://www.unicode.org/reports/tr10/#Variable_Weighting
    */
    enum class variable_weighting { non_ignorable, shifted };

    /** The order of L2 collation weights.  Only Canandian French uses
        backward. */
    enum class l2_weight_order { forward, backward };

    /** Controls whether a notional case level used in a tailored collation table.

        \see https://www.unicode.org/reports/tr35/tr35-collation.html#Case_Parameters
    */
    enum class case_level { on, off };

    /** Controls whether a preference is given to upper- or lower-case code
        points in a tailored collation table.

        \see https://www.unicode.org/reports/tr35/tr35-collation.html#Case_Parameters
    */
    enum class case_first { upper, lower, off };

    template<typename CharIter>
    struct read_table_result;

    struct collation_table;

    namespace detail {

        enum class retain_case_bits_t { no, yes };

        enum case_bits : uint16_t {
            lower_case_bits = 0x0000,
            mixed_case_bits = 0x4000,
            upper_case_bits = 0x8000
        };

        inline uint32_t
        replace_lead_byte(uint32_t l1_weight, uint32_t new_lead_byte)
        {
            l1_weight &= 0x00ffffff;
            l1_weight |= new_lead_byte;
            return l1_weight;
        }
    }

}}

#endif
