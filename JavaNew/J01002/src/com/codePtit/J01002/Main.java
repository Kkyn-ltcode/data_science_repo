package com.codePtit.J01002;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sn = new Scanner(System.in);
        int t = sn.nextInt();
        while (t-->0) {
            long n = sn.nextLong();
            System.out.println((1 + n) * n / 2);
        }
    }
}
