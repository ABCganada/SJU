package week12;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class Q2 {

    public static void main(String[] args) throws IOException {

        try {
            InputStream f = new FileInputStream("test.txt");
            Scanner sc = new Scanner(f);
            String str = sc.nextLine();
            System.out.println(str);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
