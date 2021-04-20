class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> rows;
        
        if(numRows>=1)
        {
            rows.push_back({1});
        }
        
        int row_length=1;
        vector<int> prev_row = rows[0];
        
        while(numRows>row_length)
        {
            vector<int> row;
            for(int t=0; t<=row_length; t++)
            {
                if(t==0 || t==row_length)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(prev_row[t-1]+prev_row[t]);
                }
            }
            rows.push_back(row);
            row_length++;
            prev_row = row;
        }
        return rows;
    }
};