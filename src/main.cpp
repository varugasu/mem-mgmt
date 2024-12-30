#include "StackAllocator.hpp"

int main() {
  StackAllocator allocator{1024};

  void* block1 = allocator.alloc(128);

  auto block1Marker = allocator.getMarker();
  std::cout << "Allocated 128 bytes, marker: " << block1Marker << '\n';

  // Set all bytes in block1 to 1
  std::memset(block1, 1, 128);

  char* data = static_cast<char*>(block1);
  std::cout << "Content of block1: ";
  for (size_t i = 0; i < 128; ++i) {
    std::cout << static_cast<int>(data[i]) << ' ';
  }
  std::cout << '\n';

  void* block2 = allocator.alloc(128);
  auto block2Marker = allocator.getMarker();
  std::cout << "Allocated 128 bytes, marker: " << block2Marker << '\n';

  // Set all bytes in block2 to 2
  std::memset(block2, 2, 128);

  char* data2 = static_cast<char*>(block2);
  std::cout << "Content of block2: ";
  for (size_t i = 0; i < 128; ++i) {
    std::cout << static_cast<int>(data2[i]) << ' ';
  }
  std::cout << '\n';

  allocator.freeToMarker(block1Marker);
  std::cout << "Freed to marker, marker: " << allocator.getMarker() << '\n';

  void* block3 = allocator.alloc(128);
  std::cout << "Allocated 128 bytes, marker: " << allocator.getMarker() << '\n';
  std::memset(block3, 3, 128);

  std::cout << "Content of block3 (same as block2): ";
  for (size_t i = 0; i < 128; ++i) {
    std::cout << static_cast<int>(data2[i]) << ' ';
  }
  std::cout << '\n';
}
