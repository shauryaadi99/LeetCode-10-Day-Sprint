class Solution {
public:
    int daysOfYear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int getDay(string str) {
        int month = stoi(str.substr(0, 2));
        int day = stoi(str.substr(3, 2));
        int total = day;
        for (int i = 0; i < month - 1; i++) {
            total += daysOfYear[i];
        }
        return total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int startAlice = getDay(arriveAlice);
        int endAlice = getDay(leaveAlice);

        int startBob = getDay(arriveBob);
        int endBob = getDay(leaveBob);

        int start = max(startAlice, startBob);
        int end = min(endAlice, endBob);
        return max(0, end - start + 1);
    }
};