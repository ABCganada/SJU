package week12;

import java.io.*;
import java.util.Scanner;

public class Q6 {

    public static void main(String[] args) {

        File f = new File("newFile.txt");

        try {
            Scanner sc = new Scanner(System.in);
            System.out.print("Enter your name:");
            String line1 = sc.nextLine();
            System.out.print("Enter your id:");
            String line2 = sc.nextLine();
            System.out.print("Enter your age:");
            String line3 = sc.nextLine();

            FileWriter fw = new FileWriter(f);
            fw.write("NAME:" + line1 + "\n");
            fw.write("ID:" + line2 + "\n");
            fw.write("AGE:" + line3 + "\n");
            fw.close();

            FileReader fr = new FileReader(f);
            Scanner scr = new Scanner(fr);

            while (scr.hasNext()) {
                String str = scr.nextLine();
                System.out.println(str);
            }

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
