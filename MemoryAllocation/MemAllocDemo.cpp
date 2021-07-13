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

bool VectorPass(std::vector<int> vals, size_t next=0) {
  if (next == vals.size()) {
    return Test(vals);
  }

  bool result1 = VectorPass(vals, next+1); // Next value stays zero.
  vals[next] = 1;
  bool result2 = VectorPass(vals, next+1);

  return result1 || result2;
}

int main()
{
  std::vector<int> vals(25);
  VectorPass(vals);

  std::cout << "Done!\n";
}
