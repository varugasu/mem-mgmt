# Custom Memory Managament

## Stack Allocator

```cpp
memory = static_cast<char*>(std::malloc(size_bytes));
```

We cast to `char*`:

- `char` is 1 byte in size
- Allow byte-precise pointer arithmethic. Like we do on `void* block = memory + top;`
- The C++ convetion for representing raw memory

The byte-previde pointer arithmethic is crucial because we know exactly how much we advance our pointer.

```cpp
char* memory = static_cast<char*>(malloc(100));
memory + 1  // Advances exactly 1 byte
memory + 50 // Advances exactly 50 bytes
```

If we use another type, for example `int*`, we must **multiply by 4**, because `sizeof(int) = 4`:

```cpp
int* memory = static_cast<int*>(malloc(100));
memory + 1  // Advances 4 bytes
memory + 50 // Advances 200 bytes
```
