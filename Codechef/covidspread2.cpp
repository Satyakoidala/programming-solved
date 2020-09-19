#include <bits/stdc++.h>

using namespace std;

vector<int> vel(6);
int n;

int main(){
    int t;
    cin>>t;
    while (t-->0){
        cin>>n;
        for (int i=1; i<=n; ++i){
            cin>>vel[i];
        }
        // cout<<"cp1\n";
        set <float> time;
        time.insert(0);
        for (int i=1; i<=n; ++i){
            for (int j=1; j<=n; ++j){
                if ((i<j && vel[i]>vel[j]) || (i>j && vel[i]<vel[j])) time.insert((float)(j-i)/(vel[i]-vel[j]));
            }
        }
        time.insert(*(--(time.end()))+1);
        // cout<<"cp2\n";
        vector<vector<float>> race_at(time.size()-1, vector<float>(n));
        int t_size = time.size(),i=1;
        // cout<<t_size<<endl;
        auto it1 = time.end(),it = time.begin();
        it++;
        for (; it!=it1; ++it,++i){
            for (int j=0; j<n; ++j){
                race_at[i-1][j] = (j+1) + (vel[j+1] * (*it));
                // cout<<race_at[i-1][j]<<" ";
            }
            // cout<<endl;
        }
        // cout<<"cp3\n";
        int mini = INT_MAX,maxi = INT_MIN;
        for (int i=0; i<n; ++i){
            set <int> infected;
            infected.insert(i);
            // cout<<infected.size()<<" ";
            for (int j=0; j<t_size-1; ++j){
                for (auto p=infected.begin(); p!=infected.end(); ++p){
                    for (int k=0; k<n; ++k){
                        auto it = infected.begin();
                        if (race_at[j][k]==race_at[j][*p]) infected.insert(k);
                    }
                }
            }
            // cout<<infected.size()<<"\n";
            mini = min(mini, (int)infected.size());
            maxi = max(maxi, (int)infected.size());
        }
        cout<<mini<<" "<<maxi<<"\n";
    }
    return 0;
}


/*

#include <bits/stdc++.h>

using namespace std;

vector<int> vel(5);
int n;

int max_infection(int person ){
    int visited[n]={0};
    list<int> ready;
    set <int> infected;
    ready.push_back(person);
    while (!ready.empty()){
        int j = ready.front();
        ready.pop_front();
        if (!visited[j]){
            visited[j]=1;
            infected.insert(j);
            for (int i=0; i<n; ++i){
                if ((i<j && vel[i]>vel[j])||(i>j && vel[i]<vel[j])){
                    if (!visited[i]) ready.push_back(i);
                }
            }
        }
    }
    return infected.size();
}

int f2(int i){
    vector<int> temp(n);
        int t=1;
        for(int j=0; j<n; ++j){
            if ((i<j && vel[i]>vel[j])||(i>j && vel[i]<vel[j])) t++;
        }

    return t;
}

int main(){
    int t=1;
    //cin>>t;
    while (t){
        n=rand()%5 + 1;
        if (n<3){
            n = 3;
        }
        else if (n>5){
            n=5;
        }
        for (int i=0; i<n; ++i){
            vel[i] = rand()%6;
        }
        int mini = INT_MAX,maxi = INT_MIN,t1=INT_MAX,t2=INT_MIN,t;
        vector<int> temp(n);
        for (int i=0; i<n; ++i){
            temp[i]=max_infection(i);
            int t = f2(i);
            t1 = min(t1, t);
            t2 = max(t2, t);
            mini = min(mini, temp[i]);
            maxi = max(maxi, temp[i]);
        }
        if (t1==mini && t2==maxi){
            continue;
        }
        else{
            cout<<"Failed!!! \n";
            for (int i=0; i<n; i++){
                cout<<vel[i]<<" ";
            }
            cout<<endl;
            cout<<mini<<" "<<maxi<<endl;
            cout<<t1<<" "<<t2<<endl;
        }
    }
    return 0;
}


*/