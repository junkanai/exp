class RndSeed {
private:
	static constexpr uint32_t xinit = 123456789;
	static constexpr uint32_t yinit = 362436069;
	static constexpr uint32_t zinit = 521288629;
	static constexpr uint32_t winit = 88675123;

	uint32_t x, y, z, w;
public:
	RndSeed() : x(xinit), y(yinit), z(zinit), w(winit) {}

	uint32_t operator()()
	{
		uint32_t t = x ^ (x << 11);
		x = y; y = z; z = w;
		w ^= t ^ (t >> 8) ^ (w >> 19);
		return w;
	}

	void operator()(uint32_t seed)
	{
		x = xinit + seed * 11;
		y = yinit; z = zinit; w = winit;
	}
};

RndSeed rnd_seed;
