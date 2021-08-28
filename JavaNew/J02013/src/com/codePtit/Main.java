package com.codePtit;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sn = new Scanner(System.in);
        int n = sn.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sn.nextInt();
        }
        boolean check = false;
        for (int i = 0; i < n - 1; i++) {
            check = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                    check =true;
                }
            }
            if (!check) {
                break;
            }
            System.out.printf("Buoc %d: ", i + 1);
            for (int k = 0; k < n; k++) {
                System.out.printf("%d ", a[k]);
            }
            System.out.println();
        }
    }
}
