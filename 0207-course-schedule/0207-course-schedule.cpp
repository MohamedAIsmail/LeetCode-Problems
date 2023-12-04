class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Create an adjacency list to represent the graph
    vector<vector<int>> adjacencyList(numCourses);
    
    // Keep track of the in-degrees of each course
    vector<int> inDegrees(numCourses, 0);

    // Build the graph and update in-degrees
    for (auto& prerequisite : prerequisites) {
        int courseToTake = prerequisite[0];
        int prerequisiteCourse = prerequisite[1];

        // Add an edge from prerequisite to course
        adjacencyList[prerequisiteCourse].push_back(courseToTake);

        // Increment the in-degree of the course to be taken
        inDegrees[courseToTake]++;
    }

    // Initialize a queue with courses having in-degree 0
    queue<int> zeroInDegreeCourses;
    for (int i = 0; i < numCourses; ++i) {
        if (inDegrees[i] == 0) {
            zeroInDegreeCourses.push(i);
        }
    }

    // Perform topological sort
    int coursesTaken = 0;
    while (!zeroInDegreeCourses.empty()) {
        // Take a course with in-degree 0
        int currentCourse = zeroInDegreeCourses.front();
        zeroInDegreeCourses.pop();
        
        // Increment the count of courses taken
        coursesTaken++;

        // Update in-degrees of neighbors and enqueue if in-degree becomes 0
        for (auto& neighbor : adjacencyList[currentCourse]) {
            inDegrees[neighbor]--;

            // If the neighbor's in-degree becomes 0, enqueue it
            if (inDegrees[neighbor] == 0) {
                zeroInDegreeCourses.push(neighbor);
            }
        }
    }

    // Check if all courses can be taken (no cycles)
    return coursesTaken == numCourses;
}
};