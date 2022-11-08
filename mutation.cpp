//433. Minimum Genetic Mutation

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int count=0, mutates=0;
        bool contain = false;
        vector<string>::iterator iteratr = find(bank.begin(), bank.end(),endGene);
        int endGenePosition=iteratr-bank.begin();
        if (iteratr != bank.end())
            contain=true;
        if((bank.size()>0)&&(contain))
        {
            for(int i=0; i<8; i++)
            {
                if(endGene[i]!=startGene[i])
                {
                ++count;
                for(string mutation: bank){
                    if(mutation==bank[endGenePosition])
                        continue;
                    else if(endGene[i]==mutation[i])
                    {
                        mutates++;
                        break;
                    }
                }
                }
            }
            if(mutates>=count-1)
                return count;
            else
                return -1;
        }
        else
            return -1;
    }
};