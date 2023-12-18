package week12;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class Q1 {

    public static void main(String[] args) throws IOException {

        try {
            File f = new File("test.txt");
            InputStream fin = new FileInputStream(f);
            Scanner obj = new Scanner(fin);
            String str = obj.nextLine();
            System.out.println(str);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
