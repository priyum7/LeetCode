            if(hash.count(s[right]))
            {
                checker[s[right]]++;
                if(checker[s[right]]<=hash[s[right]])
                check--;
                
            }
            
            right++;
            
            while(check==0 && left<=right)
            {
                string temp = s.substr(left, right-left); 
                
                //cout<<"left "<<left<<"right "<<right<<" "<<temp<<" count "<<check<<endl;
                
                if(result.length()==0 || result.length()>temp.length())
                result=temp;
                
                if(hash.count(s[left]))
                {
                    checker[s[left]]--;
                    if(checker[s[left]]<hash[s[left]])
                    check++;
                    
                }
                
                left++;
                
                
                
                
            }
            
            //cout<<"left"<<left<<" right"<<right<<" count"<<check<<endl;
            
        }
