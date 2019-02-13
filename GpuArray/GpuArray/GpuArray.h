#ifndef GPUARRAY_H
#define GPUARRAY_H


#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

template <class T>
class power_functor {

	T a;

public:

	power_functor(T a_) { a = a_; }

	__host__ __device__ T operator()(T x) const
	{
		return pow(x, a);
	}
};

template <class T>
class add_functor {
	
public:
	__host__ __device__	float operator()(const T& x, const T& y) const
	{
		return x + y;
	}

};

template <class T>
class GpuArray
{
public:
	GpuArray()
	{

	}

	GpuArray(int numElements)
	{
		_deviceVec.resize(numElements);
	}

	~GpuArray()
	{

	}

	GpuArray operator+(const GpuArray& b) {
		GpuArray result;
		box.length = this->length + b.length;
		box.breadth = this->breadth + b.breadth;
		box.height = this->height + b.height;
		return box;
	}
private:
	thrust::device_vector<T> _deviceVec;

};
#endif /* GPUARRAY_H */