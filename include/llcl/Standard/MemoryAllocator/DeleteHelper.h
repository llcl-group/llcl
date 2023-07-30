#ifndef LLCL_STANDARD_MEMORYALLOCATOR_DELETEHELPER_H
#define LLCL_STANDARD_MEMORYALLOCATOR_DELETEHELPER_H

namespace llcl {

namespace Standard {

namespace MemoryAllocator {

struct DeleteHelper {
  template <class Type, class Allocator>
  static void DeleteObject(const Type* obj, Allocator* alloc);

  template <class Type, class Allocator>
  static void DeleteObjectRow(const Type* obj, Allocator* alloc);
};

template <bool IsPolymorphic>
struct DeleteHelperHelper {
  template <class Type>
  static void* caster(const Type* object) {
    return static_cast<void*>(const_cast<Type*>(object));
  }
};

}  // namespace MemoryAllocator

}  // namespace Standard

}  // namespace llcl


#endif  // LLCL_STANDARD_MEMORYALLOCATOR_DELETEHELPER_H