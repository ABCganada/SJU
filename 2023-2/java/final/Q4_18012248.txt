import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Q4 {

    public static void main(String[] args) throws IOException {
        File original = new File("ORIGINAL.txt");
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter tour name:");
        String name = sc.nextLine();
        System.out.print("Enter tour id:");
        String id = sc.nextLine();
        System.out.print("Enter tour Age:");
        int age = Integer.parseInt(sc.nextLine());

        FileWriter fw = new FileWriter(original);
        fw.write("NAME:" + name + "\n");
        fw.write("ID:" + id + "\n");
        fw.write("Age:" + age + "\n");

        fw.close();

        FileReader fr = new FileReader(original);
        Scanner scr = new Scanner(fr);

        ArrayList<String> arrayList = new ArrayList<>();

        while (scr.hasNext()) {
            String str = scr.nextLine();
            arrayList.add(str);
            System.out.println(str);
        }

        File secondary = new File("SECONDARY.txt");
        fw = new FileWriter(secondary);
        for (String str : arrayList) {
            fw.write(str + "\n");
        }
        fw.close();
    }
}
