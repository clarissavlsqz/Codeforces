#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*

You have a room that's W wide and L long. You also receive the coordinates of
sensors inside that room and their detection radius.

Code a function that returns True or False, whether someone (infinitessimally small) can
or can't make it from the left side of the room to the right side  of the room

Input:

int Height
int Length
vector<Sensor> SensorList;

struct Sensor {
  int radius; // can be any length!
  int xCoord;
  int yCoord;
}

*/

struct Sensor {
  int radius; // can be any length!
  int xCoord;
  int yCoord;
};

struct SensorNode {
    Sensor *s;
    vector<SensorNode> LinkedSensors = {};
};

// Check the position of the sensor
// The radius of the sensor if the radius is bigger than the room
// If its bigger then the person can't go through the room
// Otherwise it can

/*bool checkRoom(int h, int l, Sensor s) {
  int yCordRTop = s.yCoord + s.radius;
  int yCordRBotton = s.yCoord - s.radius;
  
  if (yCordRTop >= h && yCordRBotton <= 0) {
    return false;
  }
  
  return true;
      
      
}*/

// isConnected makes the mathematical procedure to calculate if the sensors are overlapping, it returns True if they overlap otherwise false;
bool isConneted(Sensor s1, Sensor s2) {
    int dx = s1.xCoord - s2.xCoord;
    int dy = s1.yCoord - s2.yCoord;
    int d2 = (dx*dx) + (dy*dy);
    int r2 = (s1.radius+s2.radius)*(s1.radius+s2.radius);
    return r2 <= d2;
}

// checkRoom2 is the main function to see if the room is passable or not
bool checkRoom2(int h, int l, vector<Sensor> SensorList) {
    // top and bottom will help to see if a sensor overlaps with the top and bottom wall
    int top = -1;
    int bottom = -2;
    
    vector<vector<int>> graph;
    
    // makes the graph
    for (int i = 0; i < SensorList.size(); i++) {
        for (int j = 0; j < SensorList.size(); j++) {
            if (i == j) continue;
            if (isConneted(SensorList[i], SensorList[j])) {
                graph[i].push_back(j);
            }
        }
        // checks if the sensors overlaps with the top or bottom wall, if it does then it adds it as a vertice to the sensor
        if (SensorList[i].yCoord + SensorList[i].radius >= h) {
            graph[i].push_back(top);
        } else if (SensorList[i].yCoord - SensorList[i].radius <= 0) {
            graph[i].push_back(bottom);
        }
    }
    
    // BFS
    vector<bool> seen; // helps to not check that node
    queue<int> q;
    bool flag = false;
    q.push(graph[0][0]);
    seen[0] = true;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (auto &i: graph[tmp]) {
            if (seen[i]) continue;
            // if see the top then we mark a flag
            if (i == top) {
                flag = true;
                continue;
            }
            // if we have seen the top and bottom then the room isn't passable
            if (flag && i == bottom) return false;
            seen[i] = true;
            q.push(i);
        }
    }
    
    return true;

}
