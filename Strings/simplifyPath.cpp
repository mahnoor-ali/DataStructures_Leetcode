//TIME : O(N)
//SPACE: O(N)

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> fileName;
        int N = path.size();
        int i = 1;
        int j = 1;
        //to split path into folder names only without '/'
        while(j < N){
            if(path[j] == '/'){
                fileName.push_back(path.substr(i,j-i));
                //now point j to a non /
                while(path[j]=='/'){
                    j++;
                }
                i = j;
            }
            j++;
        }
        
        if(i<N){
            //Edge case = when there is no last back slash
            fileName.push_back(path.substr(i,j-i));
        }
        
        stack<string> stackPath;;
        
        for(int i=0; i<fileName.size() ;i++)
        {
            if((!stackPath.empty()) && (fileName[i]==".."))
              stackPath.pop();
            else if((fileName[i]!="") && (fileName[i]!=".") && (fileName[i]!=".."))
              stackPath.push(fileName[i]);
        }
        
        //edge case = when "" path is given
        if(stackPath.empty())
         return "/";
        
        //PATH FORMATION
        string res="";
        while(!stackPath.empty()){
           
            res = '/' + stackPath.top() + res;
            stackPath.pop();
        }
        
        return res;
    }
};