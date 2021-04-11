import java.util.*;
class Solution {
        public int solution(int[] food_times, long k) {
            int n = food_times.length;
            Queue<Info> q = new PriorityQueue<>(n, (a, b) -> a.val - b.val);
            int outer_sum = 0;
            for (int i = 0; i < n; i++) {
                outer_sum += food_times[i];
                q.add(new Info(i + 1, food_times[i]));
            }
            if (outer_sum <= k) return -1;
            int prev = 0;
            int the_sum = 0;
            int food_count = n;
            while (true) {
                Info now = q.remove();
                int min_val = now.val;
                if(the_sum + (min_val - prev) * food_count > k) {
                    q.add(now); break;
                }
                the_sum += (min_val - prev) * food_count;
                prev = min_val;
                food_count -= 1;
            }
            Info[] list = q.stream().toArray(Info[]::new);
            Arrays.sort(list, (a, b) -> a.num - b.num);
            return list[(int)((k - the_sum) % food_count)].num;
        }
        class Info {
            int num;
            int val;
            Info(int a, int b){num=a;val=b;}
        }
    }