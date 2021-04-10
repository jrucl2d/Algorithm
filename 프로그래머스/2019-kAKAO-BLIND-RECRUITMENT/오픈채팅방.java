import java.util.*;
class Solution {
        static final int ENTER = 0;
        static final int LEAVE = 1;

        public String[] solution(String[] record) {
            Map<String, String> map = new HashMap<>();
            List<Info> list = new ArrayList<>();
            for (String r : record) {
                String[] split = r.split(" ");
                if (split[0].equals("Enter")) {
                    map.put(split[1], split[2]);
                    list.add(new Info(split[1], ENTER));
                    continue;
                }
                if (split[0].equals("Leave")) {
                    list.add(new Info(split[1], LEAVE));
                    continue;
                }
                map.put(split[1], split[2]);
            }
            List<String> tmp = new ArrayList<>();
            for (Info info : list) {
                if (info.doing == ENTER) {
                    tmp.add(map.get(info.id) + "님이 들어왔습니다.");
                    continue;
                }
                tmp.add(map.get(info.id) + "님이 나갔습니다.");
            }
            String[] answer = new String[tmp.size()];
            for (int i = 0; i < tmp.size(); i++) {
                answer[i] = tmp.get(i);
            }
            return answer;
        }
        class Info {
            String id;
            int doing;
            Info(String a, int b){id=a;doing=b;}
        }
}