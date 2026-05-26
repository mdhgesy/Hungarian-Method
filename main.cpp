#include <iostream>

struct Edge
{
  // TODO
};

template <typename T>
struct Vector
{
  T *data;
  size_t size;
  size_t capacity;

  void Initialize(size_t capacity)
  {
    if (capacity == 0)
    {
      capacity = 1;
    }

    this->data = malloc(sizeof(T) * capacity);

    if (this->data == nullptr)
    {
      std::cout << "Error allocating memory\n";
      exit(EXIT_FAILURE);
    }

    this->size = 0;
    this->capacity = capacity;
  }

  void Resize()
  {
    this->data = realloc(this->data, this->capacity * 2 * sizeof(T));
    if (this->data == nullptr)
    {
      std::cout << "error reallocating memory\n";
      exit(EXIT_FAILURE);
    }

    this->capacity *= 2;
  }

  void PushBack(T data)
  {
    if (this->size == this->capacity)
    {
      Resize(vector);
    }

    this->data[this->size] = data;
    this->size++;
  }

  void Insert(T data, size_t index)
  {
    if (this->size == this->capacity)
    {
      this->Resize();
    }

    for (size_t i = this->size; i > index; --i)
    {
      this->data[i] = this->data[i - 1];
    }

    this->data[index] = data;
    this->size++;
  }

  void Erase(size_t index)
  {
    if (index >= this->size)
    {
      return;
    }

    for (size_t i = index; i < this->size - 1; ++i)
    {
      this->data[i] = this->data[i + 1];
    }

    this->size -= 1;
  }

  void Clear()
  {
    this->size = 0;
  }

  void Free()
  {
    free(this->data);
    this->data = nullptr;
    this->size = 0;
    this->capacity = 0;
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int iterations = 0;
  std::cin >> iterations;

  for (int z = 0; z < iterations; ++z)
  {
  }
}