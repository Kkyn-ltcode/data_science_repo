package com.codePtit.J01012;

import java.util.Scanner;

public class J01012 {

    public static void main(String[] args) {
        Scanner sn = new Scanner(System.in);
        int t = sn.nextInt();
        while (t-->0) {
            long c = 0;
            long n = sn.nextLong();
            for (long i = 2; i * i < n; i+=2) {
                if (n % i == 0) {
                    c++;
                }
            }
            for (long i = (int)Math.sqrt(n); i >= 1; i--) {
                if (n % i == 0 && (n / i) % 2 == 0) {
                    c++;
                }
            }
            System.out.println(c);
        }
    }
}
