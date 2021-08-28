package com.codePtit.J02012;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sn = new Scanner(System.in);
        int n = sn.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sn.nextInt();
        }
        System.out.printf("Buoc 0: %d",a[0]);
        System.out.println();
        for (int i = 1; i < n; i++) {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j -= 1;
            }
            a[j + 1] = key;
            System.out.printf("Buoc %d: ", i);
            for (int k = 0; k <= i; k++) {
                System.out.printf("%d ", a[k]);
            }
            System.out.println();
        }
    }
}
