#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n;
    cin >> n;
    // event is either 0: start, 1: end
    //(time t, event, person i)
    vector<tuple<ll, ll, ll>> events;
    for(ll i = 0; i < n; i++) {
        ll a; ll b;
        cin >> a >> b;
        events.push_back(make_tuple(a, 0, i));
        events.push_back(make_tuple(b, 1, i));
    }

    vector<ll> personToRoom(n);
    set<ll> rooms;
    ll numOfRooms = 0;
    sort(events.begin(), events.end());

    for(tuple<ll,ll,ll> event : events) {
        ll t = get<0>(event);
        ll e = get<1>(event);
        ll i = get<2>(event);
        //cout << "event: " << t << ", " << e << ", " << i << "\n"; 
        if (e == 0) {
            auto room = rooms.begin();
            if (room == rooms.end()) {
                //all rooms are full meaning we need another room
                numOfRooms++;
                personToRoom[i] = numOfRooms;
            } else {
                personToRoom[i] = *room;
                rooms.erase(*room);
            }
        } else {
            rooms.insert(personToRoom[i]);
        }
    }
    cout << numOfRooms << "\n";
    for(ll i = 0; i < n; i++) cout << personToRoom[i] << " ";
    return 0;
}