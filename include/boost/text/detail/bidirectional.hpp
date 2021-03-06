// Warning! This file is autogenerated.
#ifndef BOOST_TEXT_DETAIL_BIDIRECTIONAL_HPP
#define BOOST_TEXT_DETAIL_BIDIRECTIONAL_HPP

#include <boost/text/bidirectional_fwd.hpp>

#include <algorithm>
#include <array>

#include <stdint.h>


namespace boost { namespace text { namespace detail {

enum class bidi_bracket_type {
    open,
    close
};

struct bidi_bracket_data
{
    explicit operator bool() const { return cp_ != 0; }

    uint32_t cp_;
    uint32_t paired_bracket_;
    bidi_bracket_type type_;
};

inline bidi_bracket_data bidi_bracket(uint32_t cp) noexcept
{
    static std::array<bidi_bracket_data, 120> const brackets = {{
        {0x0028, 0x0029, bidi_bracket_type::open},
        {0x0029, 0x0028, bidi_bracket_type::close},
        {0x005B, 0x005D, bidi_bracket_type::open},
        {0x005D, 0x005B, bidi_bracket_type::close},
        {0x007B, 0x007D, bidi_bracket_type::open},
        {0x007D, 0x007B, bidi_bracket_type::close},
        {0x0F3A, 0x0F3B, bidi_bracket_type::open},
        {0x0F3B, 0x0F3A, bidi_bracket_type::close},
        {0x0F3C, 0x0F3D, bidi_bracket_type::open},
        {0x0F3D, 0x0F3C, bidi_bracket_type::close},
        {0x169B, 0x169C, bidi_bracket_type::open},
        {0x169C, 0x169B, bidi_bracket_type::close},
        {0x2045, 0x2046, bidi_bracket_type::open},
        {0x2046, 0x2045, bidi_bracket_type::close},
        {0x207D, 0x207E, bidi_bracket_type::open},
        {0x207E, 0x207D, bidi_bracket_type::close},
        {0x208D, 0x208E, bidi_bracket_type::open},
        {0x208E, 0x208D, bidi_bracket_type::close},
        {0x2308, 0x2309, bidi_bracket_type::open},
        {0x2309, 0x2308, bidi_bracket_type::close},
        {0x230A, 0x230B, bidi_bracket_type::open},
        {0x230B, 0x230A, bidi_bracket_type::close},
        {0x2329, 0x232A, bidi_bracket_type::open},
        {0x232A, 0x2329, bidi_bracket_type::close},
        {0x2768, 0x2769, bidi_bracket_type::open},
        {0x2769, 0x2768, bidi_bracket_type::close},
        {0x276A, 0x276B, bidi_bracket_type::open},
        {0x276B, 0x276A, bidi_bracket_type::close},
        {0x276C, 0x276D, bidi_bracket_type::open},
        {0x276D, 0x276C, bidi_bracket_type::close},
        {0x276E, 0x276F, bidi_bracket_type::open},
        {0x276F, 0x276E, bidi_bracket_type::close},
        {0x2770, 0x2771, bidi_bracket_type::open},
        {0x2771, 0x2770, bidi_bracket_type::close},
        {0x2772, 0x2773, bidi_bracket_type::open},
        {0x2773, 0x2772, bidi_bracket_type::close},
        {0x2774, 0x2775, bidi_bracket_type::open},
        {0x2775, 0x2774, bidi_bracket_type::close},
        {0x27C5, 0x27C6, bidi_bracket_type::open},
        {0x27C6, 0x27C5, bidi_bracket_type::close},
        {0x27E6, 0x27E7, bidi_bracket_type::open},
        {0x27E7, 0x27E6, bidi_bracket_type::close},
        {0x27E8, 0x27E9, bidi_bracket_type::open},
        {0x27E9, 0x27E8, bidi_bracket_type::close},
        {0x27EA, 0x27EB, bidi_bracket_type::open},
        {0x27EB, 0x27EA, bidi_bracket_type::close},
        {0x27EC, 0x27ED, bidi_bracket_type::open},
        {0x27ED, 0x27EC, bidi_bracket_type::close},
        {0x27EE, 0x27EF, bidi_bracket_type::open},
        {0x27EF, 0x27EE, bidi_bracket_type::close},
        {0x2983, 0x2984, bidi_bracket_type::open},
        {0x2984, 0x2983, bidi_bracket_type::close},
        {0x2985, 0x2986, bidi_bracket_type::open},
        {0x2986, 0x2985, bidi_bracket_type::close},
        {0x2987, 0x2988, bidi_bracket_type::open},
        {0x2988, 0x2987, bidi_bracket_type::close},
        {0x2989, 0x298A, bidi_bracket_type::open},
        {0x298A, 0x2989, bidi_bracket_type::close},
        {0x298B, 0x298C, bidi_bracket_type::open},
        {0x298C, 0x298B, bidi_bracket_type::close},
        {0x298D, 0x2990, bidi_bracket_type::open},
        {0x298E, 0x298F, bidi_bracket_type::close},
        {0x298F, 0x298E, bidi_bracket_type::open},
        {0x2990, 0x298D, bidi_bracket_type::close},
        {0x2991, 0x2992, bidi_bracket_type::open},
        {0x2992, 0x2991, bidi_bracket_type::close},
        {0x2993, 0x2994, bidi_bracket_type::open},
        {0x2994, 0x2993, bidi_bracket_type::close},
        {0x2995, 0x2996, bidi_bracket_type::open},
        {0x2996, 0x2995, bidi_bracket_type::close},
        {0x2997, 0x2998, bidi_bracket_type::open},
        {0x2998, 0x2997, bidi_bracket_type::close},
        {0x29D8, 0x29D9, bidi_bracket_type::open},
        {0x29D9, 0x29D8, bidi_bracket_type::close},
        {0x29DA, 0x29DB, bidi_bracket_type::open},
        {0x29DB, 0x29DA, bidi_bracket_type::close},
        {0x29FC, 0x29FD, bidi_bracket_type::open},
        {0x29FD, 0x29FC, bidi_bracket_type::close},
        {0x2E22, 0x2E23, bidi_bracket_type::open},
        {0x2E23, 0x2E22, bidi_bracket_type::close},
        {0x2E24, 0x2E25, bidi_bracket_type::open},
        {0x2E25, 0x2E24, bidi_bracket_type::close},
        {0x2E26, 0x2E27, bidi_bracket_type::open},
        {0x2E27, 0x2E26, bidi_bracket_type::close},
        {0x2E28, 0x2E29, bidi_bracket_type::open},
        {0x2E29, 0x2E28, bidi_bracket_type::close},
        {0x3008, 0x3009, bidi_bracket_type::open},
        {0x3009, 0x3008, bidi_bracket_type::close},
        {0x300A, 0x300B, bidi_bracket_type::open},
        {0x300B, 0x300A, bidi_bracket_type::close},
        {0x300C, 0x300D, bidi_bracket_type::open},
        {0x300D, 0x300C, bidi_bracket_type::close},
        {0x300E, 0x300F, bidi_bracket_type::open},
        {0x300F, 0x300E, bidi_bracket_type::close},
        {0x3010, 0x3011, bidi_bracket_type::open},
        {0x3011, 0x3010, bidi_bracket_type::close},
        {0x3014, 0x3015, bidi_bracket_type::open},
        {0x3015, 0x3014, bidi_bracket_type::close},
        {0x3016, 0x3017, bidi_bracket_type::open},
        {0x3017, 0x3016, bidi_bracket_type::close},
        {0x3018, 0x3019, bidi_bracket_type::open},
        {0x3019, 0x3018, bidi_bracket_type::close},
        {0x301A, 0x301B, bidi_bracket_type::open},
        {0x301B, 0x301A, bidi_bracket_type::close},
        {0xFE59, 0xFE5A, bidi_bracket_type::open},
        {0xFE5A, 0xFE59, bidi_bracket_type::close},
        {0xFE5B, 0xFE5C, bidi_bracket_type::open},
        {0xFE5C, 0xFE5B, bidi_bracket_type::close},
        {0xFE5D, 0xFE5E, bidi_bracket_type::open},
        {0xFE5E, 0xFE5D, bidi_bracket_type::close},
        {0xFF08, 0xFF09, bidi_bracket_type::open},
        {0xFF09, 0xFF08, bidi_bracket_type::close},
        {0xFF3B, 0xFF3D, bidi_bracket_type::open},
        {0xFF3D, 0xFF3B, bidi_bracket_type::close},
        {0xFF5B, 0xFF5D, bidi_bracket_type::open},
        {0xFF5D, 0xFF5B, bidi_bracket_type::close},
        {0xFF5F, 0xFF60, bidi_bracket_type::open},
        {0xFF60, 0xFF5F, bidi_bracket_type::close},
        {0xFF62, 0xFF63, bidi_bracket_type::open},
        {0xFF63, 0xFF62, bidi_bracket_type::close},
    }};

    auto const it = std::lower_bound(
        brackets.begin(), brackets.end(), bidi_bracket_data{cp},
        [](bidi_bracket_data lhs, bidi_bracket_data rhs){
            return lhs.cp_ < rhs.cp_;
        });
    if (it == brackets.end() || it->cp_ != cp)
        return bidi_bracket_data{0};
    return *it;
}

struct bidi_mirroring_data
{
    uint32_t cp_;
    int index_; // within bidi_mirroreds()
};

inline int bidi_mirroring(uint32_t cp) noexcept
{
    static std::array<bidi_mirroring_data, 364> const mirrorings = {{
        {0x0028, 1},
        {0x0029, 0},
        {0x003C, 3},
        {0x003E, 2},
        {0x005B, 5},
        {0x005D, 4},
        {0x007B, 7},
        {0x007D, 6},
        {0x00AB, 9},
        {0x00BB, 8},
        {0x0F3A, 11},
        {0x0F3B, 10},
        {0x0F3C, 13},
        {0x0F3D, 12},
        {0x169B, 15},
        {0x169C, 14},
        {0x2039, 17},
        {0x203A, 16},
        {0x2045, 19},
        {0x2046, 18},
        {0x207D, 21},
        {0x207E, 20},
        {0x208D, 23},
        {0x208E, 22},
        {0x2208, 27},
        {0x2209, 28},
        {0x220A, 29},
        {0x220B, 24},
        {0x220C, 25},
        {0x220D, 26},
        {0x2215, 221},
        {0x223C, 32},
        {0x223D, 31},
        {0x2243, 99},
        {0x2252, 35},
        {0x2253, 34},
        {0x2254, 37},
        {0x2255, 36},
        {0x2264, 39},
        {0x2265, 38},
        {0x2266, 41},
        {0x2267, 40},
        {0x2268, 43},
        {0x2269, 42},
        {0x226A, 45},
        {0x226B, 44},
        {0x226E, 47},
        {0x226F, 46},
        {0x2270, 49},
        {0x2271, 48},
        {0x2272, 51},
        {0x2273, 50},
        {0x2274, 53},
        {0x2275, 52},
        {0x2276, 55},
        {0x2277, 54},
        {0x2278, 57},
        {0x2279, 56},
        {0x227A, 59},
        {0x227B, 58},
        {0x227C, 61},
        {0x227D, 60},
        {0x227E, 63},
        {0x227F, 62},
        {0x2280, 65},
        {0x2281, 64},
        {0x2282, 67},
        {0x2283, 66},
        {0x2284, 69},
        {0x2285, 68},
        {0x2286, 71},
        {0x2287, 70},
        {0x2288, 73},
        {0x2289, 72},
        {0x228A, 75},
        {0x228B, 74},
        {0x228F, 77},
        {0x2290, 76},
        {0x2291, 79},
        {0x2292, 78},
        {0x2298, 206},
        {0x22A2, 82},
        {0x22A3, 81},
        {0x22A6, 296},
        {0x22A8, 298},
        {0x22A9, 297},
        {0x22AB, 299},
        {0x22B0, 88},
        {0x22B1, 87},
        {0x22B2, 90},
        {0x22B3, 89},
        {0x22B4, 92},
        {0x22B5, 91},
        {0x22B6, 94},
        {0x22B7, 93},
        {0x22C9, 96},
        {0x22CA, 95},
        {0x22CB, 98},
        {0x22CC, 97},
        {0x22CD, 33},
        {0x22D0, 101},
        {0x22D1, 100},
        {0x22D6, 103},
        {0x22D7, 102},
        {0x22D8, 105},
        {0x22D9, 104},
        {0x22DA, 107},
        {0x22DB, 106},
        {0x22DC, 109},
        {0x22DD, 108},
        {0x22DE, 111},
        {0x22DF, 110},
        {0x22E0, 113},
        {0x22E1, 112},
        {0x22E2, 115},
        {0x22E3, 114},
        {0x22E4, 117},
        {0x22E5, 116},
        {0x22E6, 119},
        {0x22E7, 118},
        {0x22E8, 121},
        {0x22E9, 120},
        {0x22EA, 123},
        {0x22EB, 122},
        {0x22EC, 125},
        {0x22ED, 124},
        {0x22F0, 127},
        {0x22F1, 126},
        {0x22F2, 133},
        {0x22F3, 134},
        {0x22F4, 135},
        {0x22F6, 136},
        {0x22F7, 137},
        {0x22FA, 128},
        {0x22FB, 129},
        {0x22FC, 130},
        {0x22FD, 131},
        {0x22FE, 132},
        {0x2308, 139},
        {0x2309, 138},
        {0x230A, 141},
        {0x230B, 140},
        {0x2329, 143},
        {0x232A, 142},
        {0x2768, 145},
        {0x2769, 144},
        {0x276A, 147},
        {0x276B, 146},
        {0x276C, 149},
        {0x276D, 148},
        {0x276E, 151},
        {0x276F, 150},
        {0x2770, 153},
        {0x2771, 152},
        {0x2772, 155},
        {0x2773, 154},
        {0x2774, 157},
        {0x2775, 156},
        {0x27C3, 159},
        {0x27C4, 158},
        {0x27C5, 161},
        {0x27C6, 160},
        {0x27C8, 163},
        {0x27C9, 162},
        {0x27CB, 165},
        {0x27CD, 164},
        {0x27D5, 167},
        {0x27D6, 166},
        {0x27DD, 169},
        {0x27DE, 168},
        {0x27E2, 171},
        {0x27E3, 170},
        {0x27E4, 173},
        {0x27E5, 172},
        {0x27E6, 175},
        {0x27E7, 174},
        {0x27E8, 177},
        {0x27E9, 176},
        {0x27EA, 179},
        {0x27EB, 178},
        {0x27EC, 181},
        {0x27ED, 180},
        {0x27EE, 183},
        {0x27EF, 182},
        {0x2983, 185},
        {0x2984, 184},
        {0x2985, 187},
        {0x2986, 186},
        {0x2987, 189},
        {0x2988, 188},
        {0x2989, 191},
        {0x298A, 190},
        {0x298B, 193},
        {0x298C, 192},
        {0x298D, 197},
        {0x298E, 196},
        {0x298F, 195},
        {0x2990, 194},
        {0x2991, 199},
        {0x2992, 198},
        {0x2993, 201},
        {0x2994, 200},
        {0x2995, 203},
        {0x2996, 202},
        {0x2997, 205},
        {0x2998, 204},
        {0x29B8, 80},
        {0x29C0, 208},
        {0x29C1, 207},
        {0x29C4, 210},
        {0x29C5, 209},
        {0x29CF, 212},
        {0x29D0, 211},
        {0x29D1, 214},
        {0x29D2, 213},
        {0x29D4, 216},
        {0x29D5, 215},
        {0x29D8, 218},
        {0x29D9, 217},
        {0x29DA, 220},
        {0x29DB, 219},
        {0x29F5, 30},
        {0x29F8, 223},
        {0x29F9, 222},
        {0x29FC, 225},
        {0x29FD, 224},
        {0x2A2B, 227},
        {0x2A2C, 226},
        {0x2A2D, 229},
        {0x2A2E, 228},
        {0x2A34, 231},
        {0x2A35, 230},
        {0x2A3C, 233},
        {0x2A3D, 232},
        {0x2A64, 235},
        {0x2A65, 234},
        {0x2A79, 237},
        {0x2A7A, 236},
        {0x2A7D, 239},
        {0x2A7E, 238},
        {0x2A7F, 241},
        {0x2A80, 240},
        {0x2A81, 243},
        {0x2A82, 242},
        {0x2A83, 245},
        {0x2A84, 244},
        {0x2A8B, 247},
        {0x2A8C, 246},
        {0x2A91, 249},
        {0x2A92, 248},
        {0x2A93, 251},
        {0x2A94, 250},
        {0x2A95, 253},
        {0x2A96, 252},
        {0x2A97, 255},
        {0x2A98, 254},
        {0x2A99, 257},
        {0x2A9A, 256},
        {0x2A9B, 259},
        {0x2A9C, 258},
        {0x2AA1, 261},
        {0x2AA2, 260},
        {0x2AA6, 263},
        {0x2AA7, 262},
        {0x2AA8, 265},
        {0x2AA9, 264},
        {0x2AAA, 267},
        {0x2AAB, 266},
        {0x2AAC, 269},
        {0x2AAD, 268},
        {0x2AAF, 271},
        {0x2AB0, 270},
        {0x2AB3, 273},
        {0x2AB4, 272},
        {0x2ABB, 275},
        {0x2ABC, 274},
        {0x2ABD, 277},
        {0x2ABE, 276},
        {0x2ABF, 279},
        {0x2AC0, 278},
        {0x2AC1, 281},
        {0x2AC2, 280},
        {0x2AC3, 283},
        {0x2AC4, 282},
        {0x2AC5, 285},
        {0x2AC6, 284},
        {0x2ACD, 287},
        {0x2ACE, 286},
        {0x2ACF, 289},
        {0x2AD0, 288},
        {0x2AD1, 291},
        {0x2AD2, 290},
        {0x2AD3, 293},
        {0x2AD4, 292},
        {0x2AD5, 295},
        {0x2AD6, 294},
        {0x2ADE, 83},
        {0x2AE3, 85},
        {0x2AE4, 84},
        {0x2AE5, 86},
        {0x2AEC, 301},
        {0x2AED, 300},
        {0x2AF7, 303},
        {0x2AF8, 302},
        {0x2AF9, 305},
        {0x2AFA, 304},
        {0x2E02, 307},
        {0x2E03, 306},
        {0x2E04, 309},
        {0x2E05, 308},
        {0x2E09, 311},
        {0x2E0A, 310},
        {0x2E0C, 313},
        {0x2E0D, 312},
        {0x2E1C, 315},
        {0x2E1D, 314},
        {0x2E20, 317},
        {0x2E21, 316},
        {0x2E22, 319},
        {0x2E23, 318},
        {0x2E24, 321},
        {0x2E25, 320},
        {0x2E26, 323},
        {0x2E27, 322},
        {0x2E28, 325},
        {0x2E29, 324},
        {0x3008, 327},
        {0x3009, 326},
        {0x300A, 329},
        {0x300B, 328},
        {0x300C, 331},
        {0x300D, 330},
        {0x300E, 333},
        {0x300F, 332},
        {0x3010, 335},
        {0x3011, 334},
        {0x3014, 337},
        {0x3015, 336},
        {0x3016, 339},
        {0x3017, 338},
        {0x3018, 341},
        {0x3019, 340},
        {0x301A, 343},
        {0x301B, 342},
        {0xFE59, 345},
        {0xFE5A, 344},
        {0xFE5B, 347},
        {0xFE5C, 346},
        {0xFE5D, 349},
        {0xFE5E, 348},
        {0xFE64, 351},
        {0xFE65, 350},
        {0xFF08, 353},
        {0xFF09, 352},
        {0xFF1C, 355},
        {0xFF1E, 354},
        {0xFF3B, 357},
        {0xFF3D, 356},
        {0xFF5B, 359},
        {0xFF5D, 358},
        {0xFF5F, 361},
        {0xFF60, 360},
        {0xFF62, 363},
        {0xFF63, 362},
    }};

    auto const it = std::lower_bound(
        mirrorings.begin(), mirrorings.end(), bidi_mirroring_data{cp},
        [](bidi_mirroring_data lhs, bidi_mirroring_data rhs){
            return lhs.cp_ < rhs.cp_;
        });
    if (it == mirrorings.end() || it->cp_ != cp)
        return -1;
    return it->index_;
}

inline std::array<uint32_t, 364> const & bidi_mirroreds() noexcept
{
    static std::array<uint32_t, 364> const retval = {{
        0x0028,
        0x0029,
        0x003C,
        0x003E,
        0x005B,
        0x005D,
        0x007B,
        0x007D,
        0x00AB,
        0x00BB,
        0x0F3A,
        0x0F3B,
        0x0F3C,
        0x0F3D,
        0x169B,
        0x169C,
        0x2039,
        0x203A,
        0x2045,
        0x2046,
        0x207D,
        0x207E,
        0x208D,
        0x208E,
        0x2208,
        0x2209,
        0x220A,
        0x220B,
        0x220C,
        0x220D,
        0x2215,
        0x223C,
        0x223D,
        0x2243,
        0x2252,
        0x2253,
        0x2254,
        0x2255,
        0x2264,
        0x2265,
        0x2266,
        0x2267,
        0x2268,
        0x2269,
        0x226A,
        0x226B,
        0x226E,
        0x226F,
        0x2270,
        0x2271,
        0x2272,
        0x2273,
        0x2274,
        0x2275,
        0x2276,
        0x2277,
        0x2278,
        0x2279,
        0x227A,
        0x227B,
        0x227C,
        0x227D,
        0x227E,
        0x227F,
        0x2280,
        0x2281,
        0x2282,
        0x2283,
        0x2284,
        0x2285,
        0x2286,
        0x2287,
        0x2288,
        0x2289,
        0x228A,
        0x228B,
        0x228F,
        0x2290,
        0x2291,
        0x2292,
        0x2298,
        0x22A2,
        0x22A3,
        0x22A6,
        0x22A8,
        0x22A9,
        0x22AB,
        0x22B0,
        0x22B1,
        0x22B2,
        0x22B3,
        0x22B4,
        0x22B5,
        0x22B6,
        0x22B7,
        0x22C9,
        0x22CA,
        0x22CB,
        0x22CC,
        0x22CD,
        0x22D0,
        0x22D1,
        0x22D6,
        0x22D7,
        0x22D8,
        0x22D9,
        0x22DA,
        0x22DB,
        0x22DC,
        0x22DD,
        0x22DE,
        0x22DF,
        0x22E0,
        0x22E1,
        0x22E2,
        0x22E3,
        0x22E4,
        0x22E5,
        0x22E6,
        0x22E7,
        0x22E8,
        0x22E9,
        0x22EA,
        0x22EB,
        0x22EC,
        0x22ED,
        0x22F0,
        0x22F1,
        0x22F2,
        0x22F3,
        0x22F4,
        0x22F6,
        0x22F7,
        0x22FA,
        0x22FB,
        0x22FC,
        0x22FD,
        0x22FE,
        0x2308,
        0x2309,
        0x230A,
        0x230B,
        0x2329,
        0x232A,
        0x2768,
        0x2769,
        0x276A,
        0x276B,
        0x276C,
        0x276D,
        0x276E,
        0x276F,
        0x2770,
        0x2771,
        0x2772,
        0x2773,
        0x2774,
        0x2775,
        0x27C3,
        0x27C4,
        0x27C5,
        0x27C6,
        0x27C8,
        0x27C9,
        0x27CB,
        0x27CD,
        0x27D5,
        0x27D6,
        0x27DD,
        0x27DE,
        0x27E2,
        0x27E3,
        0x27E4,
        0x27E5,
        0x27E6,
        0x27E7,
        0x27E8,
        0x27E9,
        0x27EA,
        0x27EB,
        0x27EC,
        0x27ED,
        0x27EE,
        0x27EF,
        0x2983,
        0x2984,
        0x2985,
        0x2986,
        0x2987,
        0x2988,
        0x2989,
        0x298A,
        0x298B,
        0x298C,
        0x298D,
        0x298E,
        0x298F,
        0x2990,
        0x2991,
        0x2992,
        0x2993,
        0x2994,
        0x2995,
        0x2996,
        0x2997,
        0x2998,
        0x29B8,
        0x29C0,
        0x29C1,
        0x29C4,
        0x29C5,
        0x29CF,
        0x29D0,
        0x29D1,
        0x29D2,
        0x29D4,
        0x29D5,
        0x29D8,
        0x29D9,
        0x29DA,
        0x29DB,
        0x29F5,
        0x29F8,
        0x29F9,
        0x29FC,
        0x29FD,
        0x2A2B,
        0x2A2C,
        0x2A2D,
        0x2A2E,
        0x2A34,
        0x2A35,
        0x2A3C,
        0x2A3D,
        0x2A64,
        0x2A65,
        0x2A79,
        0x2A7A,
        0x2A7D,
        0x2A7E,
        0x2A7F,
        0x2A80,
        0x2A81,
        0x2A82,
        0x2A83,
        0x2A84,
        0x2A8B,
        0x2A8C,
        0x2A91,
        0x2A92,
        0x2A93,
        0x2A94,
        0x2A95,
        0x2A96,
        0x2A97,
        0x2A98,
        0x2A99,
        0x2A9A,
        0x2A9B,
        0x2A9C,
        0x2AA1,
        0x2AA2,
        0x2AA6,
        0x2AA7,
        0x2AA8,
        0x2AA9,
        0x2AAA,
        0x2AAB,
        0x2AAC,
        0x2AAD,
        0x2AAF,
        0x2AB0,
        0x2AB3,
        0x2AB4,
        0x2ABB,
        0x2ABC,
        0x2ABD,
        0x2ABE,
        0x2ABF,
        0x2AC0,
        0x2AC1,
        0x2AC2,
        0x2AC3,
        0x2AC4,
        0x2AC5,
        0x2AC6,
        0x2ACD,
        0x2ACE,
        0x2ACF,
        0x2AD0,
        0x2AD1,
        0x2AD2,
        0x2AD3,
        0x2AD4,
        0x2AD5,
        0x2AD6,
        0x2ADE,
        0x2AE3,
        0x2AE4,
        0x2AE5,
        0x2AEC,
        0x2AED,
        0x2AF7,
        0x2AF8,
        0x2AF9,
        0x2AFA,
        0x2E02,
        0x2E03,
        0x2E04,
        0x2E05,
        0x2E09,
        0x2E0A,
        0x2E0C,
        0x2E0D,
        0x2E1C,
        0x2E1D,
        0x2E20,
        0x2E21,
        0x2E22,
        0x2E23,
        0x2E24,
        0x2E25,
        0x2E26,
        0x2E27,
        0x2E28,
        0x2E29,
        0x3008,
        0x3009,
        0x300A,
        0x300B,
        0x300C,
        0x300D,
        0x300E,
        0x300F,
        0x3010,
        0x3011,
        0x3014,
        0x3015,
        0x3016,
        0x3017,
        0x3018,
        0x3019,
        0x301A,
        0x301B,
        0xFE59,
        0xFE5A,
        0xFE5B,
        0xFE5C,
        0xFE5D,
        0xFE5E,
        0xFE64,
        0xFE65,
        0xFF08,
        0xFF09,
        0xFF1C,
        0xFF1E,
        0xFF3B,
        0xFF3D,
        0xFF5B,
        0xFF5D,
        0xFF5F,
        0xFF60,
        0xFF62,
        0xFF63,
    }};
    return retval;
}

}}}

#endif
