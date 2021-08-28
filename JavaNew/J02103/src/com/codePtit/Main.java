package com.codePtit;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sn =new Scanner(System.in);
        int t = sn.nextInt();
        for (int x = 1; x <= t; x++) {
            int n = sn.nextInt();
            int m = sn.nextInt();
            int[][] a = new int[n][m];
            int[][] b = new int[m][n];
            int[][] c = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = sn.nextInt();
                    b[j][i] = a[i][j];
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    c[i][j] = 0;
                    for (int k = 0; k < m; k++) {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
            System.out.printf("Test %d:", x);
            System.out.println();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.printf("%d ", c[i][j]);
                }
                System.out.println();
            }
        }
    }
}
