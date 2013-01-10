// @see http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees
template <typename T, int _Size>
class BIT {
public:
	BIT() : data() {}

	// Change frequency at some position(index) by value and update tree; index > 0
	void update(int index, T value)
	{
		while(index <= _Size)
		{
			data[index] += value;
			index += (index & -index);
		}
	}

	// Read cumulative frequency of [0, index]; index > 0
	T read(int index)
	{
		T sum(0);
		while(index > 0)
		{
			sum += data[index];
			index -= (index & -index);
		}
		return sum;
	}

	// Read the actual frequency at a position; index > 0
	T read_single(int index)
	{
		T sum = data[index];

		if(index > 0)
		{
			int z = index - (index & -index);
			index--;
			while(index != z)
			{
				sum -= data[index];
				index -= (index & -index);
			}
		}
		return sum;
	}

	int size() const {return _Size;}

private:
	// TODO: Use an allocation policy...
	T data[_Size + 1]; // 0th index will not be used..
};
