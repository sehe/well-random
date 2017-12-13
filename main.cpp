// Copyright (c) Sergiu Dotenco 2010
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * @brief WELL PRNG implementation unit test.
 * @file welltest.cpp
 */

#include <algorithm>
#include <memory>
#include <iostream>

#include "well.hpp"

#define MESSAGE_PREAMBLE() (std::cerr << __FILE__ << ":" << __LINE__ << " ")

#define CHECK_EQUAL(expected,actual) do { \
    auto&& _e = expected; \
    auto&& _a = actual; \
    if (_e != _a) \
        MESSAGE_PREAMBLE() << "expected:" << #expected << " = " << _e << "\n" \
                  << "\tactual:" << #actual << " = " << _a << "\n"; \
} while (0)

#define CHECK(test) do { if (!(test)) MESSAGE_PREAMBLE() << #test << "\n"; } while (0)

/**
 * @brief Generic WELL test case.
 *
 * The test case performs the following checks:
 * -# The last generated value is equal to the value generate by the reference
 *    implementation after @f$10^9@f$ iterations. The generator is seeded using
 *    an array filled with 1s.
 * -# The @c min and @c max methods of the @ref Well generator return 0 and
 *    @f$2^{32}-1@f$ respectively.
 *
 * @tparam RandomNumberGenerator WELL PRNG implementation type.
 * @tparam Expected The expected result after @f$10^9@f$ iterations.
 */
template
<
    class RandomNumberGenerator,
    typename RandomNumberGenerator::result_type Expected
>
class WellTestCase
{
    RandomNumberGenerator rng;

    typedef typename RandomNumberGenerator::result_type result_type;

    result_type generate()
    {
        unsigned state[RandomNumberGenerator::state_size];
        std::uninitialized_fill_n(state, RandomNumberGenerator::state_size, 1);

        unsigned* p = state;
        rng.seed(p, p + RandomNumberGenerator::state_size);

        result_type x;

        int iterations = 1000000000;

        while (iterations-- > 0)
            x = rng();

        return x;
    }

public:
    static void run()
    {
        WellTestCase c;

        CHECK_EQUAL(c.generate(), Expected);
        CHECK_EQUAL(c.rng.min(), 0U);
        CHECK_EQUAL(c.rng.max(), ~0U);
        CHECK_EQUAL(c.rng, c.rng);
        CHECK(c.rng == c.rng);
    }
};

/**
 * @brief Defines the actual test case.
 *
 * @param name The name of the test case.
 * @param type WELL pseudo-random generator type.
 * @param expected The expected result after @f$10^9@f$ iterations.
 *
 * @hideinitializer
 */
int main() {
    //CHECK_EQUAL(16, Detail::shift<2>(64));
    //CHECK_EQUAL(64, Detail::shift<-2>(16));
    //CHECK_EQUAL(32, Detail::shift<0>(32));
    //CHECK(Detail::is_powerof2(512u));
    //CHECK(not Detail::is_powerof2(0u));

    WellTestCase<Well512a,   0x2b3fe99e>::run();
    WellTestCase<Well521a,   0xc9878363>::run();
    WellTestCase<Well521b,   0xb75867f6>::run();
    WellTestCase<Well607a,   0x7b5043ea>::run();
    WellTestCase<Well607b,   0xaedee7da>::run();
    WellTestCase<Well800a,   0x2bfe686f>::run();
    WellTestCase<Well800b,   0xf009e1bd>::run();
    WellTestCase<Well1024a,  0xd07f528c>::run();
    WellTestCase<Well1024b,  0x867f7993>::run();
    WellTestCase<Well19937a, 0xb33a2cd5>::run();
    WellTestCase<Well19937b, 0x191de86a>::run();
    WellTestCase<Well19937c, 0x243eaed5>::run();
    WellTestCase<Well21701a, 0x7365a269>::run();
    WellTestCase<Well23209a, 0x807dacb >::run();
    WellTestCase<Well23209b, 0xf1a77751>::run();
    WellTestCase<Well44497a, 0xfdd7c07b>::run();
    WellTestCase<Well44497b, 0x9406547b>::run();
}
