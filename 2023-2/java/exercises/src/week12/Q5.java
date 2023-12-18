package week12;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Q5 {

    public static void main(String[] args) throws IOException {

        try {
            FileWriter fw = new FileWriter("writeTest.txt");
            Scanner sc = new Scanner(System.in);
            String str = sc.nextLine();
            fw.write(str);
            fw.close();

            FileReader fr = new FileReader("writeTest.txt");
            Scanner scr = new Scanner(fr);
            str = scr.nextLine();
            System.out.println(str);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
