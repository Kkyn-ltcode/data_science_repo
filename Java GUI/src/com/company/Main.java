package com.company;

import javax.swing.*;
import java.awt.*;

public class Main {

    public static void main(String[] args) {
        JFrame frame = new JFrame();
        frame.setSize(500, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout());
        for (int i = 1; i <= 9; i++) {
            frame.add(new JButton("" + i));
        }
        frame.setVisible(true);
    }
}
