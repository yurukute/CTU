/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package buoi2.applet;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author student
 */
public class Triangle extends Applet {
    public void paint(Graphics g) {
        int x[] = {120, 20, 70};
        int y[] = {120, 120, 20};
        
        g.setColor(Color.yellow);
        g.fillPolygon(x, y, 3);
        
        g.setColor(Color.black);
        g.drawPolygon(x, y, 3);
        
        for (int i = 0; i < 3; i++) {
            x[i] += 150;
        }
        
        g.setColor(Color.red);
        g.drawPolygon(x, y, 3);
    }
}
