package btswing;


import java.io.Serializable;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author ADMIN
 */
public class Xuong implements Serializable{
    private int ma;
    private String ten;
    private int heso;

    public Xuong() {
    }

    public Xuong(int ma, String ten, int heso) {
        this.ma = ma;
        this.ten = ten;
        this.heso = heso;
    }

    public int getMa() {
        return ma;
    }

    public void setMa(int ma) {
        this.ma = ma;
    }

    public String getTen() {
        return ten;
    }

    public void setTen(String ten) {
        this.ten = ten;
    }

    public int getHeso() {
        return heso;
    }

    public void setHeso(int heso) {
        this.heso = heso;
    }
    public Object[] toObject(){
      return new Object[]{
          ma,ten,heso
      };
    }
}
