package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Frame extends JFrame implements  ActionListener{

    JButton button;
    ImageIcon icon;
    Frame() {
        icon = new ImageIcon("snow_logo.png");

        button = new JButton();
        button.setBounds(100, 100, 250, 100);
        button.addActionListener(this);
        button.setText("Snow");
        button.setFocusable(false);
        button.setIcon(icon);
        button.setHorizontalTextPosition(JButton.CENTER);
        button.setVerticalTextPosition(JButton.CENTER);
        button.setFont(new Font("Serif", Font.PLAIN, 25));
        button.setForeground(new Color(0x004c70));
        button.setBorder(BorderFactory.createEtchedBorder(0, new Color(0x4a4a4a) ,new Color(0x004c70)));

        this.setSize(500, 500);
        this.setTitle("Java Frame");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(null);
        this.add(button);
        this.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Label label = new Label();

        JFrame frame = new JFrame();
        frame.setSize(430, 450);
        frame.setLayout(null);

        if (e.getSource() == button) {
            button.setEnabled(false);
        }

        frame.add(label);
        frame.setVisible(true);
    }
}
