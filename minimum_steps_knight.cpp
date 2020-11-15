int edge;

bool valid(int i, int j)
{
    return (i>=0 && j>=0 && i<edge && j<edge);
}

int minStepToReachTarget(int knightPos[], int targetPos[], int N) {
    // code here
    
    pair<int, int> start, end, temp;
    
    start.first = knightPos[0]-1;
    start.second = knightPos[1]-1;
    end.first = targetPos[0]-1;
    end.second = targetPos[1]-1;
    edge = N;
    
    vector<vector<int>> arr(N, vector<int>(N, -1));
    
    vector<int> dx{-2, -1, 1, 2, -2, -1, 1, 2};
    vector<int> dy{-1, -2, -2, -1, 1, 2, 2, 1};
    
    queue<pair<int, int>> q;
    q.push(start);
    arr[start.first][start.second] = 0;
    
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        
        for(int i=0; i<8; i++)
        {
            int x = temp.first + dx[i];
            int y = temp.second + dy[i];
            if(valid(x, y) && arr[x][y] == -1) 
            {
                if(x == end.first && y == end.second) return arr[temp.first][temp.second] + 1;
                
                arr[x][y] = arr[temp.first][temp.second] + 1;
                q.push({x, y});
            }
            
        }
    }
    return 0;
}
