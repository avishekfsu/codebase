int compare(Player a, Player b)
{
    if (a.score > b.score)
        return 1;
    if (a.score < b.score)
        return 0;
    int i;
    
    for (i=0;i<min(a.name.length(),b.name.length());i++){
        if (a.name[i] > b.name[i])
            return 0;
        if (a.name[i] < b.name[i])
            return 1;
    }
    if (a.name.length() <= b.name.length())
        return 1;
    else
        return 0;
    
}

int partition(vector<Player> &a,int start,int end)
{
    Player pivot=a[end]; //choose end element as pivot;
    Player temp;
    int pindex=start;
    for (int jj=start;jj<end;jj++){
        if (compare(pivot,a[jj])==0){ //needs to swapped with pindex
            temp=a[pindex];
            a[pindex]=a[jj];
            a[jj]=temp;
            pindex=pindex+1;
        }
    }
    temp=a[end];
    a[end]=a[pindex];
    a[pindex]=temp;
    return pindex;
            
}
void quickSort(vector<Player> &players,int start,int end)
{
    if (end < start) return;
    
    int pindex=partition(players,start,end);
    quickSort(players,start,pindex-1);
    quickSort(players,pindex+1,end);
    
    
        
}
    
vector<Player> comparator(vector<Player> players) {
    
    quickSort(players,0,players.size()-1);
    return players;

}

