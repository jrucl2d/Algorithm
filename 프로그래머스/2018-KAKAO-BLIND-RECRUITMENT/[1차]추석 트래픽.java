class Solution {
    Time[] times;
    public int solution(String[] lines) {
        times = new Time[lines.length];
        if (lines.length == 1) return 1;
        for (int i = 0; i < lines.length; i++) {
            String line = lines[i];
            String[] now = line.split(" ");
            String[] time_string = now[1].split(":");
            int hour = Integer.valueOf(time_string[0]);
            int minute = Integer.valueOf(time_string[1]);
            double second = Double.valueOf(time_string[2]);
            double during = Double.valueOf(now[2].substring(0, now[2].length() - 1));
            double end = hour * 3600 + minute * 60 + second;
            times[i] = new Time(Math.round((end - during + 0.001) * 1000) / 1000.0, end);
        }
        int ans = 0;
        for (int i = 0; i < times.length; i++) {
            int inner_cnt = 1;
            double border = times[i].end + 1 - 0.001;
            border = Math.round(border * 1000) / 1000.0;
            for (int j = i + 1; j < times.length; j++) {
                double now = times[j].start;
                if (Math.round(now * 1000) / 1000.0 <= border) inner_cnt += 1;
            }
            ans = Math.max(inner_cnt, ans);
        }
        return ans;
    }
    class Time {
        double start;
        double end;
        Time(double a, double b){start=a;end=b;}
    }
}