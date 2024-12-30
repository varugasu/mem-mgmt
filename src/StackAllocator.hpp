#ifndef STACK_ALLOCATOR_HPP
#define STACK_ALLOCATOR_HPP

#include <iostream>
#include <cstdint>
#include <cstdlib>

class StackAllocator {
 public:
  using Marker = uint32_t;

  explicit StackAllocator(uint32_t size_bytes)
      : stackSize{size_bytes}, memory{nullptr}, top{0} {
    memory = static_cast<char*>(std::malloc(size_bytes));
    if (!memory) {
      throw std::bad_alloc();
    }
  }

  ~StackAllocator() { std::free(memory); }

  void* alloc(uint32_t size_bytes) {
    if (top + size_bytes > stackSize) {
      throw std::bad_alloc();
    }
    void* block = memory + top;
    top += size_bytes;
    return block;
  }

  Marker getMarker() const { return top; }

  void freeToMarker(Marker marker) { top = marker; }

  void clear() { top = 0; }

 private:
  char* memory;
  uint32_t stackSize;
  Marker top;
};

#endif
