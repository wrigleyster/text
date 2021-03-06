#ifndef BOOST_TEXT_WORD_BREAK_HPP
#define BOOST_TEXT_WORD_BREAK_HPP

#include <boost/text/algorithm.hpp>
#include <boost/text/lazy_segment_range.hpp>

#include <array>

#include <stdint.h>


namespace boost { namespace text {

    /** The word properties outlined in Unicode 10. */
    enum class word_property {
        Other,
        CR,
        LF,
        Newline,
        Katakana,
        ALetter,
        MidLetter,
        MidNum,
        MidNumLet,
        Numeric,
        ExtendNumLet,
        Regional_Indicator,
        Hebrew_Letter,
        Double_Quote,
        Single_Quote,
        E_Base,
        E_Modifier,
        Glue_After_Zwj,
        E_Base_GAZ,
        Format,
        Extend,
        ZWJ
    };

    namespace detail {
        struct word_prop_interval
        {
            uint32_t lo_;
            uint32_t hi_;
            word_property prop_;
        };

        inline bool
        operator<(word_prop_interval lhs, word_prop_interval rhs) noexcept
        {
            return lhs.hi_ <= rhs.lo_;
        }

        BOOST_TEXT_DECL std::array<word_prop_interval, 21> const &
        make_word_prop_intervals();
        BOOST_TEXT_DECL std::unordered_map<uint32_t, word_property> const &
        make_word_prop_map();
    }

    /** Returns the word property associated with code point \a cp. */
    inline word_property word_prop(uint32_t cp) noexcept
    {
        static auto const map = detail::make_word_prop_map();
        static auto const intervals = detail::make_word_prop_intervals();

        auto const it = map.find(cp);
        if (it == map.end()) {
            auto const it2 = std::lower_bound(
                intervals.begin(),
                intervals.end(),
                detail::word_prop_interval{cp, cp + 1});
            if (it2 == intervals.end() || cp < it2->lo_ || it2->hi_ <= cp)
                return word_property::Other;
            return it2->prop_;
        }
        return it->second;
    }

    namespace detail {
        inline bool skippable(word_property prop) noexcept
        {
            return prop == word_property::Extend ||
                   prop == word_property::Format || prop == word_property::ZWJ;
        }

        inline bool linebreak(word_property prop) noexcept
        {
            return prop == word_property::CR || prop == word_property::LF ||
                   prop == word_property::Newline;
        }

        inline bool ah_letter(word_property prop) noexcept
        {
            return prop == word_property::ALetter ||
                   prop == word_property::Hebrew_Letter;
        }

        // Corresonds to (MidLetter | MidNumLetQ) in WB6 and WB7
        inline bool mid_ah(word_property prop) noexcept
        {
            return prop == word_property::MidLetter ||
                   prop == word_property::MidNumLet ||
                   prop == word_property::Single_Quote;
        }

        // Corresonds to (MidNum | MidNumLetQ) in WB11 and WB12
        inline bool mid_num(word_property prop) noexcept
        {
            return prop == word_property::MidNum ||
                   prop == word_property::MidNumLet ||
                   prop == word_property::Single_Quote;
        }

        // Used in WB15, WB16
        enum class word_break_emoji_state_t {
            none,
            first_emoji, // Indicates that prop points to an odd-count emoji.
            second_emoji // Indicates that prop points to an even-count emoji.
        };

        template<typename CPIter>
        struct word_break_state
        {
            CPIter it;
            bool it_points_to_prev = false;

            word_property prev_prev_prop;
            word_property prev_prop;
            word_property prop;
            word_property next_prop;
            word_property next_next_prop;

            word_break_emoji_state_t emoji_state;
        };

        template<typename CPIter>
        word_break_state<CPIter> next(word_break_state<CPIter> state)
        {
            ++state.it;
            state.prev_prev_prop = state.prev_prop;
            state.prev_prop = state.prop;
            state.prop = state.next_prop;
            state.next_prop = state.next_next_prop;
            return state;
        }

        template<typename CPIter>
        word_break_state<CPIter> prev(word_break_state<CPIter> state)
        {
            if (!state.it_points_to_prev)
                --state.it;
            state.it_points_to_prev = false;
            state.next_next_prop = state.next_prop;
            state.next_prop = state.prop;
            state.prop = state.prev_prop;
            state.prev_prop = state.prev_prev_prop;
            return state;
        }

        inline bool table_word_break(word_property lhs, word_property rhs)
        {
            // clang-format off
// See chart at http://www.unicode.org/Public/UCD/latest/ucd/auxiliary/WordBreakTest.html.
constexpr std::array<std::array<bool, 22>, 22> word_breaks = {{
//  Other CR LF NL Ktk AL ML MN MNL Num ENL RI HL DQ SQ E_Bse E_Mod GAZ EBG Fmt Extd ZWJ
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // Other
    {{1,   1, 0, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  1,  1,   1}}, // CR
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  1,  1,   1}}, // LF
                                                                                     
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  1,  1,   1}}, // Newline
    {{1,   1, 1, 1, 0,  1, 1, 1, 1,  1,  0,  1, 1, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // Katakana
    {{1,   1, 1, 1, 1,  0, 1, 1, 1,  0,  0,  1, 0, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // ALetter
                                                                                     
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // MidLetter
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // MidNum
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // MidNumLet
                                                                                     
    {{1,   1, 1, 1, 1,  0, 1, 1, 1,  0,  0,  1, 0, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // Numeric
    {{1,   1, 1, 1, 0,  0, 1, 1, 1,  0,  0,  1, 0, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // ExtendNumLet
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  0, 1, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // RI
                                                                                     
    {{1,   1, 1, 1, 1,  0, 1, 1, 1,  0,  0,  1, 0, 1, 0, 1,    1,    1,  1,  0,  0,   0}}, // Hebrew_Letter
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // Double_Quote
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // Single_Quote
                                                                                     
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    0,    1,  1,  0,  0,   0}}, // E_Base
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // E_Modifier
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // Glue_After_Zwj
                                                                                     
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    0,    1,  1,  0,  0,   0}}, // EBG
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // Format
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    1,  1,  0,  0,   0}}, // Extend
                                                                                     
    {{1,   1, 1, 1, 1,  1, 1, 1, 1,  1,  1,  1, 1, 1, 1, 1,    1,    0,  0,  0,  0,   0}}, // ZWJ
}};
            // clang-format on
            auto const lhs_int = static_cast<int>(lhs);
            auto const rhs_int = static_cast<int>(rhs);
            return word_breaks[lhs_int][rhs_int];
        }

        // WB4: Except after line breaks, ignore/skip (Extend | Format |
        // ZWJ)*
        template<typename CPIter, typename Sentinel>
        word_break_state<CPIter> skip_forward(
            word_break_state<CPIter> state, CPIter first, Sentinel last)
        {
            if (state.it != first && !skippable(state.prev_prop) &&
                skippable(state.prop)) {
                auto temp_it = find_if_not(state.it, last, [](uint32_t cp) {
                    return skippable(word_prop(cp));
                });
                if (temp_it == last)
                    --temp_it;
                auto const temp_prop = word_prop(*temp_it);
                state.it = temp_it;
                state.prop = temp_prop;
                state.next_prop = word_property::Other;
                state.next_next_prop = word_property::Other;
                if (std::next(state.it) != last) {
                    state.next_prop = word_prop(*std::next(state.it));
                    if (std::next(state.it, 2) != last) {
                        state.next_next_prop =
                            word_prop(*std::next(state.it, 2));
                    }
                }
            }
            return state;
        }
    }

    /** Finds the nearest word break at or before before <code>it</code>.  If
        <code>it == first</code>, that is returned.  Otherwise, the first code
        point of the word that <code>it</code> is within is returned (even if
        <code>it</code> is already at the first code point of a word). */
    template<typename CPIter, typename Sentinel>
    auto prev_word_break(CPIter first, CPIter it, Sentinel last) noexcept
        -> detail::cp_iter_ret_t<CPIter, CPIter>
    {
        if (it == first)
            return it;

        if (it == last && --it == first)
            return it;

        detail::word_break_state<CPIter> state;

        state.it = it;

        state.prop = word_prop(*state.it);

        // Special case: If state.prop is skippable, we need to skip backward
        // until we find a non-skippable.
        if (detail::skippable(state.prop)) {
            state.it = find_if_not_backward(first, it, [](uint32_t cp) {
                return detail::skippable(word_prop(cp));
            });
            state.next_prop = word_prop(*std::next(state.it));
            state.prop = word_prop(*state.it);

            // If we end up on a non-skippable that should break before the
            // skippable(s) we just moved over, break on the last skippable.
            if (!detail::skippable(state.prop) &&
                detail::table_word_break(state.prop, state.next_prop)) {
                return ++state.it;
            }
            if (state.it == first)
                return first;
        }

        state.prev_prev_prop = word_property::Other;
        if (std::prev(state.it) != first)
            state.prev_prev_prop = word_prop(*std::prev(state.it, 2));
        state.prev_prop = word_prop(*std::prev(state.it));
        state.next_prop = word_property::Other;
        state.next_next_prop = word_property::Other;
        if (std::next(state.it) != last) {
            state.next_prop = word_prop(*std::next(state.it));
            if (std::next(state.it, 2) != last)
                state.next_next_prop = word_prop(*std::next(state.it, 2));
        }

        // Since 'it' may be anywhere within the word in which it sits, we
        // need to look forward to make sure that next_prop and next_next_prop
        // don't point to skippables.
        {
            if (std::next(state.it) != last) {
                auto temp_state = state;
                temp_state = next(temp_state);
                temp_state = detail::skip_forward(temp_state, first, last);
                if (temp_state.it == last) {
                    state.next_prop = word_property::Other;
                    state.next_next_prop = word_property::Other;
                } else {
                    state.next_prop = temp_state.prop;
                    if (std::next(temp_state.it) != last) {
                        temp_state = next(temp_state);
                        temp_state =
                            detail::skip_forward(temp_state, first, last);
                        if (temp_state.it == last)
                            state.next_next_prop = word_property::Other;
                        else
                            state.next_next_prop = temp_state.prop;
                    }
                }
            }
        }

        state.emoji_state = detail::word_break_emoji_state_t::none;

        // WB4: Except after line breaks, ignore/skip (Extend | Format |
        // ZWJ)*
        auto skip = [](detail::word_break_state<CPIter> state, CPIter first) {
            if (detail::skippable(state.prev_prop)) {
                auto temp_it =
                    find_if_not_backward(first, state.it, [](uint32_t cp) {
                        return detail::skippable(word_prop(cp));
                    });
                if (temp_it == state.it)
                    return state;
                auto temp_prev_prop = word_prop(*temp_it);
                if (!detail::linebreak(temp_prev_prop)) {
                    state.it = temp_it;
                    state.it_points_to_prev = true;
                    state.prev_prop = temp_prev_prop;
                    if (temp_it == first)
                        state.prev_prev_prop = word_property::Other;
                    else
                        state.prev_prev_prop = word_prop(*std::prev(temp_it));
                }
            }
            return state;
        };

        for (; state.it != first; state = prev(state)) {
            if (std::prev(state.it) != first)
                state.prev_prev_prop = word_prop(*std::prev(state.it, 2));
            else
                state.prev_prev_prop = word_property::Other;

            // When we see an RI, back up to the first RI so we can see what
            // emoji state we're supposed to be in here.
            if (state.emoji_state == detail::word_break_emoji_state_t::none &&
                state.prop == word_property::Regional_Indicator) {
                auto temp_state = state;
                int ris_before = 0;
                while (temp_state.it != first) {
                    temp_state = skip(temp_state, first);
                    if (temp_state.it == first) {
                        if (temp_state.prev_prop ==
                            word_property::Regional_Indicator) {
                            ++ris_before;
                        }
                        break;
                    }
                    if (temp_state.prev_prop ==
                        word_property::Regional_Indicator) {
                        temp_state = prev(temp_state);
                        if (temp_state.it != first &&
                            std::prev(temp_state.it) != first) {
                            temp_state.prev_prev_prop =
                                word_prop(*std::prev(temp_state.it, 2));
                        } else {
                            temp_state.prev_prev_prop = word_property::Other;
                        }
                        ++ris_before;
                    } else {
                        break;
                    }
                }
                state.emoji_state =
                    (ris_before % 2 == 0)
                        ? detail::word_break_emoji_state_t::first_emoji
                        : detail::word_break_emoji_state_t::second_emoji;
            }

            // WB3
            if (state.prev_prop == word_property::CR &&
                state.prop == word_property::LF) {
                continue;
            }

            // WB3a
            if (state.prev_prop == word_property::CR ||
                state.prev_prop == word_property::LF ||
                state.prev_prop == word_property::Newline) {
                return state.it;
            }

            // WB3b
            if (state.prop == word_property::CR ||
                state.prop == word_property::LF ||
                state.prop == word_property::Newline) {
                return state.it;
            }

            // WB3c
            if (state.prev_prop == word_property::ZWJ &&
                (state.prop == word_property::Glue_After_Zwj ||
                 state.prop == word_property::E_Base_GAZ)) {
                continue;
            }

            // If we end up breaking durign this iteration, we want the break
            // to show up after the skip, so that the skippable CPs go with
            // the CP before them.  This is to maintain symmetry with
            // next_word_break().
            auto after_skip_it = state.it;

            // Puting this here means not having to do it explicitly below
            // between prev_prop and prop (and transitively, between prop and
            // next_prop).
            state = skip(state, first);

            // WB6
            if (detail::ah_letter(state.prev_prop) &&
                detail::mid_ah(state.prop) &&
                detail::ah_letter(state.next_prop)) {
                continue;
            }

            // WB7
            if (detail::mid_ah(state.prev_prop) &&
                detail::ah_letter(state.prop) && state.it != first) {
                auto const temp_state = skip(prev(state), first);
                if (detail::ah_letter(temp_state.prev_prop))
                    continue;
            }

            // WB7b
            if (state.prev_prop == word_property::Hebrew_Letter &&
                state.prop == word_property::Double_Quote &&
                state.next_prop == word_property::Hebrew_Letter) {
                continue;
            }

            // WB7c
            if (state.prev_prop == word_property::Double_Quote &&
                state.prop == word_property::Hebrew_Letter &&
                state.it != first) {
                auto const temp_state = skip(prev(state), first);
                if (temp_state.prev_prop == word_property::Hebrew_Letter)
                    continue;
            }

            // WB11
            if (detail::mid_num(state.prev_prop) &&
                state.prop == word_property::Numeric && state.it != first) {
                auto const temp_state = skip(prev(state), first);
                if (temp_state.prev_prop == word_property::Numeric)
                    continue;
            }

            // WB12
            if (state.prev_prop == word_property::Numeric &&
                detail::mid_num(state.prop) &&
                state.next_prop == word_property::Numeric) {
                continue;
            }

            if (state.emoji_state ==
                detail::word_break_emoji_state_t::first_emoji) {
                if (state.prev_prop == word_property::Regional_Indicator) {
                    state.emoji_state =
                        detail::word_break_emoji_state_t::second_emoji;
                    return after_skip_it;
                } else {
                    state.emoji_state = detail::word_break_emoji_state_t::none;
                }
            } else if (
                state.emoji_state ==
                    detail::word_break_emoji_state_t::second_emoji &&
                state.prev_prop == word_property::Regional_Indicator) {
                state.emoji_state =
                    detail::word_break_emoji_state_t::first_emoji;
                continue;
            }

            if (detail::table_word_break(state.prev_prop, state.prop))
                return after_skip_it;
        }

        return first;
    }

    /** Finds the next word break after <code>first</code>.  This will be the
        first code point after the current word, or <code>last</code> if no
        next word exists.

        \pre <code>first</code> is at the beginning of a word. */
    template<typename CPIter, typename Sentinel>
    auto next_word_break(CPIter first, Sentinel last) noexcept
        -> detail::cp_iter_ret_t<CPIter, CPIter>
    {
        if (first == last)
            return first;

        detail::word_break_state<CPIter> state;
        state.it = first;

        if (++state.it == last)
            return state.it;

        state.prev_prev_prop = word_property::Other;
        state.prev_prop = word_prop(*std::prev(state.it));
        state.prop = word_prop(*state.it);
        state.next_prop = word_property::Other;
        state.next_next_prop = word_property::Other;
        if (std::next(state.it) != last) {
            state.next_prop = word_prop(*std::next(state.it));
            if (std::next(state.it, 2) != last)
                state.next_next_prop = word_prop(*std::next(state.it, 2));
        }

        state.emoji_state = state.prev_prop == word_property::Regional_Indicator
                                ? detail::word_break_emoji_state_t::first_emoji
                                : detail::word_break_emoji_state_t::none;

        for (; state.it != last; state = next(state)) {
            if (std::next(state.it) != last && std::next(state.it, 2) != last)
                state.next_next_prop = word_prop(*std::next(state.it, 2));
            else
                state.next_next_prop = word_property::Other;

            // WB3
            if (state.prev_prop == word_property::CR &&
                state.prop == word_property::LF) {
                continue;
            }

            // WB3a
            if (state.prev_prop == word_property::CR ||
                state.prev_prop == word_property::LF ||
                state.prev_prop == word_property::Newline) {
                return state.it;
            }

            // WB3b
            if (state.prop == word_property::CR ||
                state.prop == word_property::LF ||
                state.prop == word_property::Newline) {
                return state.it;
            }

            // WB3c
            if (state.prev_prop == word_property::ZWJ &&
                (state.prop == word_property::Glue_After_Zwj ||
                 state.prop == word_property::E_Base_GAZ)) {
                continue;
            }

            // Puting this here means not having to do it explicitly below
            // between prop and next_prop (and transitively, between prev_prop
            // and prop).
            state = detail::skip_forward(state, first, last);
            if (state.it == last)
                return state.it;

            // WB6
            if (detail::ah_letter(state.prev_prop) &&
                detail::mid_ah(state.prop) && std::next(state.it) != last) {
                auto const temp_state =
                    detail::skip_forward(next(state), first, last);
                if (temp_state.it == last)
                    return temp_state.it;
                if (detail::ah_letter(temp_state.prop))
                    continue;
            }

            // WB7
            if (detail::ah_letter(state.prev_prev_prop) &&
                detail::mid_ah(state.prev_prop) &&
                detail::ah_letter(state.prop)) {
                continue;
            }

            // WB7b
            if (state.prev_prop == word_property::Hebrew_Letter &&
                state.prop == word_property::Double_Quote &&
                std::next(state.it) != last) {
                auto const temp_state =
                    detail::skip_forward(next(state), first, last);
                if (temp_state.it == last)
                    return temp_state.it;
                if (temp_state.prop == word_property::Hebrew_Letter)
                    continue;
            }

            // WB7c
            if (state.prev_prev_prop == word_property::Hebrew_Letter &&
                state.prev_prop == word_property::Double_Quote &&
                state.prop == word_property::Hebrew_Letter) {
                continue;
            }

            // WB11
            if (state.prev_prev_prop == word_property::Numeric &&
                detail::mid_num(state.prev_prop) &&
                state.prop == word_property::Numeric) {
                continue;
            }

            // WB12
            if (state.prev_prop == word_property::Numeric &&
                detail::mid_num(state.prop) && std::next(state.it) != last) {
                auto const temp_state =
                    detail::skip_forward(next(state), first, last);
                if (temp_state.it == last)
                    return temp_state.it;
                if (temp_state.prop == word_property::Numeric)
                    continue;
            }

            if (state.emoji_state ==
                detail::word_break_emoji_state_t::first_emoji) {
                if (state.prop == word_property::Regional_Indicator) {
                    state.emoji_state = detail::word_break_emoji_state_t::none;
                    continue;
                } else {
                    state.emoji_state = detail::word_break_emoji_state_t::none;
                }
            } else if (state.prop == word_property::Regional_Indicator) {
                state.emoji_state =
                    detail::word_break_emoji_state_t::first_emoji;
                return state.it;
            }

            if (detail::table_word_break(state.prev_prop, state.prop))
                return state.it;
        }
        return state.it;
    }

    /** Finds the nearest word break at or before before <code>it</code>.  If
        <code>it == range.begin()</code>, that is returned.  Otherwise, the
        first code point of the word that <code>it</code> is within is
        returned (even if <code>it</code> is already at the first code point
        of a word). */
    template<typename CPRange, typename CPIter>
    auto prev_word_break(CPRange & range, CPIter it) noexcept
        -> detail::iterator_t<CPRange>
    {
        using std::begin;
        using std::end;
        return prev_word_break(begin(range), it, end(range));
    }

    /** Finds the next word break after <code>range.begin()</code>.  This will
        be the first code point after the current word, or
        <code>range.end()</code> if no next word exists.

        \pre <code>range.begin()</code> is at the beginning of a word. */
    template<typename CPRange>
    auto next_word_break(CPRange & range) noexcept
        -> detail::iterator_t<CPRange>
    {
        using std::begin;
        using std::end;
        return next_word_break(begin(range), end(range));
    }

    namespace detail {
        template<typename CPIter, typename Sentinel>
        struct next_word_callable
        {
            auto operator()(CPIter it, Sentinel last) noexcept
                -> detail::cp_iter_ret_t<CPIter, CPIter>
            {
                return next_word_break(it, last);
            }
        };
    }

    /** Returns the bounds of the word that <code>it</code> lies within. */
    template<typename CPIter, typename Sentinel>
    cp_range<CPIter> word(CPIter first, CPIter it, Sentinel last) noexcept
    {
        first = prev_word_break(first, it, last);
        return cp_range<CPIter>{first, next_word_break(first, last)};
    }

    /** Returns the bounds of the word that <code>it</code> lies within. */
    template<typename CPRange, typename CPIter>
    auto word(CPRange & range, CPIter it) noexcept
        -> cp_range<detail::iterator_t<CPRange>>
    {
        using std::begin;
        using std::end;
        auto first = prev_word_break(begin(range), it, end(range));
        return cp_range<CPIter>{first, next_word_break(first, end(range))};
    }

    /** Returns a lazy range of the code point ranges delimiting words in
        <code>[first, last)</code>. */
    template<typename CPIter, typename Sentinel>
    lazy_segment_range<
        CPIter,
        Sentinel,
        detail::next_word_callable<CPIter, Sentinel>>
    words(CPIter first, Sentinel last) noexcept
    {
        return {{first, last}, {last}};
    }

    /** Returns a lazy range of the code point ranges delimiting words in
        <code>range</code>. */
    template<typename CPRange>
    auto words(CPRange & range) noexcept -> lazy_segment_range<
        detail::iterator_t<CPRange>,
        detail::sentinel_t<CPRange>,
        detail::next_word_callable<
            detail::iterator_t<CPRange>,
            detail::sentinel_t<CPRange>>>
    {
        using std::begin;
        using std::end;
        return {{begin(range), end(range)}, {end(range)}};
    }

}}

#endif
