#ifndef INSTANCE_COUNTER_H
#define INSTANCE_COUNTER_H

#ifdef USE_INSTANCE_COUNTER
#define DEFINE_CLASS_WITH_BASE(className, ...) class className: __VA_ARGS__, private Utility::InstanceCounter<className>
#define DEFINE_CLASS(className) class className: private Utility::InstanceCounter<className>
#else
#define DEFINE_CLASS_WITH_BASE(className, ...) class className: __VA_ARGS__
#define DEFINE_CLASS(className) class className
#endif

namespace Utility {
	template <typename T>
	class InstanceCounter
	{
	public:
		InstanceCounter() { ++sActiveInstances; ++sTotalInstances; }
		InstanceCounter(const InstanceCounter&) { ++sActiveInstances; ++sTotalInstances; }
		~InstanceCounter() { --sActiveInstances; }

		static inline size_t total()	{ return sTotalInstances;	}
		static inline size_t active()	{ return sActiveInstances;	}

	private:
		static size_t sActiveInstances;
		static size_t sTotalInstances;
	};

	template<typename T>
	size_t InstanceCounter<T>::sActiveInstances = 0;

	template<typename T>
	size_t InstanceCounter<T>::sTotalInstances = 0;

} // Namespace
#endif