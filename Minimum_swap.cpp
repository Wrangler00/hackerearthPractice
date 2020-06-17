//https://www.hackerrank.com/challenges/minimum-swaps-2/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=arrays

int minimumSwaps(vector<int> arr) {
    int sz = arr.size();
    int ans=0,i,j;
    for(i=0;i<sz;i++){
        if(arr[i] == i+1)
            continue;
        int roam=arr[i],j=i,fg=false;
        while(roam!=-1){
            roam = arr[roam-1];
            arr[j]=-1;
            j = roam-1;
            ++ans;
            fg=true;
        }

        if (fg) --ans;
    }

    return ans;
}
