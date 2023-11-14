package file;

import java.io.File;
import java.io.IOException;

public class FileCreation2 {

    public static void main(String[] args) {
        try {
            File f = new File("/Users/abcganada/SJU/2023-2/java/week11/testCreation2.txt");
            if (f.createNewFile()) {
                System.out.println("File created");
            } else {
                System.out.println("Already exists");
            }
        } catch (IOException e) {
            System.out.println("IO exception");
        }
    }
}
