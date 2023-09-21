package wrapper;

import javax.swing.*;

public class WrapperClass {

    public static void main(String[] args){

        Float obj = Float.parseFloat("12.33");
        Float num = Float.valueOf("12.33");
        Integer intNum = Integer.valueOf("12");
        Integer test = Integer.valueOf(12);

        System.out.println(obj);
        System.out.println(num);
        System.out.println(intNum);
        System.out.println(test);

        int number = Integer.parseInt(JOptionPane.showInputDialog("Enter Quantity"));
    }
}
