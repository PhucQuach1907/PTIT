package btswing;


import java.io.Serializable;
import java.net.UnknownHostException;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author ADMIN
 */
public class CongNhan implements Serializable{
    private  int ma;
    private String ten,diachi,dthoai;
    private  int bac;

    public CongNhan() {
    }

    public CongNhan(int ma, String ten, String diachi, String dthoai, int bac) {
        this.ma = ma;
        this.ten = ten;
        this.diachi = diachi;
        this.dthoai = dthoai;
        this.bac = bac;
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

    public String getDiachi() {
        return diachi;
    }

    public void setDiachi(String diachi) {
        this.diachi = diachi;
    }

    public String getDthoai() {
        return dthoai;
    }

    public void setDthoai(String dthoai) {
        this.dthoai = dthoai;
    }

    public int getBac() {
        return bac;
    }

    public void setBac(int bac) {
        this.bac = bac;
    }
    public Object[] toObject(){
        return new Object[]{
          ma,ten,diachi,dthoai,bac
        };
    }
}
