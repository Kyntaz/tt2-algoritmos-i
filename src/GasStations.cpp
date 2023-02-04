// Solution for https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3743
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long number;

int main() {
    number L, G;
    while (cin >> L >> G) {
        // End of the test cases.
        if (L == 0 && G == 0) {
            break;
        }

        vector<pair<int, int>> stations;

        // Read stations and store their information.
        for (number i = 0; i < G; i++) {
            number center, radius;
            cin >> center >> radius;
            // We only care about the range of a station within the road, so lets trim it.
            stations.push_back(make_pair(max(center - radius, 0ll), min(center + radius, L)));
        }

        // Custom sort so that we have stations in the right order.
        // Stations whose influence starts first on the road, come first.
        // If there's a tie, stations whose influence ends later on the road come first.
        sort(stations.begin(), stations.end(), [](pair<int, int> p1, pair<int, int> p2) {
            if (p1.first != p2.first) {
                return p1.first < p2.first;
            } else {
                return p1.second > p2.second;
            }
        });

        // If the first station doesn't cover the start of the road,
        // stop right here and return -1.
        if (stations[0].first > 0) {
            cout << -1 << endl;
            continue;
        }

        // The first station is always open.
        vector<pair<int, int>> openStations = vector<pair<int, int>>();
        openStations.push_back(stations[0]);

        pair<int, int> potentialStation = make_pair(0, 0);

        for (number i = 1; i < stations.size(); i++) {
            // If this station doesn't cover any road portion that
            // isn't already covered by the last open station,
            // don't open it and move on to the next one.
            if (stations[i].second <= openStations.back().second) {
                continue;
            }

            // If this this station overlaps the last opened station,
            // let's consider it to be opened.
            if (stations[i].first <= openStations.back().second) {
                // If this station's reach goes farther than the previously
                // considered station to be next in line, discard the previous
                // potential station in favor of this one.
                if (potentialStation.second <= stations[i].second) {
                    potentialStation = stations[i];
                }
            } else {
                // If this station doesn't overlap the last opened one,
                // we need to open one more station -- the one that was last
                // considered as a potential station to be opened, as that one
                // will cover the most length of the road.
                if (potentialStation != make_pair(0, 0)) {
                    openStations.push_back(potentialStation);
                    potentialStation = make_pair(0, 0);
                    i--;
                } else {
                    // If there was no potential station, that means
                    // there will always be a part of the road that
                    // won't be covered, so we can stop checking stations.
                    break;
                }
            }
        }

        // If there was a potential station at the end that wasn't opened yet,
        // let's open it.
        if (potentialStation != make_pair(0, 0)) {
            openStations.push_back(potentialStation);
        }

        // If the influence of the last opened station doesn't cover the
        // end of the road, we can't cover the entire road, so let's return -1.
        // Otherwise, let's close all stations that weren't marked to be opened (G - #open).
        if (openStations.back().second >= L) {
            cout << G - openStations.size() << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}
