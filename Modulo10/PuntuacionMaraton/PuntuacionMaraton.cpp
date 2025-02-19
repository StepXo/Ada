#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Team {
    int id;
    int problems_solved = 0;
    int penalty_time = 0;
    unordered_map<int, pair<int, bool>> problems; 
};

bool compareTeams(const Team& a, const Team& b) {
    if (a.problems_solved != b.problems_solved) {
        return a.problems_solved > b.problems_solved;
    }
    if (a.penalty_time != b.penalty_time) {
        return a.penalty_time < b.penalty_time;
    }
    return a.id < b.id;
}

void processMarathon(int marathon_number, int R) {
    unordered_map<int, Team> teams;
    
    for (int i = 0; i < R; i++) {
        int team_id, problem_id, time;
        char result;
        cin >> team_id >> problem_id >> time >> result;
        
        if (!teams.count(team_id)) {
            teams[team_id] = {team_id};
        }

        Team& team = teams[team_id];
        
        if (result == 'C') {
            if (!team.problems[problem_id].second) { 
                team.problems[problem_id].second = true;
                team.problems_solved++;
                team.penalty_time += time + team.problems[problem_id].first * 20;
            }
        } else if (result == 'I') {
            team.problems[problem_id].first++; 
        }
    }
    
    vector<Team> results;
    for (const auto& entry : teams) {
        if (entry.second.problems_solved > 0) {
            results.push_back(entry.second);
        }
    }
    
    sort(results.begin(), results.end(), compareTeams);
    
    cout << "maraton " << marathon_number << ":\n";
    for (const auto& team : results) {
        cout << team.id << " " << team.problems_solved << " " << team.penalty_time << "\n";
    }
    cout << "\n";
}

int main() {
    int M;
    cin >> M;
    
    for (int i = 1; i <= M; i++) {
        int R;
        cin >> R;
        processMarathon(i, R);
    }
    
    return 0;
}
