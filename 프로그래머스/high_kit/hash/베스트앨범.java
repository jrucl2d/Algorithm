class Solution {
    public int[] solution(String[] genres, int[] plays) {
        int n = genres.length;
        Map<String, Info> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String genre = genres[i];
            if (map.containsKey(genre)) {
                Info before = map.get(genre);
                before.total += plays[i];
                before.list.add(new InnerInfo(i, plays[i]));
                map.put(genre, before);
            } else {
                Info info = new Info();
                info.total = plays[i];
                info.list.add(new InnerInfo(i, plays[i]));
                map.put(genre, info);
            }
        }
        PriorityQueue<Info> infos = new PriorityQueue<>((a, b) -> b.total - a.total);
        for (String key : map.keySet()) {
            infos.add(map.get(key));
        }
        List<Integer> ans = new ArrayList<>();
        while (!infos.isEmpty()) {
            Info now = infos.remove();
            for (int i = 0; i < 2; i++) {
                if (now.list.isEmpty()) break;
                ans.add(now.list.remove().num);
            }
        }
        int[] ret = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) ret[i] = ans.get(i);
        return ret;
    }
    class Info {
        int total;
        PriorityQueue<InnerInfo> list = new PriorityQueue<>((a, b) -> {
            if (a.play == b.play) return a.num - b.num;
            return b.play - a.play;
        });
    }
    class InnerInfo {
        int num;
        int play;
        InnerInfo(int num, int play) {this.num=num;this.play=play;}
    }
}
