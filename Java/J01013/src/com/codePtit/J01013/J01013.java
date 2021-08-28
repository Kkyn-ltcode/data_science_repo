package com.codePtit.J01013;

import java.util.Scanner;

public class J01013 {

    public static void main(String[] args) {
        Scanner sn = new Scanner(System.in);
        int n = sn.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sn.nextInt();
        }
        int res = primeExtract(a, n);
        System.out.println(res);
    }

    static int primeExtract(int[] a, int n) {
        /*int res = 0;
        for (int i = 0; i < n; i++) {
            while (a[i] % 2 == 0) {
                res += 2;
                a[i] /= 2;
            }
        }
        for (int i = 3; i <= Math.sqrt(n); i+=2) {
            for (int j = 0; j < n; j++) {
                while (a[j] % i == 0) {
                    res += i;
                    a[j] /= i;
                }
            }
        }
        if (n > 2) {
            res += n;
        }
        return res;*/
        int k = 2;
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (k <= Math.sqrt(a[i])) {
                while (a[i] % k == 0) {
                    res += k;
                    a[i] /= k;
                }
                if (k == 2) {
                    k += 1;
                } else {
                    k += 2;
                }
            }
            if (a[i] > 2) {
                res += a[i];
            }
            k= 2;
        }
        return res;
    }
}
