#ifndef LLCL_STANDARD_ADT_ILIST_BASE_H
#define LLCL_STANDARD_ADT_ILIST_BASE_H

#include <cassert>

#include "llcl/Standard/ADT/ilist_node_base.h"

namespace llcl {

template <bool EnableSentinelTracking, class ParentTy>
class ilist_base {
 public:
  using node_base_type = ilist_node_base<EnableSentinelTracking, ParentTy>;

  static void insertBeforeImpl(node_base_type& Next, node_base_type& N) {
    node_base_type& Prev = *Next.getPrev();
    N.setNext(&Next);
    N.setPrev(&Prev);
    Prev.setNext(&N);
    Next.setPrev(&N);
  }
};

}  // namespace llcl

#endif  // LLCL_STANDARD_ADT_ILIST_BASE_H