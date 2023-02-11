#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

struct Position {
    int x;
    int y;

    Position(int _x, int _y) {
        x = _x;
        y = _y;
    }

    bool operator==(Position other) const {
        return x == other.x && y == other.y; 
    }
};

struct Move {
    char dir;
    int dist;

    Move(char _dir, int _dist) {
        dir = _dir;
        dist = _dist;
    }

    void print() const {
        cout << dir << dist << endl;
    }
};

class Maze {
    private:
    vector<vector<int>> positions;

    public:
    void read() {
        int n;
        cin >> n;
        positions = vector<vector<int>>(n);
        
        for (int i = 0; i < n; i++) {
            positions[i] = vector<int>(n);
            for (int j = 0; j < n; j ++) {
                int value;
                cin >> value;
                positions[i][j] = value;
            }
        }
    }

    int at(Position p) const {
        if (
            p.y >= 0 && p.y < positions.size() &&
            p.x >= 0 && p.x < positions[p.y].size()
        ) {
            return positions[p.y][p.x];
        } else {
            return 0;
        }
    }
};

class Solver {
    public:
    vector<vector<Move>> solutions = vector<vector<Move>>();

    void solve(
        const Maze& maze,
        Position from,
        Position to,
        vector<Move> previous,
        vector<Position> visited
    ) {
        if (from == to) {
            solutions.push_back(previous);
            return;
        } else {
            auto newVisited = vector<Position>(visited);
            newVisited.push_back(from);
            auto maxJump = maze.at(from);

            auto tryDirection = [
                this,
                maze,
                to,
                from,
                previous,
                maxJump,
                newVisited
            ](char dir, function<Position(Position, int)> calcP) {
                for (int jump = 1; jump <= maxJump; jump++) {
                    auto newPosition = calcP(from, jump);
                    if (maze.at(newPosition) != 0 && count(newVisited.begin(), newVisited.end(), newPosition) == 0) {
                        auto newMoves = vector<Move>(previous);
                        newMoves.push_back(Move(dir, jump));
                        solve(maze, newPosition, to, newMoves, newVisited);
                    }
                }
            };

            tryDirection('R', [](Position from, int jump) {
                return Position(from.x + jump, from.y);
            });
            tryDirection('D', [](Position from, int jump) {
                return Position(from.x, from.y + jump);
            });
            tryDirection('L', [](Position from, int jump) {
                return Position(from.x - jump, from.y);
            });
            tryDirection('U', [](Position from, int jump) {
                return Position(from.x, from.y - jump);
            });
        }
    }

    void printSolutions() const {
        if (solutions.size() == 0) {
            cout << "No path" << endl;
            return;
        }

        for (int i = 0; i < solutions.size(); i++) {
            cout << "Path no " << i + 1 << ":" << endl;
            for (auto move : solutions[i]) {
                move.print();
            }
        }
    }
};

Position readPosition() {
    int x, y;
    cin >> x >> y;
    return Position(x, y);
}

int main() {
    auto maze = Maze();
    maze.read();

    auto start = readPosition();
    auto end = readPosition();

    auto solver = Solver();
    solver.solve(maze, start, end, vector<Move>(), vector<Position>());
    solver.printSolutions();
    return 0;
}
