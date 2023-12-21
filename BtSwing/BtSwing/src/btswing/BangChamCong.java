package btswing;


import btswing.CongNhan;
import java.io.Serializable;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author ADMIN
 */
public class BangChamCong implements Serializable{
    private CongNhan congNhan;
    private Xuong xuong;
    private int songay;

    public BangChamCong() {
    }

    public BangChamCong(CongNhan congNhan, Xuong xuong, int songay) {
        this.congNhan = congNhan;
        this.xuong = xuong;
        this.songay = songay;
    }

    public CongNhan getCongNhan() {
        return congNhan;
    }

    public void setCongNhan(CongNhan congNhan) {
        this.congNhan = congNhan;
    }

    public Xuong getXuong() {
        return xuong;
    }

    public void setXuong(Xuong xuong) {
        this.xuong = xuong;
    }

    public int getSongay() {
        return songay;
    }
    public String VietTK(){
        return congNhan.getMa()+": "+congNhan.getTen();
    }
    public int getThunhap(){
        return songay*xuong.getHeso()*140000;
    }
    public void setSongay(int songay) {
        this.songay = songay;
    }
    public Object[] toObject(){
    return new Object[]{
      congNhan.getMa(),congNhan.getTen(),xuong.getMa(),songay
    };
}
}
