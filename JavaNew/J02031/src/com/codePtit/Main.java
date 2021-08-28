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
        intersectionSort(a, n, 0);
    }

    static void intersectionSort(int[] a, int n, int step) {
        int min = step;
        for (int j = step + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        int tmp = a[step];
        a[step] = a[min];
        a[min] = tmp;
        int[] b = a;
        if (step != n - 2) {
            intersectionSort(a, n, step + 1);
        }
        System.out.printf("Buoc %d: ", step + 1);
        for (int j = 0; j < n; j++) {
            System.out.printf("%d ", b[j]);
        }
        System.out.println();
    }

}

