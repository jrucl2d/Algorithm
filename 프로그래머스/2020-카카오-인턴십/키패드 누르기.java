class Solution {
    public String solution(int[] numbers, String hand) {
        Point[] points = new Point[10];
        int points_index = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                points[points_index++] = new Point(i, j);
            }
        }
        points[0] = new Point(3, 1);
        Point left = new Point(3, 0);
        Point right = new Point(3, 2);
        StringBuilder sb = new StringBuilder();
        for (int number : numbers) {
            switch (number) {
                case 1:
                case 4:
                case 7:
                    sb.append('L');
                    left.x = points[number].x;
                    left.y = points[number].y;
                    break;
                case 3:
                case 6:
                case 9:
                    sb.append('R');
                    right.x = points[number].x;
                    right.y = points[number].y;
                    break;
                default:
                    int left_dist = Math.abs(points[number].x - left.x) + Math.abs(points[number].y - left.y);
                    int right_dist = Math.abs(points[number].x - right.x) + Math.abs(points[number].y - right.y);
                    if (left_dist < right_dist) {
                        sb.append('L');
                        left.x = points[number].x;
                        left.y = points[number].y;
                        break;
                    }
                    if (left_dist > right_dist) {
                        sb.append('R');
                        right.x = points[number].x;
                        right.y = points[number].y;
                        break;
                    }
                    if (hand.equals("left")) {
                        sb.append('L');
                        left.x = points[number].x;
                        left.y = points[number].y;
                        break;
                    }
                    sb.append('R');
                    right.x = points[number].x;
                    right.y = points[number].y;
                    break;
            }
        }
        return sb.toString();
    }
    class Point{
        int x, y;
        Point(int a, int b) {x=a;y=b;}
    }
}