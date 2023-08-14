package JAVA;
public class MagicSquare {
    public static void generateMagicSquare(int n) {
        int[][] magicSquare = new int[n][n];

        int row = n / 2;
        int col = n - 1;

        for (int num = 1; num <= n * n; ) {
            if (row == -1 && col == n) {
                row = 0;
                col = n - 2;
            } else {
                if (col == n) {
                    col = 0;
                }
                if (row < 0) {
                    row = n - 1;
                }
            }
            if (magicSquare[row][col] != 0) {
                row++;
                col -= 2;
                continue;
            } else {
                magicSquare[row][col] = num++;
                }
            row--;
            col++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(magicSquare[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int n = 3;
        generateMagicSquare(n);
    }
}
