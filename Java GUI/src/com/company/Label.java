package com.company;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;

public class Label extends JLabel {
    Label() {
        ImageIcon icon = new ImageIcon("snow_logo.png");

        Border border = BorderFactory.createLineBorder(new Color(0x4a4a4a), 3);

        this.setText("Snow");
        this.setIcon(icon);
        this.setHorizontalTextPosition(JLabel.CENTER);
        this.setVerticalTextPosition(JLabel.BOTTOM);
        this.setForeground(new Color(0xffffff));
        this.setFont(new Font("Serif", Font.PLAIN, 20));
        this.setIconTextGap(10);
        this.setBackground(new Color(0x004c70));
        this.setOpaque(true);
        this.setBorder(border);
        this.setBounds(0, 0, 430, 450);
    }
}
