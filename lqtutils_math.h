/**
 * MIT License
 *
 * Copyright (c) 2021 Luca Carlon
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

#ifndef LQTUTILS_MATH
#define LQTUTILS_MATH

#include <cmath>
#include <QtMath>

namespace lqt {

/**
 * @brief in_range<T> Returns true iif val is in [a, b).
 * @param val
 * @param a
 * @param b
 * @return
 */
template<typename T> [[deprecated]] inline bool in_range(const T& val, const T& a, const T& b)
{ return val >= a && val < b; }

/**
 * @brief in_range<T> Returns true iif val is in [a, b].
 * @param val
 * @param a
 * @param b
 * @return
 */
template<typename T> inline bool is_in(const T& val, const T& a, const T& b)
{ return val >= a && val <= b; }

/**
 * @brief nearest_in_range Returns the nearest value in the range.
 * @param val
 * @param a
 * @param b
 * @return
 */
template<typename T> inline T nearest_in_range(const T& val, const T& a, const T& b)
{ return val < a ? a : (val > b) ? b : val; }

/**
 * Compares two floating point numbers.
 *
 * @brief lqt_approx_equal
 * @param a
 * @param b
 * @param epsilon
 * @return
 */
template<typename T> inline bool approx_equal(const T& a, const T& b, const T& epsilon)
{ return std::fabs(a - b) <= ( (std::fabs(a) < std::fabs(b) ? std::fabs(b) : std::fabs(a)) * epsilon); }

} // namespace

#endif // LQTUTILS_MATH
