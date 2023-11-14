package file;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class FileRead2 {

    public static void main(String[] args) throws IOException {

        InputStream fin = new FileInputStream("/Users/abcganada/SJU/2023-2/java/week11/test.txt");
        Scanner sc = new Scanner(fin);
        String str = sc.nextLine();
        System.out.println(str);
    }
}
