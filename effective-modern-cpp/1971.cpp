class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>>adjList(n);
        for (auto i:edges){
            adjList[i[0]].push_back(i[1]) ;
            adjList[i[1]].push_back(i[0]) ;
        } 
       if(source==destination)
           return true;
        stack<int> st;
        set<int> seen; 
        st.push(source);
        while(!st.empty()){
            int curNode = st.top();
            st.pop();
            seen.insert(curNode);
            for(auto neigh:adjList[curNode]) {
                if(!seen.contains(neigh)){
                    st.push(neigh);
                    if(neigh==destination)
                        return true;


                }
            }   
        }

        return false;
    }
};
