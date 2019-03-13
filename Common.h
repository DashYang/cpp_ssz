#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using byte = uint8_t;
using bytes = std::vector<byte>;
using u256 =  boost::multiprecision::number<boost::multiprecision::cpp_int_backend<256, 256, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;

