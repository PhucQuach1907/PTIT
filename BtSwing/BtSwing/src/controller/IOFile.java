/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controller;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FilterOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author ADMIN
 */
public class IOFile implements Serializable{
    public static<T> List<T>doctuFile(String fname){
        List<T>list=new ArrayList<>();
        try{
            ObjectInputStream o = new ObjectInputStream(new FileInputStream(fname)); 
            list=(List<T>)o.readObject();
            o.close();
        }
        catch(IOException e){
            System.err.println(e);
        }
        catch(ClassNotFoundException e){
            System.out.println(e);
        }
        return list;
    }
     public static <T> void vietvaofile(String fname,List<T>arr){
         try{
            ObjectOutputStream o = new ObjectOutputStream(new FileOutputStream(fname));
            o.writeObject(arr);
            o.close();
         }
         catch (FileNotFoundException e) {
            System.out.println(e);}
         catch(IOException e){
            System.err.println(e);
        } 
     }
     private IOFile() {

    }

    private static IOFile instance;

    public static IOFile getInstance() {
        if (instance == null) {
            instance = new IOFile();
        }
        return instance;
    }
}