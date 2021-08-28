package com.codePtit.J01011;

import java.util.Scanner;

public class J01011 {
    public static void main(String[] args) {
        Scanner sn =new Scanner(System.in);
        int t = sn.nextInt();
        while (t-->0) {
            long a = sn.nextLong();
            long b = sn.nextLong();
            long res = gcd(a, b);
            System.out.printf("%d %d", (a * b) / res, res);
            System.out.println();
        }
    }
    static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
