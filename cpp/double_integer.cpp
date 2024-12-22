
#include <cstdint>

int32_t double_integer(const int32_t n)
{
    return n * 2;
}
//////////////////
int __attribute__((naked)) double_integer(int)
{
__asm__("shl %edi\nmov %edi,%eax\nret\n");
}
//////////////
#include <numeric>
#include <cstdint>
#include <vector>

namespace calculation
{
using ValueType = std::int32_t;

class IStrategy
{
public:
	virtual ~IStrategy() {}

	virtual ValueType calculate(const ValueType value) = 0;
};
  
class Computation
{
public:
	virtual ~Computation() {}

	virtual void setStrategy(IStrategy* strategy) final
	{
		m_strategy = strategy;
	}

	virtual ValueType calculate(const ValueType value)
	{
		return m_strategy->calculate(value);
	}

private:
	IStrategy* m_strategy;
};

class Double : public IStrategy
{
public:
	ValueType calculate(const ValueType value) override
	{
		const std::vector<ValueType> values (2, value);
		return std::accumulate(std::begin(values), std::end(values), 0);
	}
};

} // namespace calculation

calculation::ValueType double_integer(const calculation::ValueType value)
{
	calculation::Computation computation {};
	calculation::Double strategy {};

	computation.setStrategy(&strategy);

	auto result = computation.calculate(value);
	return result;
}