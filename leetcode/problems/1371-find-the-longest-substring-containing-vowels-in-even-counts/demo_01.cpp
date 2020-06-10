ass Solution {
public:
    int findTheLongestSubstring(string s) {
      vector<int> status_pos(32, INT_MAX);
      status_pos[0] = -1;
      int status = 0;
      int found = -1;
      
      for (int i = 0; i < s.size(); ++i) {
          switch (s[i]) {
              case 'a': status ^= 1 << 1; break;
              case 'e': status ^= 1 << 2; break;
              case 'i': status ^= 1 << 3; break;
              case 'o': status ^= 1 << 4; break;
              case 'u': status ^= 1 << 5; break;
              default : break;
          }
          if (status_pos[status] == INT_MAX) status_pos[status] = i;
          else found = max(found, i - status_pos[status]);
      }

      return found;
    }
};
