package exercise;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class Q1 {

    public static void main(String[] args) {
        File f = new File("/Users/abcganada/SJU/2023-2/java/week11/test4.txt");
        try {
            if (f.exists()) {
                InputStream fin = new FileInputStream(f);
                Scanner sc = new Scanner(fin);
                String str = sc.nextLine();
                System.out.println(str);
            } else {
                throw new IOException();
            }
        } catch (IOException e) {
            System.out.println("IO exception");
        }

    }
}
