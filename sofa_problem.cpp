#include <cstdint>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

// Represents a position of the sofa (two connected cells)
struct SofaState {
    int x1, y1;  // First 's' position
    int x2, y2;  // Second 's' position
    int steps;

    SofaState(int x1, int y1, int x2, int y2, int steps) 
        : x1(x1), y1(y1), x2(x2), y2(y2), steps(steps) {}

    // For storing in set to track visited states
    bool operator<(const SofaState& other) const {
        if (x1 != other.x1) return x1 < other.x1;
        if (y1 != other.y1) return y1 < other.y1;
        if (x2 != other.x2) return x2 < other.x2;
        return y2 < other.y2;
    }
};

class Room {
   public:
    Room(uint8_t M, uint8_t N) : M_(M), N_(N) {
        data_ = new char[M * N];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> data_[i * N + j];
            }
        }
    }

    ~Room() {
        delete[] data_;
    }

    void print() {
        for (int i = 0; i < M_; i++) {
            for (int j = 0; j < N_; j++) {
                std::cout << data_[i * N_ + j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool isValid(int x, int y) {
        return x >= 0 && x < M_ && y >= 0 && y < N_ && data_[x * N_ + y] != 'H';
    }

    // Check if we can rotate at position (x,y) - needs a 2x2 area of '0's
    bool canRotate(int x, int y) {
        for(int i = x; i < x + 2; i++) {
            for(int j = y; j < y + 2; j++) {
                if (!isValid(i, j) || data_[i * N_ + j] == 'H') 
                    return false;
            }
        }
        return true;
    }

    int findMinSteps() {
        // Find start ('s') positions
        vector<pair<int,int>> start_pos;
        vector<pair<int,int>> target_pos;
        
        for (int i = 0; i < M_; i++) {
            for (int j = 0; j < N_; j++) {
                if (data_[i * N_ + j] == 's') {
                    start_pos.push_back({i, j});
                } else if (data_[i * N_ + j] == 'S') {
                    target_pos.push_back({i, j});
                }
            }
        }

        if (start_pos.size() != 2 || target_pos.size() != 2) return -1;

        queue<SofaState> q;
        set<SofaState> visited;

        SofaState initial(start_pos[0].first, start_pos[0].second,
                         start_pos[1].first, start_pos[1].second, 0);
        q.push(initial);
        visited.insert(initial);

        // Possible moves for translation
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            SofaState curr = q.front();
            q.pop();

            // Check if we reached target
            if ((curr.x1 == target_pos[0].first && curr.y1 == target_pos[0].second &&
                 curr.x2 == target_pos[1].first && curr.y2 == target_pos[1].second) ||
                (curr.x1 == target_pos[1].first && curr.y1 == target_pos[1].second &&
                 curr.x2 == target_pos[0].first && curr.y2 == target_pos[0].second)) {
                return curr.steps;
            }

            // Try translations
            for (int i = 0; i < 4; i++) {
                int new_x1 = curr.x1 + dx[i];
                int new_y1 = curr.y1 + dy[i];
                int new_x2 = curr.x2 + dx[i];
                int new_y2 = curr.y2 + dy[i];

                if (isValid(new_x1, new_y1) && isValid(new_x2, new_y2)) {
                    SofaState next(new_x1, new_y1, new_x2, new_y2, curr.steps + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // Try rotations if sofa is vertical
            if (curr.x1 == curr.x2 - 1 && curr.y1 == curr.y2) {
                // Try rotating around bottom-left corner of 2x2 area
                if (canRotate(curr.x1, curr.y1 - 1)) {
                    SofaState next(curr.x1, curr.y1 - 1, curr.x1, curr.y1, curr.steps + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
                if (canRotate(curr.x1, curr.y1)) {
                    SofaState next(curr.x1, curr.y1, curr.x1, curr.y1 + 1, curr.steps + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            // Try rotations if sofa is horizontal
            else if (curr.x1 == curr.x2 && curr.y1 == curr.y2 - 1) {
                // Try rotating around top-left corner of 2x2 area
                if (canRotate(curr.x1, curr.y1)) {
                    SofaState next(curr.x1, curr.y1, curr.x1 + 1, curr.y1, curr.steps + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
                if (canRotate(curr.x1 - 1, curr.y1)) {
                    SofaState next(curr.x1 - 1, curr.y1, curr.x1, curr.y1, curr.steps + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }

        return -1;  // No path found
    }

   private:
    uint8_t M_;
    uint8_t N_;
    char* data_;
};

int main() {
    uint8_t M, N;
    std::cin >> M >> N;
    
    Room room(M, N);
    int steps = room.findMinSteps();
    
    if (steps != -1) {
        std::cout << "Minimum steps required: " << steps << std::endl;
    } else {
        std::cout << "No valid path found!" << std::endl;
    }
    
    return 0;
}
