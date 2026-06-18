class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = 6 * minutes;
        double hourAngle = 30 * (hour % 12) + 0.5 * minutes;
        double x = abs(minuteAngle - hourAngle);
        return min(x, 360 - x);
    }
};