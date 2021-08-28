package com.codePtit.J01002;

import java.util.Scanner;

public class J01002 {
    public static void main(String[] args) {
        Scanner sn = new Scanner(System.in);
        int t = sn.nextInt();
        while (t-->0) {
            int n = sn.nextInt();
            System.out.println((1 + n) * n / 2);
        }
    }
}
