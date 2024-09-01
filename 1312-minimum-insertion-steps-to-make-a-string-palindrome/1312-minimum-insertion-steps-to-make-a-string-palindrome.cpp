class Solution {
public:
int lcs(string s, string t) {
  int n1 = s.size();
  int n2 = t.size();
  vector<int> prev(n2 + 1, 0);
  for (int i = 1; i <= n1; i++) {
    vector<int> curr(n2 + 1, 0);
    for (int j = 1; j <= n2; j++) {
      if (s[i - 1] == t[j - 1]) {
        curr[j] = 1 + prev[j - 1];
      }

      else {
        int first = prev[j];
        int second = curr[j - 1];
        curr[j] = max(first, second);
      }
    }
	prev=curr;
  }
  return prev[n2];
}
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        return n-lcs(s,t);
    }
};