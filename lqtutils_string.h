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

#ifndef LQTUTILS_STRING_H
#define LQTUTILS_STRING_H

#include <QDir>
#include <QString>

#ifndef QSL
#define QSL QStringLiteral
#endif // QSL

inline QString path_combine(std::initializer_list<QString> l)
{
    QString ret;
    for (size_t i = 0; i < l.size(); i++) {
        ret += *(l.begin() + i);
        if (Q_LIKELY(i != l.size() - 1))
            ret += QDir::separator();
    }
    return ret;
}

inline int string_to_int(const QString& s, int def, bool* ok = nullptr)
{
    bool _ok;
    int ret = s.toInt(&_ok);
    if (ok)
        *ok = _ok;
    return _ok ? ret : def;
}

inline float string_to_float(const QString& s, float def, bool* ok = nullptr)
{
    bool _ok;
    float ret = s.toFloat(&_ok);
    if (ok)
        *ok = _ok;
    return _ok ? ret : def;
}

#endif // LQTUTILS_STRING_H