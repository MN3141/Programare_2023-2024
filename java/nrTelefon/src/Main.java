
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        ArrayList<Person> fileBuffer = new ArrayList<Person>();
        try {
            File fileInput = new File("input.txt");
            Scanner fileRead = new Scanner(fileInput);
            while (fileRead.hasNext()) {
                String temp[] = fileRead.nextLine().split(" ");
                //0 name
                //1 surname
                //2 telephone number
                Person tempPerson = new Person(temp[1], temp[0], Integer.parseInt(temp[2]));
                fileBuffer.add(tempPerson);
            }
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
        int bufferSize = fileBuffer.size();
        //SARCINA 1:Sortare persoane
        //========================================================================================================
        for (int i = 0; i < bufferSize; i++) {
            System.out.println(fileBuffer.get(i));
        }
        System.out.println("===========================");
        Collections.sort(fileBuffer, new PersonComparator());//redefinire interfata de comparare
        for (int i = 0; i < bufferSize; i++) {
            System.out.println(fileBuffer.get(i));
        }
        try {
            File outputFile=new File("output.txt");
            outputFile.createNewFile();
            Path path = Paths.get(outputFile.getPath());
            byte temp[] = {};
            Files.write(path, temp, StandardOpenOption.TRUNCATE_EXISTING);
            for (int i = 0; i < bufferSize; i++) {
                temp = (fileBuffer.get(i).toString() + "\n").getBytes();
                Files.write(path, temp, StandardOpenOption.APPEND);
            }

        } catch (IOException e) {
            System.out.println(e.getMessage());
            System.out.println(e.getCause());
        }
        //SARCINA 2:Afisare numere telefon ce se repeta
        //========================================================================================================
        HashMap<Integer, Integer> phoneNumberMap = new HashMap<Integer, Integer>();
        //Phone number:counter
        System.out.println("===========================");
        for (int i = 0; i < bufferSize; i++) {
            int temp = fileBuffer.get(i).getTelephoneNumber();
            if (phoneNumberMap.containsKey(temp)) {
                int counter = phoneNumberMap.get(temp);
                counter++;
                phoneNumberMap.replace(temp, counter);
            } else
                phoneNumberMap.put(temp, 1);
        }

        try {
            int mapSize = phoneNumberMap.size();
            File outputFile2=new File("output2.txt");
            outputFile2.createNewFile() ;
            Path path = Paths.get(outputFile2.getPath());
            byte temp[] = {};
            Files.write(path, temp, StandardOpenOption.TRUNCATE_EXISTING);
            temp=new byte[1];
            for (Map.Entry<Integer, Integer> set : phoneNumberMap.entrySet()) {
                int tempNumber = set.getValue();
                if (tempNumber >= 2) {
                    temp[0] = (byte) (tempNumber+48);//problema cand contorul este mai mare sau egal cu 10
                    Files.write(path, temp, StandardOpenOption.APPEND);
                }
            }

        } catch (IOException e) {
            System.out.println(e.getMessage());
            System.out.println(e.getCause());
        }

    }
}