            
            
            
            while(i<arr.size()-1 && arr[i]<arr[i+1])
            {
                
                up++;                                
                cout<<"INDEX"<<i<<arr[i]<<" "<<arr[i+1]<<"UP:"<<up<<endl;
                i++;
​
            }
            
            if(i==arr.size()-1)
                {
                    i++;
                    break;
                }
            
            while(i<arr.size()-1 && arr[i]>arr[i+1])
            {
                
                down++;
                cout<<"INDEX"<<i<<arr[i]<<" "<<arr[i+1]<<"DOWN:"<<down<<endl;
                
                i++;
            }
            
            
                
            cout<<"INDEX"<<i<<"  UP:"<<up<<"   DOWN:"<<down<<endl;
            
            if(up>1 && down>0 && max<up+down)
            {
                max=up+down;
            }
            
            up=1;
            down=0;
            if(i==arr.size()-1)
                {
                    i++;
                }
        }
        return max;
    }
};
