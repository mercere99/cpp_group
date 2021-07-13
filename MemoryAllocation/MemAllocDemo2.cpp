#include <vector>
#include <iostream>

bool Test(const std::vector<int> & vals) {
  for (size_t i = 0; i < vals.size(); i++) {
    if (vals[i] != (i % 3 == 0)) return false;
  }

  std::cout << "Found: ";
  for (int x : vals) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return true;
}

std::vector< std::vector<int> > cache;

bool VectorPass(size_t next=0) {
  if (cache.size() <= next+1) cache.resize(next+2);
  auto & vals = cache[next];

  if (next == vals.size()) {
    return Test(vals);
  }

  cache[next+1] = vals;
  bool result1 = VectorPass(next+1); // Next value stays zero.
  vals[next] = 1;
  cache[next+1] = vals;
  bool result2 = VectorPass(next+1);

  return result1 || result2;
}

int main()
{
  cache.resize(100);
  cache[0].resize(25);
  VectorPass();

  std::cout << "Done!\n";
}
