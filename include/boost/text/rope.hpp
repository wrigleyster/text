#ifndef BOOST_TEXT_ROPE_HPP
#define BOOST_TEXT_ROPE_HPP

#include <boost/text/grapheme_iterator.hpp>
#include <boost/text/utf8.hpp>

#include <iterator>


#ifndef BOOST_TEXT_DOXYGEN

#ifdef BOOST_TEXT_TESTING
#define BOOST_TEXT_CHECK_ROPE_NORMALIZATION()                                  \
    do {                                                                       \
        string str(rope_);                                                     \
        normalize_to_fcc(str);                                                 \
        assert(rope_ == str);                                                  \
    } while (false)
#else
#define BOOST_TEXT_CHECK_ROPE_NORMALIZATION()
#endif

#endif

namespace boost { namespace text {

    namespace detail {
        struct const_rope_iterator;
    }

    struct text;
    struct rope_view;

    /** A mutable sequence of graphemes with copy-on-write semantics.  A rope
        is non-contiguous and is not null-terminated.  The underlying storage
        is an unencoded_rope that is UTF-8-encoded and FCC-normalized. */
    struct rope
    {
        using value_type =
            cp_range<utf8::to_utf32_iterator<detail::const_rope_iterator>>;
        using size_type = std::ptrdiff_t;
        using iterator = grapheme_iterator<
            utf8::to_utf32_iterator<detail::const_rope_iterator>>;
        using const_iterator = iterator;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = reverse_iterator;

        /** Default ctor. */
        rope() {}

        /** Constructs a text from a pair of iterators. */
        rope(const_iterator first, const_iterator last);

        /** Constructs a rope from a null-terminated string. */
        rope(char const * c_str);

        /** Constructs a rope from a string_view. */
        explicit rope(string_view sv);

        /** Constructs a rope from a rope_view. */
        explicit rope(rope_view rv);

        /** Constructs a rope from a string. */
        explicit rope(string s);

        /** Constructs a rope from a text. */
        explicit rope(text t);

#ifdef BOOST_TEXT_DOXYGEN

        /** Constructs a rope from a range of char.

            This function only participates in overload resolution if
            CharRange models the CharRange concept. */
        template<typename CharRange>
        explicit rope(CharRange const & r);

        /** Constructs a rope from a sequence of char.

            This function only participates in overload resolution if CharIter
            models the CharIter concept. */
        template<typename CharIter>
        rope(CharIter first, Iter Charlast);

#else

        template<typename CharRange>
        explicit rope(
            CharRange const & r, detail::rng_alg_ret_t<int *, CharRange> = 0);

        template<typename CharIter>
        rope(
            CharIter first,
            CharIter last,
            detail::char_iter_ret_t<void *, CharIter> = 0);

#endif

        /** Assignment from a null-terminated string. */
        rope & operator=(char const * c_str);

        /** Assignment from a rope_view. */
        rope & operator=(rope_view rv);

        /** Assignment from a string_view. */
        rope & operator=(string_view sv);

        /** Move-assignment from a string. */
        rope & operator=(string s);

        /** Move-assignment from a text. */
        rope & operator=(text t);

#ifdef BOOST_TEXT_DOXYGEN

        /** Assignment from a range of char.

            This function only participates in overload resolution if
            CharRange models the CharRange concept. */
        template<typename CharRange>
        rope & operator=(CharRange const & r);

#else

        template<typename CharRange>
        auto operator=(CharRange const & r)
            -> detail::rng_alg_ret_t<rope &, CharRange>;

#endif

        const_iterator begin() const noexcept;
        const_iterator end() const noexcept;

        const_iterator cbegin() const noexcept;
        const_iterator cend() const noexcept;

        const_reverse_iterator rbegin() const noexcept;
        const_reverse_iterator rend() const noexcept;

        const_reverse_iterator crbegin() const noexcept;
        const_reverse_iterator crend() const noexcept;

        /** Returns true if begin() == end(), false otherwise. */
        bool empty() const noexcept;

        /** Returns the number of bytes controlled by *this, not including the
            null terminator. */
        size_type storage_bytes() const noexcept;

        /** Returns the number of graphemes in *this.  This operation is
            O(n). */
        size_type distance() const noexcept;

        /** Returns the maximum size a rope can have. */
        size_type max_size() const noexcept { return PTRDIFF_MAX; }

        /** Returns true if *this and rhs contain the same root node pointer.
            This is useful when you want to check for equality between two
            unencoded_ropes that are likely to have originated from the same
            initial unencoded_rope, and may have since been mutated. */
        bool equal_root(rope rhs) const noexcept;

        /** Clear. */
        void clear() noexcept;

        /** Inserts the sequence of char from c_str into *this starting at
            position at. */
        const_iterator insert(const_iterator at, char const * c_str);

        /** Inserts the sequence of char from rv into *this starting at position
            at. */
        const_iterator insert(const_iterator at, rope_view rv);

        /** Inserts s into *this starting at position at. */
        const_iterator insert(const_iterator at, string && s);

        /** Inserts the sequence of char from sv into *this starting at position
            at. */
        const_iterator insert(const_iterator at, string_view sv);

        /** Inserts the sequence of char from rsv into *this starting at
            position at. */
        const_iterator insert(const_iterator at, repeated_string_view rsv);

#ifdef BOOST_TEXT_DOXYGEN

        /** Inserts the char range r into *this starting at position at.

            This function only participates in overload resolution if
            CharRange models the CharRange concept. */
        template<typename CharRange>
        const_iterator insert(const_iterator at, CharRange const & r);

        /** Inserts the char sequence [first, last) into *this starting at
            position at.

            This function only participates in overload resolution if CharIter
            models the CharIter concept. */
        template<typename CharIter>
        const_iterator insert(const_iterator at, CharIter first, CharIter last);

#else

        template<typename CharRange>
        auto insert(const_iterator at, CharRange const & r)
            -> detail::rng_alg_ret_t<const_iterator, CharRange>;

        template<typename CharIter>
        auto insert(const_iterator at, CharIter first, CharIter last)
            -> detail::char_iter_ret_t<const_iterator, CharIter>;

#endif

        /** Erases the portion of *this delimited by rv.

            \pre !std::less(rv.begin().base().base(), begin().base().base()) &&
            !std::less(end().base().base(), rv.end().base().base()) */
        rope & erase(rope_view rv);

        /** Erases the portion of *this delimited by [first, last).

            \pre first <= last */
        const_iterator erase(const_iterator first, const_iterator last);

        /** Replaces the portion of *this delimited by old_substr with the
            sequence of char from new_substr.

            \pre !std::less(old_substr.begin().base().base(),
            begin().base().base()) && !std::less(end().base().base(),
            old_substr.end().base().base()) */
        rope & replace(rope_view old_substr, rope_view new_substr);

        /** Replaves the  portion of *this delimited by old_substr with the
            sequence of char from new_substr.

            \pre !std::less(old_substr.begin().base().base(),
            begin().base().base()) && !std::less(end().base().base(),
            old_substr.end().base().base()) */
        rope & replace(rope_view old_substr, string_view new_substr);

        /** Replaces the portion of *this delimited by old_substr with the
            sequence of char from new_substr.

            \pre !std::less(old_substr.begin().base().base(),
            begin().base().base()) && !std::less(end().base().base(),
            old_substr.end().base().base()) */
        rope & replace(rope_view old_substr, repeated_string_view new_substr);

#ifdef BOOST_TEXT_DOXYGEN

        /** Replaces the portion of *this delimited by old_substr with the
            char range r.

            This function only participates in overload resolution if
            CharRange models the CharRange concept.

            \pre !std::less(old_substr.begin().base().base(),
            begin().base().base()) && !std::less(end().base().base(),
            old_substr.end().base().base()) */
        template<typename CharRange>
        rope & replace(rope_view old_substr, CharRange const & r);

        /** Replaces the portion of *this delimited by old_substr with the
            char sequence [first, last).

            This function only participates in overload resolution if CharIter
            models the CharIter concept.

            \pre !std::less(old_substr.begin().base().base(),
            begin().base().base()) && !std::less(end().base().base(),
            old_substr.end().base().base()) */
        template<typename CharIter>
        rope & replace(rope_view old_substr, CharIter first, CharIter last);

#else

        template<typename CharRange>
        auto replace(rope_view old_substr, CharRange const & r)
            -> detail::rng_alg_ret_t<rope &, CharRange>;

        template<typename CharIter>
        auto replace(rope_view old_substr, CharIter first, CharIter last)
            -> detail::char_iter_ret_t<rope &, CharIter>;

#endif

        /** Swaps *this with rhs. */
        void swap(rope & rhs) noexcept;

        /** Removes and returns the underlying unencoded_rope from *this. */
        unencoded_rope extract() && noexcept;

        /** Replaces the underlying unencoded_rope in *this. */
        void replace(unencoded_rope && ur) noexcept;

        /** Appends c_str to *this. */
        rope & operator+=(char const * c_str);

        /** Appends rv to *this. */
        rope & operator+=(rope_view rv);

        /** Appends tv to *this. */
        rope & operator+=(string_view sv);

        /** Appends rtv to *this. */
        rope & operator+=(repeated_string_view rsv);

#ifdef BOOST_TEXT_DOXYGEN

        /** Appends the char range r to *this.

            This function only participates in overload resolution if
            CharRange models the CharRange concept.

            \throw std::invalid_argument if the ends of the range are not
            valid UTF-8. */
        template<typename CharRange>
        rope & operator+=(CharRange const & r);

#else

        template<typename CharRange>
        auto operator+=(CharRange const & r)
            -> detail::rng_alg_ret_t<rope &, CharRange>;

#endif

        /** Stream inserter; performs formatted output, in UTF-8 encoding. */
        friend std::ostream & operator<<(std::ostream & os, rope const & r)
        {
            if (os.good()) {
                auto const size = r.distance();
                detail::pad_width_before(os, size);
                os << r.rope_;
                if (os.good())
                    detail::pad_width_after(os, size);
            }
            return os;
        }

#ifndef BOOST_TEXT_DOXYGEN

    private:
        static const_iterator make_iter(
            detail::const_rope_iterator first,
            detail::const_rope_iterator it,
            detail::const_rope_iterator last) noexcept;

        using mutable_utf32_iter =
            utf8::to_utf32_iterator<detail::const_rope_iterator>;

        mutable_utf32_iter prev_stable_cp(mutable_utf32_iter last) noexcept;
        mutable_utf32_iter next_stable_cp(mutable_utf32_iter first) noexcept;

        const_iterator
        insert_impl(iterator at, string str, bool str_normalized);
        rope &
        replace_impl(rope_view old_substr, string str, bool str_normalized);

        unencoded_rope rope_;

        friend struct ::boost::text::rope_view;

#endif // Doxygen
    };

    inline rope::iterator begin(rope const & t) noexcept { return t.begin(); }
    inline rope::iterator end(rope const & t) noexcept { return t.end(); }
    inline rope::iterator cbegin(rope const & t) noexcept { return t.cbegin(); }
    inline rope::iterator cend(rope const & t) noexcept { return t.cend(); }

    inline rope::reverse_iterator rbegin(rope const & t) noexcept
    {
        return t.rbegin();
    }
    inline rope::reverse_iterator rend(rope const & t) noexcept
    {
        return t.rend();
    }
    inline rope::reverse_iterator crbegin(rope const & t) noexcept
    {
        return t.crbegin();
    }
    inline rope::reverse_iterator crend(rope const & t) noexcept
    {
        return t.crend();
    }

}}

#include <boost/text/text.hpp>
#include <boost/text/rope_view.hpp>
#include <boost/text/normalize.hpp>
#include <boost/text/detail/rope_iterator.hpp>

#ifndef BOOST_TEXT_DOXYGEN

namespace boost { namespace text {

    inline rope::rope(const_iterator first, const_iterator last) :
        rope(rope_view(first, last))
    {}

    inline rope::rope(char const * c_str) : rope_(text(c_str).extract()) {}

    inline rope::rope(rope_view rv) :
        rope_(rv.begin().base().base(), rv.end().base().base())
    {}

    inline rope::rope(string_view sv) : rope_(text(sv).extract()) {}

    inline rope::rope(string s) : rope_(text(std::move(s)).extract()) {}

    inline rope::rope(text t) : rope_(std::move(t).extract()) {}

    template<typename CharRange>
    rope::rope(CharRange const & r, detail::rng_alg_ret_t<int *, CharRange>) :
        rope_(text(r).extract())
    {}

    template<typename CharIter>
    rope::rope(
        CharIter first,
        CharIter last,
        detail::char_iter_ret_t<void *, CharIter>) :
        rope_(text(first, last).extract())
    {}

    inline rope & rope::operator=(char const * c_str)
    {
        rope temp(c_str);
        swap(temp);
        return *this;
    }

    inline rope & rope::operator=(rope_view rv)
    {
        rope temp(rv);
        swap(temp);
        return *this;
    }

    inline rope & rope::operator=(string_view sv)
    {
        rope temp(sv);
        swap(temp);
        return *this;
    }

    inline rope & rope::operator=(string s)
    {
        rope temp(std::move(s));
        swap(temp);
        return *this;
    }

    inline rope & rope::operator=(text t)
    {
        rope temp(std::move(t));
        swap(temp);
        return *this;
    }

    template<typename CharRange>
    auto rope::operator=(CharRange const & r)
        -> detail::rng_alg_ret_t<rope &, CharRange>
    {
        rope temp(r);
        swap(temp);
        return *this;
    }

    inline rope::const_iterator rope::begin() const noexcept
    {
        return make_iter(rope_.begin(), rope_.begin(), rope_.end());
    }
    inline rope::const_iterator rope::end() const noexcept
    {
        return make_iter(rope_.begin(), rope_.end(), rope_.end());
    }

    inline rope::const_iterator rope::cbegin() const noexcept
    {
        return begin();
    }
    inline rope::const_iterator rope::cend() const noexcept { return end(); }

    inline rope::const_reverse_iterator rope::rbegin() const noexcept
    {
        return reverse_iterator(end());
    }
    inline rope::const_reverse_iterator rope::rend() const noexcept
    {
        return reverse_iterator(begin());
    }

    inline rope::const_reverse_iterator rope::crbegin() const noexcept
    {
        return rbegin();
    }
    inline rope::const_reverse_iterator rope::crend() const noexcept
    {
        return rend();
    }

    inline bool rope::empty() const noexcept { return rope_.empty(); }

    inline rope_view::size_type rope::storage_bytes() const noexcept
    {
        return rope_.size();
    }

    inline rope_view::size_type rope::distance() const noexcept
    {
        return std::distance(begin(), end());
    }

    inline bool rope::equal_root(rope rhs) const noexcept
    {
        return rope_.equal_root(rhs.rope_);
    }

    inline void rope::clear() noexcept { rope_.clear(); }

    inline rope::const_iterator
    rope::insert(const_iterator at, char const * c_str)
    {
        return insert_impl(at, string(c_str), false);
    }

    inline rope::const_iterator rope::insert(const_iterator at, rope_view rv)
    {
        // TODO: It would be better if we shared nodes with copied nodes from
        // rv.  Same for unencoded_rope probably.
        return insert_impl(
            at, string(rv.begin().base().base(), rv.end().base().base()), true);
    }

    inline rope::const_iterator rope::insert(const_iterator at, string && s)
    {
        return insert_impl(at, std::move(s), false);
    }

    inline rope::const_iterator rope::insert(const_iterator at, string_view sv)
    {
        return insert_impl(at, string(sv), false);
    }

    inline rope::const_iterator
    rope::insert(const_iterator at, repeated_string_view rsv)
    {
        bool const rsv_null_terminated =
            !rsv.view().empty() && rsv.view().end()[-1] == '\0';
        if (rsv_null_terminated)
            rsv = repeat(rsv.view()(0, -1), rsv.count());
        return insert_impl(at, string(rsv.begin(), rsv.end()), false);
    }

    template<typename CharRange>
    auto rope::insert(const_iterator at, CharRange const & r)
        -> detail::rng_alg_ret_t<rope::const_iterator, CharRange>
    {
        return insert_impl(at, string(r), false);
    }

    template<typename CharIter>
    auto rope::insert(const_iterator at, CharIter first, CharIter last)
        -> detail::char_iter_ret_t<rope::const_iterator, CharIter>
    {
        return insert_impl(at, string(first, last), false);
    }

    inline rope & rope::erase(rope_view rv)
    {
        rope_view const this_rv(*this);
        auto const this_rv_first = this_rv.begin().base().base();
        auto const this_rv_last = this_rv.end().base().base();

        auto const rv_first = rv.begin().base().base();
        auto const rv_last = rv.end().base().base();

        using mutable_utf32_view_iter =
            utf8::to_utf32_iterator<detail::const_rope_view_iterator>;

        mutable_utf32_view_iter first(this_rv_first, rv_first, this_rv_last);
        first = find_if_backward(
            mutable_utf32_view_iter(this_rv_first, this_rv_first, this_rv_last),
            first,
            detail::stable_fcc_code_point);
        mutable_utf32_view_iter last(this_rv_first, rv_last, this_rv_last);

        last = find_if(
            last,
            mutable_utf32_view_iter(this_rv_last, this_rv_last, this_rv_last),
            detail::stable_fcc_code_point);

        string str(first.base(), rv_first);
        str.insert(str.end(), rv_last, last.base());

        rope_.replace(
            rope_(first.base() - this_rv_first, last.base() - this_rv_first),
            std::move(str));

        BOOST_TEXT_CHECK_ROPE_NORMALIZATION();

        return *this;
    }

    inline rope::const_iterator
    rope::erase(const_iterator first, const_iterator last)
    {
        int const offset = first.base().base() - rope_.begin();
        erase(rope_view(first, last));
        return make_iter(rope_.begin(), rope_.begin() + offset, rope_.end());
    }

    inline rope & rope::replace(rope_view old_substr, rope_view new_substr)
    {
        return replace_impl(
            old_substr,
            string(
                new_substr.begin().base().base(),
                new_substr.end().base().base()),
            true);
    }

    inline rope & rope::replace(rope_view old_substr, string_view new_substr)
    {
        return replace_impl(old_substr, string(new_substr), false);
    }

    inline rope &
    rope::replace(rope_view old_substr, repeated_string_view new_substr)
    {
        return replace_impl(old_substr, string(new_substr), false);
    }

    template<typename CharRange>
    auto rope::replace(rope_view old_substr, CharRange const & r)
        -> detail::rng_alg_ret_t<rope &, CharRange>
    {
        using std::begin;
        using std::end;
        replace(old_substr, begin(r), end(r));
        return *this;
    }

    template<typename CharIter>
    auto rope::replace(rope_view old_substr, CharIter first, CharIter last)
        -> detail::char_iter_ret_t<rope &, CharIter>
    {
        return replace_impl(old_substr, string(first, last), false);
    }

    inline void rope::swap(rope & rhs) noexcept { rope_.swap(rhs.rope_); }

    inline unencoded_rope rope::extract() && noexcept
    {
        return std::move(rope_);
    }

    inline void rope::replace(unencoded_rope && ur) noexcept
    {
        rope_ = std::move(ur);
    }

    inline rope & rope::operator+=(char const * c_str)
    {
        return *this += string_view(c_str);
    }

    inline rope & rope::operator+=(rope_view rv)
    {
        insert(end(), rv);
        return *this;
    }

    inline rope & rope::operator+=(string_view sv)
    {
        insert(end(), sv);
        return *this;
    }

    inline rope & rope::operator+=(repeated_string_view rsv)
    {
        insert(end(), rsv);
        return *this;
    }

    template<typename CharRange>
    auto rope::operator+=(CharRange const & r)
        -> detail::rng_alg_ret_t<rope &, CharRange>
    {
        insert(end(), r);
        return *this;
    }

    inline rope::const_iterator rope::make_iter(
        detail::const_rope_iterator first,
        detail::const_rope_iterator it,
        detail::const_rope_iterator last) noexcept
    {
        return const_iterator{
            utf8::to_utf32_iterator<detail::const_rope_iterator>{
                first, first, last},
            utf8::to_utf32_iterator<detail::const_rope_iterator>{
                first, it, last},
            utf8::to_utf32_iterator<detail::const_rope_iterator>{
                first, last, last}};
    }

    inline rope::mutable_utf32_iter
    rope::prev_stable_cp(mutable_utf32_iter last) noexcept
    {
        auto const first =
            mutable_utf32_iter(rope_.begin(), rope_.begin(), rope_.end());
        auto const it =
            find_if_backward(first, last, detail::stable_fcc_code_point);
        if (it == last)
            return first;
        return it;
    }

    inline rope::mutable_utf32_iter
    rope::next_stable_cp(mutable_utf32_iter first) noexcept
    {
        auto const last =
            mutable_utf32_iter(rope_.begin(), rope_.end(), rope_.end());
        auto const it = find_if(first, last, detail::stable_fcc_code_point);
        return it;
    }

    inline rope::const_iterator
    rope::insert_impl(const_iterator at, string str, bool str_normalized)
    {
        int const offset = at.base().base() - rope_.begin();
        replace_impl(rope_view(at, at), std::move(str), str_normalized);
        return make_iter(rope_.begin(), rope_.begin() + offset, rope_.end());
    }

    inline rope &
    rope::replace_impl(rope_view old_substr, string str, bool str_normalized)
    {
        rope_view const this_rv(*this);

        auto const rope_first =
            rope_.begin() +
            (old_substr.begin().base().base() - this_rv.begin().base().base());
        auto const rope_last = rope_.begin() + (old_substr.end().base().base() -
                                                this_rv.begin().base().base());

        mutable_utf32_iter first(rope_.begin(), rope_first, rope_.end());
        first = prev_stable_cp(first);
        mutable_utf32_iter last(rope_.begin(), rope_last, rope_.end());
        last = next_stable_cp(last);

        str.insert(str.begin(), first.base(), rope_first);
        auto const initial_str_end_offset = str.size();
        str.insert(str.end(), rope_last, last.base());

        if (str_normalized) {
            using utf32_string_iter = utf8::to_utf32_iterator<char const *>;

            if (last.base() != rope_last) {
                auto const str_first = str.begin() + initial_str_end_offset;
                auto const str_last =
                    find_if_backward(
                        utf32_string_iter(str.begin(), str.begin(), str.end()),
                        utf32_string_iter(str.begin(), str_first, str.end()),
                        detail::stable_fcc_code_point)
                        .base();
                auto const suffix = str(str_last - str.end()); // negative index
                container::small_vector<char, 128> buf;
                normalize_to_fcc(
                    utf32_range(suffix.begin(), suffix.end()),
                    utf8::from_utf32_back_inserter(buf));
                str.replace(suffix, string_view(buf));
            }

            if (first.base() != rope_first) {
                auto const str_first =
                    str.begin() + (rope_first - first.base());
                auto const str_last =
                    find_if(
                        utf32_string_iter(str.begin(), str_first, str.end()),
                        utf32_string_iter(str.begin(), str.end(), str.end()),
                        detail::stable_fcc_code_point)
                        .base();
                auto const prefix = str(str_last - str.begin());
                container::small_vector<char, 128> buf;
                normalize_to_fcc(
                    utf32_range(prefix.begin(), prefix.end()),
                    utf8::from_utf32_back_inserter(buf));
                str.replace(prefix, string_view(buf));
            }
        } else {
            normalize_to_fcc(str);
        }

        rope_.replace(
            rope_(first.base() - rope_.begin(), last.base() - rope_.begin()),
            std::move(str));

        BOOST_TEXT_CHECK_ROPE_NORMALIZATION();

        return *this;
    }

}}

#endif

namespace boost { namespace text {

    inline bool operator==(text const & lhs, rope_view rhs) noexcept
    {
        return algorithm::equal(
            lhs.begin().base().base(),
            lhs.end().base().base(),
            rhs.begin().base().base(),
            rhs.end().base().base());
    }
    inline bool operator==(rope_view lhs, text const & rhs) noexcept
    {
        return rhs == lhs;
    }

    inline bool operator!=(text const & lhs, rope_view rhs) noexcept
    {
        return !(lhs == rhs);
    }
    inline bool operator!=(rope_view lhs, text const & rhs) noexcept
    {
        return !(lhs == rhs);
    }

    inline bool operator==(text const & lhs, rope rhs) noexcept
    {
        return algorithm::equal(
            lhs.begin().base().base(),
            lhs.end().base().base(),
            rhs.begin().base().base(),
            rhs.end().base().base());
    }
    inline bool operator==(rope lhs, text const & rhs) noexcept
    {
        return rhs == lhs;
    }

    inline bool operator!=(text const & lhs, rope rhs) noexcept
    {
        return !(lhs == rhs);
    }
    inline bool operator!=(rope lhs, text const & rhs) noexcept
    {
        return !(lhs == rhs);
    }

    inline bool operator==(rope const & lhs, rope_view rhs) noexcept
    {
        return algorithm::equal(
            lhs.begin().base().base(),
            lhs.end().base().base(),
            rhs.begin().base().base(),
            rhs.end().base().base());
    }
    inline bool operator==(rope_view lhs, rope const & rhs) noexcept
    {
        return rhs == lhs;
    }

    inline bool operator!=(rope const & lhs, rope_view rhs) noexcept
    {
        return !(lhs == rhs);
    }
    inline bool operator!=(rope_view lhs, rope const & rhs) noexcept
    {
        return !(lhs == rhs);
    }

    inline bool operator==(rope const & lhs, rope const & rhs) noexcept
    {
        return algorithm::equal(
            lhs.begin().base().base(),
            lhs.end().base().base(),
            rhs.begin().base().base(),
            rhs.end().base().base());
    }

    inline bool operator!=(rope const & lhs, rope const & rhs) noexcept
    {
        return !(lhs == rhs);
    }

    /** Creates a new rope object that is the concatenation of r and c_str. */
    inline rope operator+(rope t, char const * c_str) { return t += c_str; }

    /** Creates a new rope object that is the concatenation of c_str and r. */
    inline rope operator+(char const * c_str, rope const & r)
    {
        return rope(c_str) += r;
    }

    /** Creates a new rope object that is the concatenation of r and r2. */
    inline rope operator+(rope r, rope const & r2) { return r += r2; }

    /** Creates a new rope object that is the concatenation of r and rv. */
    inline rope operator+(rope r, rope_view rv) { return r += rv; }

    /** Creates a new rope object that is the concatenation of rv and r. */
    inline rope operator+(rope_view rv, rope const & r)
    {
        return rope(rv) += r;
    }

    /** Creates a new rope object that is the concatenation of r and rsv. */
    inline rope operator+(rope r, repeated_string_view rsv) { return r += rsv; }

    /** Creates a new rope object that is the concatenation of rsv and r. */
    inline rope operator+(repeated_string_view rsv, rope const & r)
    {
        return rope(rsv) += r;
    }

#ifdef BOOST_TEXT_DOXYGEN

    /** Creates a new rope object that is the concatenation of r and r2.

        This function only participates in overload resolution if CharRange
        models the CharRange concept.

        \throw std::invalid_argument if the ends of the range are not valid
        UTF-8. */
    template<typename CharRange>
    rope operator+(rope r, CharRange const & r2);

    /** Creates a new rope object that is the concatenation of r and r2.

        This function only participates in overload resolution if CharRange
        models the CharRange concept.

        \throw std::invalid_argument if the ends of the range are not valid
        UTF-8. */
    template<typename CharRange>
    rope operator+(CharRange const & r, rope const & r2);

#else

    template<typename CharRange>
    auto operator+(rope r, CharRange const & r2)
        -> detail::rng_alg_ret_t<rope, CharRange>
    {
        return r += r2;
    }

    template<typename CharRange>
    auto operator+(CharRange const & r, rope const & r2)
        -> detail::rng_alg_ret_t<rope, CharRange>
    {
        return rope(r) += r2;
    }

#endif

    /** Creates a new rope object that is the concatenation of t and rv. */
    inline text & operator+=(text & t, rope_view rv)
    {
        t.insert(t.end(), rv.begin().base().base(), rv.end().base().base());
        return t;
    }

    /** Creates a new rope object that is the concatenation of t and rv. */
    inline rope operator+(text t, rope_view rv)
    {
        return rope(std::move(t)) += rv;
    }

    /** Creates a new rope object that is the concatenation of r and t. */
    inline rope operator+(rope_view rv, text const & t)
    {
        return rope(rv) += t;
    }

    /** Creates a new rope object that is the concatenation of t and r. */
    inline text & operator+=(text & t, rope const & r)
    {
        t.insert(t.end(), r.begin().base().base(), r.end().base().base());
        return t;
    }

    /** Creates a new rope object that is the concatenation of t and r. */
    inline rope operator+(text t, rope const & r)
    {
        return rope(std::move(t)) += r;
    }

    /** Creates a new rope object that is the concatenation of r and t. */
    inline rope operator+(rope r, text const & t) { return r += t; }


    inline text::iterator text::insert(iterator at, rope_view rv)
    {
        return insert_impl(
            at, rv.begin().base().base(), rv.end().base().base(), true);
    }

    inline text & text::replace(text_view old_substr, rope_view new_substr)
    {
        return replace_impl(
            old_substr,
            new_substr.begin().base().base(),
            new_substr.end().base().base(),
            true);
    }

}}

#endif
