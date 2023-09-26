package assignment1.q1;

import javax.swing.*;

class Student{
    String name;
    int n, id;
}

public class Q1 {

    public static void main(String[] args){

        Student st1 = new Student();
        Student st2 = new Student();

        String input = JOptionPane.showInputDialog("Student: ");
        st1.n = Integer.parseInt(input);
        input = JOptionPane.showInputDialog("Name: ");
        st1.name = input;
        input = JOptionPane.showInputDialog("Id: ");
        st1.id = Integer.parseInt(input);

        input = JOptionPane.showInputDialog("Student: ");
        st2.n = Integer.parseInt(input);
        input = JOptionPane.showInputDialog("Name: ");
        st2.name = input;
        input = JOptionPane.showInputDialog("Id: ");
        st2.id = Integer.parseInt(input);

        if(st1.id == st2.id || st1.name.equals(st2.name)){
            JOptionPane.showMessageDialog(null, "Duplicate entry", "result", JOptionPane.ERROR_MESSAGE);
        } else{
            JOptionPane.showMessageDialog(null, "Student: " + st1.n + "\n" + "Name: " + st1.name + "\n" +
                    "Id: " + st1.id + "\n" + "Student: " + st2.n + "\n" + "Name: " + st2.name + "\n" + "Id: " + st2.id,
                    "result", JOptionPane.INFORMATION_MESSAGE);

        }
    }
}
