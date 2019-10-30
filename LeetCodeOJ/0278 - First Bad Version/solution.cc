// Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Bad Version.
// Memory Usage: 8.3 MB, less than 42.42% of C++ online submissions for First Bad Version.

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    int lo = 1;
    int hi = n;
    
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      
      if (isBadVersion(mid)) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    
    return hi + 1;
  }
};
