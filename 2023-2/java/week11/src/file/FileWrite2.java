package file;

import java.io.FileWriter;
import java.io.IOException;

public class FileWrite2 {

    public static void main(String[] args) throws IOException {
        FileWriter fw = new FileWriter("/Users/abcganada/SJU/2023-2/java/week11/test33.txt");

        fw.write("This is a java class");
        fw.close();
    }
}
