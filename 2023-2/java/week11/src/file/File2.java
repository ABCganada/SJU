package file;

import java.io.File;

public class File2 {

    public static void main(String[] args) {
        File f = new File("/Users/abcganada/SJU/2023-2/java/week11/test.txt");
        if (f.exists()) {
            System.out.println("File name: " + f.getName());
            System.out.println("File path: " + f.getAbsolutePath());
            System.out.println("File writeable: " + f.canWrite());
            System.out.println("File readable: " + f.canRead());
            System.out.println("File size in bytes: " + f.length());
        } else {
            System.out.println("not exist");
        }
    }
}
