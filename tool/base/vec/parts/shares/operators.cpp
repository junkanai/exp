T&       operator()(size_t w, size_t z, size_t y, size_t x) { return data[w*Z*Y*X + z*Y*X + y*X + x]; }
const T& operator()(size_t w, size_t z, size_t y, size_t x) const { return data[w*Z*Y*X + z*Y*X + y*X + x]; }
T&       operator()(size_t i) { return data[i]; }
const T& operator()(size_t i) const { return data[i]; }

void operator+=(const T& t) noexcept { data += t; }
void operator+=(const Self& t) noexcept { data += t.data; }
Self operator+(const T& t) const noexcept { Self rtn = *this; rtn += t; return rtn; }
Self operator+(const Self& t) const noexcept { Self rtn = *this; rtn += t; return rtn; }
void operator-=(const T& t) noexcept { data -= t; }
void operator-=(const Self& t) noexcept { data -= t.data; }
Self operator-(const T& t) const noexcept { Self rtn = *this; rtn -= t; return rtn; }
Self operator-(const Self& t) const noexcept { Self rtn = *this; rtn -= t; return rtn; }
void operator*=(const T& t) noexcept { data *= t; }
void operator*=(const Self& t) noexcept { data *= t.data; }
Self operator*(const T& t) const noexcept { Self rtn = *this; rtn *= t; return rtn; }
Self operator*(const Self& t) const noexcept { Self rtn = *this; rtn *= t; return rtn; }
void operator/=(const T& t) { data /= t; }
void operator/=(const Self& t) { data /= t.data; }
Self operator/(const T& t) const { Self rtn = *this; rtn /= t; return rtn; }
Self operator/(const Self& t) const { Self rtn = *this; rtn /= t; return rtn; }
