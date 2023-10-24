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
public class Circle extends Applet {
    public void paint(Graphics g){
        g.setColor(Color.green);
        g.fillOval( 10, 10, 100, 100 );
        g.fillOval( 120, 10, 100, 100 );
        g.setColor(Color.red);
        g.fillArc(10, 10, 100, 100, 0, 90);
    }
}
