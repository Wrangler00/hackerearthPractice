//https://www.hackerrank.com/challenges/ctci-ransom-note/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=dictionaries-hashmaps

//cpp

void checkMagazine(vector<string> mag, vector<string> nt) {
    int mgl = mag.size();
    int ntl = nt.size();

    unordered_map<string,int> mp;

    if(ntl>mgl){
        cout<<"No\n";
        return;
    }

    for(auto &i: mag){
        if(mp.find(i)!=mp.end())
            ++mp.at(i);
        else
            mp.insert({i,1});
    }

    for(auto &i: nt){
        if(mp.find(i)==mp.end()){
            cout<<"No\n";
            return;
        }
        if(mp.at(i) == 0){
            cout<<"No\n";
            return;
        }
        --mp.at(i);
    }

    cout<<"Yes\n";
    return;

}
