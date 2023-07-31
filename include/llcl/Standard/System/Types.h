#ifndef LLCL_STANDARD_SYSTEM_TYPES_H
#define LLCL_STANDARD_SYSTEM_TYPES_H

#include <cstddef>

namespace llcl {
namespace standard {

// platform-dependent types.
struct Types {
  using size_type = std::size_t;
  using UintPtr = std::size_t;
  using IntPtr = std::ptrdiff_t;
  using Int64 = long long;
  using Uint64 = unsigned long long;
};

}  // namespace standard
}  // namespace llcl

#endif  // LLCL_STANDARD_SYSTEM_TYPES_H