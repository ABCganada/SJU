package week11;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

class Student {
    String name;
    int age;
    double GPA;

    public Student(String name, int age, double GPA) {
        this.name = name;
        this.age = age;
        this.GPA = GPA;
    }
}

public class Q2 {

    public static void main(String[] args) {

        JFrame frame = new JFrame("GPA");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        ArrayList<Student> studentArrayList = new ArrayList<>();

        for (int i = 0; i < 4; i++) {
            String name = JOptionPane.showInputDialog("Enter student" + (i+1) + " name");
            int age = Integer.parseInt(JOptionPane.showInputDialog("Enter student" + (i+1) + " age"));
            double GPA = Double.parseDouble(JOptionPane.showInputDialog("Enter student" + (i+1) + " GPA score"));

            Student student = new Student(name, age, GPA);
            studentArrayList.add(student);
        }

        Student oldAgeStudent = studentArrayList.get(0);
        for (int i = 1; i < studentArrayList.size(); i++) {
            oldAgeStudent = oldAgeStudent.age > studentArrayList.get(i).age ? oldAgeStudent : studentArrayList.get(i);
        }

        Student highGPAStudent = studentArrayList.get(0);
        for (int i = 1; i < studentArrayList.size(); i++) {
            highGPAStudent = highGPAStudent.GPA > studentArrayList.get(i).GPA ? highGPAStudent : studentArrayList.get(i);
        }

        JOptionPane.showMessageDialog(null, "Name: " + oldAgeStudent.name + "\n"
                + "Age: " + oldAgeStudent.age + "\n" + "GPA: " + oldAgeStudent.GPA, "Oldest age student info", JOptionPane.INFORMATION_MESSAGE);

        JOptionPane.showMessageDialog(null, "Name: " + highGPAStudent.name + "\n"
                + "Age: " + highGPAStudent.age + "\n" + "GPA: " + highGPAStudent.GPA, "Highest GPA student info", JOptionPane.INFORMATION_MESSAGE);

        frame.pack();
        frame.setVisible(true);
    }
}
