/**
 * MIT License
 *
 * Copyright (c) 2020 Luca Carlon
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

#ifndef LQTUTILS_PERF_H
#define LQTUTILS_PERF_H

#include <QtGlobal>
#include <QElapsedTimer>

#include <functional>

#ifdef __GNUC__
#define LC_LIKELY(x) \
   __builtin_expect((x), 1)
#define LC_UNLIKELY(x) \
   __builtin_expect((x), 0)
#else
#define LC_LIKELY(x) (x)
#define LC_UNLIKELY(x) (x)
#endif // __GNUC__

/**
 * @brief measure_time Measures time spent in lambda f.
 * @param f The procedure to time.
 * @param callback The callback returning the result.
 * @return Time taken to compute f.
 */
inline void l_measure_time(std::function<void()> f, std::function<void(const qint64&)> callback = nullptr, bool disable = false)
{
    if (disable)
        f();
    else {
        QElapsedTimer timer;
        timer.start();
        f();

        qint64 time = timer.elapsed();
        if (callback)
            callback(time);
    }
}

/**
 * This macro wraps the l_measure_time. Defining/undefining L_ENABLE_BENCHMARKS
 * can be used to turn on/off benchmarks.
 */
#ifdef L_ENABLE_BENCHMARKS
#define L_MEASURE_TIME(f, callback, disable) l_measure_time(f, callback, disable)
#else
#define L_MEASURE_TIME(f, callback, disable) f()
#endif

#endif // LQTUTILS_PERF_H
