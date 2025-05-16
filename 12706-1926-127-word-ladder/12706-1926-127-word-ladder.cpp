class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;

            if(word==endWord) return steps;

            q.pop();

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    if (ch == original) continue; // Skip same character
                    word[i]=ch;
                    
                    //if that word exist in set .. then remove it from the set and push it in queue
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original; //This line restores the original character at position i in the string after trying all 26 letters of the alphabet. -> like if we have hit then last string is zit that's why we need to get back {original }
            }
        }
         
        // if no such sequence exists.
        return 0;
    }
};