#!/usr/bin/env python
# -*- coding: utf-8 -*-

test_form = decls = '''\
// Warning! This file is autogenerated.
#include <boost/text/normalize.hpp>
#include <boost/text/utility.hpp>

#include <gtest/gtest.h>

#include <algorithm>


{0}
'''

source = 0
NFC = 1
NFD = 2
NFKC = 3
NFKD = 4

def extract_tests(filename):
    current_batch = []
    retval = []
    lines = open(filename, 'r').readlines()
    num_lines = 0
    for line in lines:
        if num_lines == 200:
            retval.append(current_batch)
            current_batch = []
            num_lines = 0
        line = line[:-1]
        if not line.startswith('#') and not line.startswith('@') and len(line) != 0:
            comment_start = line.find('#')
            comment = ''
            if comment_start != -1:
                comment = line[comment_start + 1:].strip()
                line = line[:comment_start]
            raw_fields = line.split(';')[:-1]
            fields = []
            for f in raw_fields:
                f = map(lambda x: '0x' + x, f.split(' '))
                fields.append(f)
            fields = map(lambda x: map(lambda y: '0x' + y, x.split(' ')), line.split(';'))
            current_batch.append((fields, line, comment))
        num_lines += 1
    if len(current_batch):
        retval.append(current_batch)
    return retval

def arrayify(cps, name):
    return 'std::array<uint32_t, {0}> {1} = {{{{ {2} }}}};'.format(
        len(cps), name, ', '.join(cps)
    )

def generate_tests(tests, normalization, field):
    for i in range(len(tests)):
        test_lines = ''
        chunk = tests[i]
        test_idx = 0
        for elem in chunk:
            (fields, line, comment) = elem
            test_lines += '''
TEST(normalization, {4}_{5:03}_{6:03})
{{
    // {0}
    // {1}
    {{
        {2}
        boost::text::string str = boost::text::to_string(source.begin(), source.end());
        {3}

        boost::text::normalize_to_{4}(str);

        boost::text::utf32_range utf32_range(str);

        EXPECT_EQ(std::distance(utf32_range.begin(), utf32_range.end()), dest.size());

        auto dest_it = dest.begin();
        int i = 0;
        for (auto x : utf32_range) {{
            EXPECT_EQ(x, *dest_it) << "iteration " << i;
            ++dest_it;
            ++i;
        }}
'''.format(line, comment, arrayify(fields[source], 'const source'), arrayify(fields[field], 'const dest'), normalization, i, test_idx)
            test_lines += '\n    }\n}\n\n'
            test_idx += 1
        cpp_file = open('normalize_to_{}_{:03}.cpp'.format(normalization, i), 'w')
        cpp_file.write(test_form.format(test_lines))

tests = extract_tests('NormalizationTest.txt')
generate_tests(tests, 'nfd', NFD)
generate_tests(tests, 'nfkd', NFKD)

# TODO: Add nfc and nfkc.

# TODO: Test all individual code points not covered in the tests above, as the
# header at the top of NormalizationTest.txt indicates that this is required.
