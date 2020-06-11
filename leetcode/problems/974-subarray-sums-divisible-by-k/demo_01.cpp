class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> m_k_counter = {{0, 1}};
        int sum = 0;
        int found = 0;
        int m_k = 0;
        for (auto e: A) {
            sum += e;
            m_k = (sum % K);
            if (m_k < 0) m_k += K;
            
            if (m_k_counter.count(m_k)) {
                found += m_k_counter[m_k];
            }
            ++m_k_counter[m_k];
        }
        return found;
    }
};
