package com.codePtit;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sn = new Scanner(System.in);
        int n = sn.nextInt();
        String[] b = new String[1000000];
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = sn.nextInt();
                if (tmp == 1 && j > i) {
                    b[k++] = "(" + (i + 1) + "," + (j + 1) + ")";
                }
            }
        }
        for (int i = 0; i < k; i++) {
            System.out.println(b[i]);
        }
    }
}
