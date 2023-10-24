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
public class Square extends Applet {
    public void paint(Graphics g){
        g.drawRect(10,10,100,100);
        g.setColor(Color.blue);
        g.drawLine(10, 10, 110, 110);
        g.setColor(Color.green);
        g.drawLine(10, 110, 110, 10);
        g.setColor(Color.red);
        g.fillRect(120, 10, 100, 100);
    }
}

