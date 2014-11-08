/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Nobel Khandaker
 */
public class BitAddition {

    public static int add(int x, int y) {

        int xor, and, temp;
        and = x & y;
        xor = x ^ y;

        while (and != 0) {
            and <<= 1;
            temp = xor ^ and;
            and &= xor;
            xor = temp;
        }
        return xor;
    }
    

    public static void main(String[] args) {

        //System.out.println(BitAddition.add(20, 2));
    }
}