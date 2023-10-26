#pragma once

#include "mnist.hpp"

namespace mnist {

template<class T = uint8_t>
Vec<T, TRAIN_SIZE, 7, 7> read_train_images_7x7()
{
	Vec<double, TRAIN_SIZE, 7, 7> rtn_double(0);
	auto raw = read_train_images();

	rep(i, TRAIN_SIZE) {
		rep(y, IMAGE_HEIGHT) rep(x, IMAGE_WIDTH){
			rtn_double[i, y/4, x/4] += raw[i, y, x];
		}
	}

	return (rtn_double / 16).to<T>();
}

template<class T = uint8_t>
Vec<T, TEST_SIZE, 7, 7> read_test_images_7x7()
{
	Vec<double, TEST_SIZE, 7, 7> rtn_double(0);
	auto raw = read_test_images();

	rep(i, TEST_SIZE) {
		rep(y, IMAGE_HEIGHT) rep(x, IMAGE_WIDTH){
			rtn_double[i, y/4, x/4] += raw[i, y, x];
		}
	}

	return (rtn_double / 16).to<T>();
}

}
