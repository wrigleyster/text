#ifndef BOOST_TEXT_DETAIL_CASE_MAPPING_DATA_HPP
#define BOOST_TEXT_DETAIL_CASE_MAPPING_DATA_HPP

#include <boost/text/config.hpp>
#include <boost/text/detail/case_constants.hpp>

#include <unordered_map>
#include <unordered_set>


namespace boost { namespace text { namespace detail {

    struct case_mapping_to
    {
        uint16_t first_;      // cp indices
        uint16_t last_;
        uint16_t conditions_;
    };

    struct case_mapping
    {
        uint32_t from_;
        uint16_t first_;      // case_mapping_to indices
        uint16_t last_;
    };

    struct case_elements
    {
        using iterator = case_mapping_to const *;

        iterator begin(case_mapping_to const * elements) const noexcept
        {
            return elements + first_;
        }
        iterator end(case_mapping_to const * elements) const noexcept
        {
            return elements + last_;
        }

        int size() const noexcept { return last_ - first_; }
        explicit operator bool() const noexcept { return first_ != last_; }

        uint16_t first_;
        uint16_t last_;
    };

    inline bool operator==(case_elements lhs, case_elements rhs) noexcept
    {
        return lhs.first_ == rhs.first_ && lhs.last_ == rhs.last_;
    }
    inline bool operator!=(case_elements lhs, case_elements rhs) noexcept
    {
        return !(lhs == rhs);
    }

    using case_map_t = std::unordered_map<uint32_t, case_elements>;

    BOOST_TEXT_DECL case_map_t make_to_lower_map();
    BOOST_TEXT_DECL case_map_t make_to_title_map();
    BOOST_TEXT_DECL case_map_t make_to_upper_map();
    BOOST_TEXT_DECL std::vector<uint32_t> make_soft_dotted_cps();
    BOOST_TEXT_DECL std::vector<uint32_t> make_soft_dotted_cps();
    BOOST_TEXT_DECL std::unordered_set<uint32_t> make_cased_cps();
    BOOST_TEXT_DECL std::unordered_set<uint32_t> make_case_ignorable_cps();
    BOOST_TEXT_DECL extern uint32_t const * g_case_cps_first;
    BOOST_TEXT_DECL extern case_mapping_to const * g_case_mapping_to_first;

    inline case_map_t const & to_lower_map()
    {
        static case_map_t const retval = make_to_lower_map();
        return retval;
    }

    inline case_map_t const & to_title_map()
    {
        static case_map_t const retval = make_to_title_map();
        return retval;
    }

    inline case_map_t const & to_upper_map()
    {
        static case_map_t const retval = make_to_upper_map();
        return retval;
    }

    inline bool cased(uint32_t cp)
    {
        static std::unordered_set<uint32_t> const cps = make_cased_cps();
        return 0 < cps.count(cp);
    }

    inline bool case_ignorable(uint32_t cp)
    {
        static std::unordered_set<uint32_t> const cps =
            make_case_ignorable_cps();
        return 0 < cps.count(cp);
    }

    inline bool soft_dotted(uint32_t cp)
    {
        static std::vector<uint32_t> const cps = make_soft_dotted_cps();
        auto const it = std::lower_bound(cps.begin(), cps.end(), cp);
        return it != cps.end() && *it == cp;
    }

}}}

#endif
