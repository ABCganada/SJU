package file;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class FileRead {

    public static void main(String[] args) throws IOException {
        File f = new File("/Users/abcganada/SJU/2023-2/java/week11/test.txt");
        InputStream fin = new FileInputStream(f);
        Scanner sc = new Scanner(fin);
        String str = sc.nextLine();
        System.out.println(str);
    }
}
