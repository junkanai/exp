#pragma once

#include "mnist.hpp"

namespace mnist {

template<class T = uint8_t>
Vec<T, TRAIN_SIZE, 8, 6> read_train_images_8x6()
{
	Vec<double, TRAIN_SIZE, 8, 6> rtn_double(0);
	auto raw = read_train_images();

	rep(i, TRAIN_SIZE) {
		rep(y, 24) rep(x, 18) {
			rtn_double[i, y/3, x/3] += raw[i, y+2, x+5];
		}
	}

	return (rtn_double / 9).to<T>();
}

template<class T = uint8_t>
Vec<T, TEST_SIZE, 8, 6> read_test_images_8x6()
{
	Vec<double, TEST_SIZE, 8, 6> rtn_double(0);
	auto raw = read_test_images();

	rep(i, TEST_SIZE) {
		rep(y, 24) rep(x, 18) {
			rtn_double[i, y/3, x/3] += raw[i, y+2, x+5];
		}
	}

	return (rtn_double / 9).to<T>();
}

}
