class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        
        for(auto itr=m.begin(); itr != m.end(); itr++){
            pq.push({itr->second, itr->first});
        }

        int size = s.size();
        int x = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int freq = top.first;
            char character = top.second;
            if(freq > (size+1)/2) return "";
            while(freq!=0){
                freq--;
                if(x>=size) x=1;
                s[x]=character;
                x=x+2;
            }
        }
        return s;
    }
};