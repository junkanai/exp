class RndBase {
private:
	uint32_t x, y, z, w;
protected:
	void init()
	{
		// initialize seed from instance of RandomSeed
		x = rnd_seed();
		y = rnd_seed();
		z = rnd_seed();
		w = rnd_seed();
	}

	uint32_t get_u32()
	{
		uint32_t t = x ^ (x << 11);
		x = y; y = z; z = w;
		w ^= t ^ (t >> 8) ^ (w >> 19);
		return w;
	}
};
