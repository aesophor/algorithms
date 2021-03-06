// Runtime: 28 ms, faster than 67.39% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 16.5 MB, less than 41.05% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> existing_chars;
        int win_left = 0;
        int win_right = 0;
        int max_len = 0;

        while (win_right < s.size()) {
            if (existing_chars.find(s.at(win_right)) == existing_chars.end()) {
                // If this char has not appeared before, add it to the map.
                existing_chars[s.at(win_right)] = win_right; // store its index
            } else {
                // If this char has appeared before...
                // and it is within current window
                if (existing_chars[s.at(win_right)] < win_left) {
                    existing_chars[s.at(win_right)] = win_right; // store its index
                } else {
                    // Calculate current unrepeated substring length
                    max_len = max(max_len, win_right - win_left);

                    // Set win_left to the next index where it previously appeared
                    win_left = existing_chars.at(s.at(win_right)) + 1;
                    existing_chars[s.at(win_right)] = win_right;
                }
            }
            win_right++;
        }

        // Calculate the size of last window
        max_len = max(max_len, win_right - win_left);
        return max_len;
    }
};
