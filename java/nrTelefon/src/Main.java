
import com.sun.source.tree.Tree;

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
        ArrayList<Person> fileBuffer = new ArrayList<>();
        try {
            File fileInput = new File("input.txt");
            Scanner fileRead = new Scanner(fileInput);
            while (fileRead.hasNext()) {
                String temp[] = fileRead.nextLine().split(" ");
                //0 name
                //1 surname
                //2 telephone number
                Person tempPerson = new Person(temp[1], temp[0], temp[2]);
                fileBuffer.add(tempPerson);
            }
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        }
        int bufferSize = fileBuffer.size();
        //SARCINA 1:Sortare persoane
        //========================================================================================================
        System.out.println("Sarcina 1:");
        //for (int i = 0; i < bufferSize; i++) {
           // System.out.println(fileBuffer.get(i));
        //}
        System.out.println("===========================");
        Collections.sort(fileBuffer, new PersonComparator());//redefinire interfata de comparare
        //for (int i = 0; i < bufferSize; i++) {
        //    System.out.println(fileBuffer.get(i));
       // }
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
        System.out.println("Sarcina 2:");
        HashMap<String,Integer> phoneNumberMap=new HashMap<>();
        for (Person person : fileBuffer) {
            String phoneNumber = person.getTelephoneNumber();
            if (phoneNumberMap.containsKey(phoneNumber)) {
                int counter = phoneNumberMap.get(phoneNumber);
                counter++;
                phoneNumberMap.replace(phoneNumber, counter);
            } else
                phoneNumberMap.put(phoneNumber, 1);

        }
        System.out.println(phoneNumberMap);
        try {
            File outputFile2=new File("output2.txt");
            outputFile2.createNewFile();
            Path path = Paths.get(outputFile2.getPath());
            byte temp[] = {};
            Files.write(path, temp, StandardOpenOption.TRUNCATE_EXISTING);
            for (Map.Entry<String, Integer> entry : phoneNumberMap.entrySet()) {
                if(entry.getValue()>=2) {
                    {
                        System.out.println(entry.getKey());
                        byte writeBuffer[]=(entry.getKey()+"\n").getBytes();
                        Files.write(path,writeBuffer,StandardOpenOption.APPEND);
                    }
                }
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
            System.out.println(e.getCause());
        }
    }
}