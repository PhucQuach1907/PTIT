/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package view;

import btswing.BangChamCong;
import btswing.CongNhan;
import btswing.Xuong;
import controller.IOFile;
import controller.ValiException;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author ADMIN
 */
public class Main extends javax.swing.JFrame {

    private List<CongNhan> listCN;
    private List<Xuong> listX;
    private List<BangChamCong> listBCC;
    private DefaultTableModel tmCN, tmX, tmBCC;
    private String fileCN, fileX, fileBCC;

    public Main() {
        initComponents();
        fileCN = "src/controller/CN.dat";
        fileX = "src/controller/XSX.dat";
        fileBCC = "src/controller/BCC.dat";
        if (new File(fileCN).exists()) {
            listCN = IOFile.doctuFile(fileCN);
        } else {
            listCN = new ArrayList<>();
        }
        if (new File(fileX).exists()) {
            listX = IOFile.doctuFile(fileX);
        } else {
            listX = new ArrayList<>();
        }
        if (new File(fileBCC).exists()) {
            listBCC = IOFile.doctuFile(fileBCC);
        } else {
            listBCC = new ArrayList<>();
        }
        tmCN = (DefaultTableModel) tbCN.getModel();
        tmX = (DefaultTableModel) tbXuong.getModel();
        tmBCC = (DefaultTableModel) tbBCC.getModel();
        docCN();
        docX();
        docBCC();
        setButtonCN(true);
        setButtonX(true);
        eventCN();
        eventX();
        eventBCC();
        thongkebtn.addActionListener(e ->{
            Map<String,Integer> sum=listBCC.stream().collect(Collectors.groupingBy(BangChamCong::VietTK,
                    Collectors.summingInt(BangChamCong::getThunhap)));
            thongketxt.setText(sum.toString());
        });
    }

    private void docCN() {
        tmCN.setRowCount(0);
        for (CongNhan i : listCN) {
            tmCN.addRow(i.toObject());
        }
    }

    private void docX() {
        tmX.setRowCount(0);
        for (Xuong i : listX) {
            tmX.addRow(i.toObject());
        }
    }

    private void docBCC() {
        tmBCC.setRowCount(0);
        for (BangChamCong i : listBCC) {
            tmBCC.addRow(i.toObject());
        }
    }

    private void setButtonCN(boolean b) {
        themCNBT.setEnabled(b);
        capnhatCNBT.setEnabled(!b);
        boquaCNBT.setEnabled(!b);
    }

    private void setButtonX(boolean b) {
        themX.setEnabled(b);
        capnhatX.setEnabled(!b);
    }

    private void eventCN() {

        themCNBT.addActionListener(e -> {
            maCN.setText(1000 + listCN.size() + "");
            hotenCN.requestFocus();
            setButtonCN(false);
        });
        capnhatCNBT.addActionListener(e -> {
            try {
                if (!dthoaiCN.getText().matches("\\d+")) {
                    throw new ValiException("Moi nhap lai so");
                }
                CongNhan c = new CongNhan(Integer.parseInt(maCN.getText()), hotenCN.getText(), diachiCN.getText(), dthoaiCN.getText(), Integer.parseInt(bacCN.getSelectedItem().toString()));
                listCN.add(c);
                tmCN.addRow(c.toObject());
                setButtonCN(true);
            } catch (ValiException ex) {
                JOptionPane.showMessageDialog(this, ex);
                dthoaiCN.setText("");
                dthoaiCN.requestFocus();
            }
        });
        xoaCNBT.addActionListener(e -> {
            int row = tbCN.getSelectedRow();
            if (row >= 0 && row < tbCN.getRowCount()) {
                listCN.remove(row);
                tmCN.removeRow(row);
            } else {
                JOptionPane.showMessageDialog(this, "chon dong de xoa");
            }
        });
        luuCNBT.addActionListener(e -> {
            IOFile.vietvaofile(fileCN, listCN);
        });
        boquaCNBT.addActionListener(e -> {
            setButtonCN(true);
        });
    }

    private void eventX() {

        themX.addActionListener(e -> {
            maX.setText(100 + listX.size() + "");
            tenX.requestFocus();
            setButtonX(false);
        });
        capnhatX.addActionListener(e -> {
            Xuong x = new Xuong(Integer.parseInt(maX.getText()), tenX.getText(), Integer.parseInt(hesoX.getSelectedItem().toString()));
            listX.add(x);
            tmX.addRow(x.toObject());
            setButtonX(true);
        });
        xoaX.addActionListener(e -> {
            int row = tbXuong.getSelectedRow();
            if (row >= 0 && row < tbXuong.getRowCount()) {
                listX.remove(row);
                tmX.removeRow(row);
            } else {
                JOptionPane.showMessageDialog(this, "chon dong de xoa");
            }
        });
        suaX.addActionListener(e -> {
            int row = tbXuong.getSelectedRow();
            if (row >= 0 && row <= tbXuong.getRowCount()) {
                Xuong X = new Xuong(Integer.parseInt(maX.getText()), tenX.getText(), Integer.parseInt(hesoX.getSelectedItem().toString()));
                listX.set(row, X);
                tmX.removeRow(row);
                tmX.insertRow(row, X.toObject());
            } else {
                JOptionPane.showMessageDialog(this, "Chon hang de xoa");
            }
        });
        luuX.addActionListener(e -> {
            IOFile.vietvaofile(fileX, listX);
        });

    }

    private int getSoNgay(int maCN) {
        int so = 0;
        for (BangChamCong i : listBCC) {
            if (i.getCongNhan().getMa() == maCN) {
                so += i.getSongay();
            }
        }
        return so;
    }

    private CongNhan getCongnhan(int ma) {
        for (CongNhan i : listCN) {
            if (i.getMa() == ma) {
                return i;
            }
        }
        return null;
    }

    private Xuong getXUONG(int ma) {
        for (Xuong i : listX) {
            if (i.getMa() == ma) {
                return i;
            }
        }
        return null;
    }

    public void eventBCC() {
        lamtuoiCC.addActionListener(e -> {
            maCNCB.removeAllItems();
            for (CongNhan i : listCN) {
                maCNCB.addItem(i.getMa() + "");
            }
            maXCB.removeAllItems();
            for (Xuong i : listX) {
                maXCB.addItem(i.getMa() + "");
            }
        });
        ThemCC.addActionListener(e -> {
            try {
                int maCN1 = Integer.parseInt(maCNCB.getSelectedItem().toString());
                int maX1 = Integer.parseInt(maXCB.getSelectedItem().toString());
                int ngay = Integer.parseInt(txtSongay.getText());
                if (getSoNgay(maCN1) + ngay > 31) {
                    JOptionPane.showMessageDialog(this, "So ngay > 31");
                } else {
                    BangChamCong b = new BangChamCong(getCongnhan(maCN1), getXUONG(maX1), ngay);
                    listBCC.add(b);
                    tmBCC.addRow(b.toObject());
                }
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(this, ex);

            }
        });
        LuuCC.addActionListener(e -> {
            IOFile.vietvaofile(fileBCC, listBCC);
        });
        sxBCC.addActionListener(e -> {
            int index = cbSx.getSelectedIndex();
            if (index == 0) {
                listBCC.sort(new Comparator<BangChamCong>() {
                    @Override
                    public int compare(BangChamCong o1, BangChamCong o2) {
                        String[] t1 = o1.getCongNhan().getTen().split("\\s+");
                        String[] t2 = o2.getCongNhan().getTen().split("\\s+");
                        String ten1 = t1[t1.length - 1] + o1.getCongNhan().getTen();
                        String ten2 = t2[t2.length - 1] + o2.getCongNhan().getTen();
                        return ten1.compareToIgnoreCase(ten2);
                    }

                });
            } else {
                listBCC.sort(new Comparator<BangChamCong>() {
                    @Override
                    public int compare(BangChamCong o1, BangChamCong o2) {
                        return o1.getSongay() - o2.getSongay();
                    }
                });
            }
            tmBCC.setRowCount(0);
            for(BangChamCong i:listBCC){
                tmBCC.addRow(i.toObject());
            }
        });       
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jTabbedPane1 = new javax.swing.JTabbedPane();
        jPanel1 = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        tbCN = new javax.swing.JTable();
        jPanel4 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        maCN = new javax.swing.JTextField();
        diachiCN = new javax.swing.JTextField();
        dthoaiCN = new javax.swing.JTextField();
        hotenCN = new javax.swing.JTextField();
        bacCN = new javax.swing.JComboBox<>();
        jPanel5 = new javax.swing.JPanel();
        themCNBT = new javax.swing.JButton();
        capnhatCNBT = new javax.swing.JButton();
        boquaCNBT = new javax.swing.JButton();
        xoaCNBT = new javax.swing.JButton();
        luuCNBT = new javax.swing.JButton();
        jPanel2 = new javax.swing.JPanel();
        jScrollPane2 = new javax.swing.JScrollPane();
        tbXuong = new javax.swing.JTable();
        jPanel6 = new javax.swing.JPanel();
        jPanel8 = new javax.swing.JPanel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        maX = new javax.swing.JTextField();
        tenX = new javax.swing.JTextField();
        hesoX = new javax.swing.JComboBox<>();
        jPanel9 = new javax.swing.JPanel();
        themX = new javax.swing.JButton();
        capnhatX = new javax.swing.JButton();
        suaX = new javax.swing.JButton();
        xoaX = new javax.swing.JButton();
        luuX = new javax.swing.JButton();
        jPanel3 = new javax.swing.JPanel();
        jScrollPane3 = new javax.swing.JScrollPane();
        tbBCC = new javax.swing.JTable();
        jPanel7 = new javax.swing.JPanel();
        jLabel8 = new javax.swing.JLabel();
        jLabel11 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        maCNCB = new javax.swing.JComboBox<>();
        maXCB = new javax.swing.JComboBox<>();
        txtSongay = new javax.swing.JTextField();
        jLabel13 = new javax.swing.JLabel();
        cbSx = new javax.swing.JComboBox<>();
        SapxepCC = new javax.swing.JPanel();
        LuuCC = new javax.swing.JButton();
        ThemCC = new javax.swing.JButton();
        sxBCC = new javax.swing.JButton();
        lamtuoiCC = new javax.swing.JButton();
        jPanel10 = new javax.swing.JPanel();
        jScrollPane4 = new javax.swing.JScrollPane();
        thongketxt = new javax.swing.JTextArea();
        thongkebtn = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        tbCN.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null}
            },
            new String [] {
                "Ma", "Ten", "Dia chi", "Dien thoai", "Bac"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane1.setViewportView(tbCN);
        if (tbCN.getColumnModel().getColumnCount() > 0) {
            tbCN.getColumnModel().getColumn(4).setHeaderValue("Bac");
        }

        jLabel1.setText("Ma");

        jLabel2.setText("Ho ten");

        jLabel3.setText("Dia chi");

        jLabel4.setText("Dien thoai");

        jLabel5.setText("Bac");

        maCN.setEditable(false);

        bacCN.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "1", "2", "3", "4", "5", "6", "7" }));

        themCNBT.setText("Them");

        capnhatCNBT.setText("Cap nhat");

        boquaCNBT.setText("Bo qua");

        xoaCNBT.setText("Xoa");

        luuCNBT.setText("Luu File");

        javax.swing.GroupLayout jPanel5Layout = new javax.swing.GroupLayout(jPanel5);
        jPanel5.setLayout(jPanel5Layout);
        jPanel5Layout.setHorizontalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(themCNBT)
                    .addComponent(capnhatCNBT)
                    .addComponent(boquaCNBT)
                    .addComponent(xoaCNBT)
                    .addComponent(luuCNBT))
                .addContainerGap(353, Short.MAX_VALUE))
        );
        jPanel5Layout.setVerticalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addGap(17, 17, 17)
                .addComponent(themCNBT)
                .addGap(29, 29, 29)
                .addComponent(capnhatCNBT)
                .addGap(30, 30, 30)
                .addComponent(boquaCNBT)
                .addGap(31, 31, 31)
                .addComponent(xoaCNBT)
                .addGap(18, 18, 18)
                .addComponent(luuCNBT)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout jPanel4Layout = new javax.swing.GroupLayout(jPanel4);
        jPanel4.setLayout(jPanel4Layout);
        jPanel4Layout.setHorizontalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel4Layout.createSequentialGroup()
                        .addGap(34, 34, 34)
                        .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(68, 68, 68))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel4Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 63, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(42, 42, 42)))
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(maCN, javax.swing.GroupLayout.PREFERRED_SIZE, 300, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(diachiCN, javax.swing.GroupLayout.PREFERRED_SIZE, 300, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(dthoaiCN, javax.swing.GroupLayout.PREFERRED_SIZE, 300, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(hotenCN, javax.swing.GroupLayout.PREFERRED_SIZE, 300, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(bacCN, javax.swing.GroupLayout.PREFERRED_SIZE, 300, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 42, Short.MAX_VALUE)
                .addComponent(jPanel5, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );
        jPanel4Layout.setVerticalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addGap(26, 26, 26)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(maCN, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(22, 22, 22)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(hotenCN, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(29, 29, 29)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(diachiCN, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(23, 23, 23)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(dthoaiCN, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(24, 24, 24)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(bacCN, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jPanel5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addContainerGap())
        );

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(21, 21, 21)
                        .addComponent(jPanel4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 1016, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(115, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(33, 33, 33)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 191, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(30, 30, 30)
                .addComponent(jPanel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGap(551, 551, 551))
        );

        jTabbedPane1.addTab("Cong nhan", jPanel1);

        tbXuong.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null}
            },
            new String [] {
                "Ma xuong", "Ten xuong", "He so cong viec"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        tbXuong.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tbXuongMouseClicked(evt);
            }
        });
        jScrollPane2.setViewportView(tbXuong);

        jLabel6.setText("Ma");

        jLabel7.setText("Ten Xuong");

        jLabel10.setText("He so cong viec");

        maX.setEditable(false);

        hesoX.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" }));

        javax.swing.GroupLayout jPanel8Layout = new javax.swing.GroupLayout(jPanel8);
        jPanel8.setLayout(jPanel8Layout);
        jPanel8Layout.setHorizontalGroup(
            jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel8Layout.createSequentialGroup()
                .addGap(34, 34, 34)
                .addGroup(jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                        .addComponent(jLabel7, javax.swing.GroupLayout.PREFERRED_SIZE, 87, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(jLabel10, javax.swing.GroupLayout.PREFERRED_SIZE, 87, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jLabel6, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 87, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(maX, javax.swing.GroupLayout.PREFERRED_SIZE, 300, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(tenX, javax.swing.GroupLayout.PREFERRED_SIZE, 300, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(hesoX, javax.swing.GroupLayout.PREFERRED_SIZE, 300, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(124, Short.MAX_VALUE))
        );
        jPanel8Layout.setVerticalGroup(
            jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel8Layout.createSequentialGroup()
                .addGap(26, 26, 26)
                .addGroup(jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6)
                    .addComponent(maX, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(22, 22, 22)
                .addGroup(jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(tenX, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(27, 27, 27)
                .addGroup(jPanel8Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel10)
                    .addComponent(hesoX, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(113, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout jPanel6Layout = new javax.swing.GroupLayout(jPanel6);
        jPanel6.setLayout(jPanel6Layout);
        jPanel6Layout.setHorizontalGroup(
            jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 575, Short.MAX_VALUE)
            .addGroup(jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel6Layout.createSequentialGroup()
                    .addContainerGap()
                    .addComponent(jPanel8, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
        );
        jPanel6Layout.setVerticalGroup(
            jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 292, Short.MAX_VALUE)
            .addGroup(jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(jPanel6Layout.createSequentialGroup()
                    .addGap(19, 19, 19)
                    .addComponent(jPanel8, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGap(19, 19, 19)))
        );

        themX.setText("Them");

        capnhatX.setText("Cap nhat");

        suaX.setText("Sua");

        xoaX.setText("Xoa");

        luuX.setText("Luu File");

        javax.swing.GroupLayout jPanel9Layout = new javax.swing.GroupLayout(jPanel9);
        jPanel9.setLayout(jPanel9Layout);
        jPanel9Layout.setHorizontalGroup(
            jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel9Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel9Layout.createSequentialGroup()
                        .addGroup(jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel9Layout.createSequentialGroup()
                                .addComponent(themX)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 22, Short.MAX_VALUE)
                                .addComponent(capnhatX))
                            .addGroup(jPanel9Layout.createSequentialGroup()
                                .addComponent(suaX)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(xoaX)))
                        .addGap(181, 181, 181))
                    .addGroup(jPanel9Layout.createSequentialGroup()
                        .addComponent(luuX)
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
        );
        jPanel9Layout.setVerticalGroup(
            jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel9Layout.createSequentialGroup()
                .addGap(17, 17, 17)
                .addGroup(jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(themX)
                    .addComponent(capnhatX))
                .addGap(27, 27, 27)
                .addGroup(jPanel9Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(suaX)
                    .addComponent(xoaX))
                .addGap(33, 33, 33)
                .addComponent(luuX)
                .addContainerGap(122, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(19, 19, 19)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                        .addComponent(jPanel6, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jPanel9, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 939, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(179, Short.MAX_VALUE))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(19, 19, 19)
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 232, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGap(42, 42, 42)
                        .addComponent(jPanel6, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGap(18, 18, 18)
                        .addComponent(jPanel9, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jTabbedPane1.addTab("Xuong san xuat", jPanel2);

        tbBCC.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Ma", "Ho va ten", "Ma Xuong", "So ngay"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane3.setViewportView(tbBCC);

        jLabel8.setText("Ma cong nhan");

        jLabel11.setText("Ma Xuong");

        jLabel12.setText("So ngay LV");

        maCNCB.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Item 1", "Item 2", "Item 3", "Item 4" }));

        maXCB.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Item 1", "Item 2", "Item 3", "Item 4" }));

        jLabel13.setText("Sap xep");

        cbSx.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Ho ten cong nhan", "So ngay lam viec" }));

        javax.swing.GroupLayout jPanel7Layout = new javax.swing.GroupLayout(jPanel7);
        jPanel7.setLayout(jPanel7Layout);
        jPanel7Layout.setHorizontalGroup(
            jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel7Layout.createSequentialGroup()
                .addGap(55, 55, 55)
                .addGroup(jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                        .addComponent(jLabel11, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jLabel8, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jLabel12, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addComponent(jLabel13, javax.swing.GroupLayout.PREFERRED_SIZE, 57, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(32, 32, 32)
                .addGroup(jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(maCNCB, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(maXCB, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(txtSongay)
                    .addComponent(cbSx, 0, 312, Short.MAX_VALUE))
                .addContainerGap(62, Short.MAX_VALUE))
        );
        jPanel7Layout.setVerticalGroup(
            jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel7Layout.createSequentialGroup()
                .addGap(36, 36, 36)
                .addGroup(jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel8)
                    .addComponent(maCNCB, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(24, 24, 24)
                .addGroup(jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel11)
                    .addComponent(maXCB, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(38, 38, 38)
                .addGroup(jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel12)
                    .addComponent(txtSongay, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(52, 52, 52)
                .addGroup(jPanel7Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel13)
                    .addComponent(cbSx, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(90, Short.MAX_VALUE))
        );

        LuuCC.setText("Luu File");

        ThemCC.setText("Them");

        sxBCC.setText("Sapxep");

        lamtuoiCC.setText("Lam moi");

        javax.swing.GroupLayout SapxepCCLayout = new javax.swing.GroupLayout(SapxepCC);
        SapxepCC.setLayout(SapxepCCLayout);
        SapxepCCLayout.setHorizontalGroup(
            SapxepCCLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(SapxepCCLayout.createSequentialGroup()
                .addGap(45, 45, 45)
                .addGroup(SapxepCCLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(lamtuoiCC)
                    .addComponent(sxBCC)
                    .addComponent(ThemCC)
                    .addComponent(LuuCC))
                .addContainerGap(311, Short.MAX_VALUE))
        );
        SapxepCCLayout.setVerticalGroup(
            SapxepCCLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(SapxepCCLayout.createSequentialGroup()
                .addGap(23, 23, 23)
                .addComponent(ThemCC)
                .addGap(45, 45, 45)
                .addComponent(LuuCC)
                .addGap(36, 36, 36)
                .addComponent(lamtuoiCC)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 44, Short.MAX_VALUE)
                .addComponent(sxBCC)
                .addGap(74, 74, 74))
        );

        javax.swing.GroupLayout jPanel3Layout = new javax.swing.GroupLayout(jPanel3);
        jPanel3.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addGap(19, 19, 19)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addComponent(jPanel7, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(SapxepCC, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 1016, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(102, Short.MAX_VALUE))
        );
        jPanel3Layout.setVerticalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addGap(21, 21, 21)
                .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 191, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(35, 35, 35)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jPanel7, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(SapxepCC, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jTabbedPane1.addTab("Bang cham cong", jPanel3);

        thongketxt.setColumns(20);
        thongketxt.setRows(5);
        jScrollPane4.setViewportView(thongketxt);

        thongkebtn.setText("Thong ke");

        javax.swing.GroupLayout jPanel10Layout = new javax.swing.GroupLayout(jPanel10);
        jPanel10.setLayout(jPanel10Layout);
        jPanel10Layout.setHorizontalGroup(
            jPanel10Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel10Layout.createSequentialGroup()
                .addGap(52, 52, 52)
                .addGroup(jPanel10Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(thongkebtn)
                    .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 829, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(256, Short.MAX_VALUE))
        );
        jPanel10Layout.setVerticalGroup(
            jPanel10Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel10Layout.createSequentialGroup()
                .addGap(33, 33, 33)
                .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 160, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(48, 48, 48)
                .addComponent(thongkebtn)
                .addContainerGap(258, Short.MAX_VALUE))
        );

        jTabbedPane1.addTab("Thong ke", jPanel10);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jTabbedPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 1137, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(365, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jTabbedPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 554, Short.MAX_VALUE)
                .addGap(676, 676, 676))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void tbXuongMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tbXuongMouseClicked
        // TODO add your handling code here:
        int row = tbXuong.getSelectedRow();
        if (row >= 0 && row <= tbXuong.getRowCount()) {
            maX.setText(tbXuong.getValueAt(row, 0).toString());
            tenX.setText(tbXuong.getValueAt(row, 1).toString());
            for (int i = 0; i < hesoX.getItemCount(); i++) {
                if (hesoX.getItemAt(i).equals(tmX.getValueAt(row, 2).toString())) {
                    hesoX.setSelectedIndex(i);
                }
            }
        }
    }//GEN-LAST:event_tbXuongMouseClicked

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Main.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Main().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton LuuCC;
    private javax.swing.JPanel SapxepCC;
    private javax.swing.JButton ThemCC;
    private javax.swing.JComboBox<String> bacCN;
    private javax.swing.JButton boquaCNBT;
    private javax.swing.JButton capnhatCNBT;
    private javax.swing.JButton capnhatX;
    private javax.swing.JComboBox<String> cbSx;
    private javax.swing.JTextField diachiCN;
    private javax.swing.JTextField dthoaiCN;
    private javax.swing.JComboBox<String> hesoX;
    private javax.swing.JTextField hotenCN;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel10;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JPanel jPanel6;
    private javax.swing.JPanel jPanel7;
    private javax.swing.JPanel jPanel8;
    private javax.swing.JPanel jPanel9;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JTabbedPane jTabbedPane1;
    private javax.swing.JButton lamtuoiCC;
    private javax.swing.JButton luuCNBT;
    private javax.swing.JButton luuX;
    private javax.swing.JTextField maCN;
    private javax.swing.JComboBox<String> maCNCB;
    private javax.swing.JTextField maX;
    private javax.swing.JComboBox<String> maXCB;
    private javax.swing.JButton suaX;
    private javax.swing.JButton sxBCC;
    private javax.swing.JTable tbBCC;
    private javax.swing.JTable tbCN;
    private javax.swing.JTable tbXuong;
    private javax.swing.JTextField tenX;
    private javax.swing.JButton themCNBT;
    private javax.swing.JButton themX;
    private javax.swing.JButton thongkebtn;
    private javax.swing.JTextArea thongketxt;
    private javax.swing.JTextField txtSongay;
    private javax.swing.JButton xoaCNBT;
    private javax.swing.JButton xoaX;
    // End of variables declaration//GEN-END:variables
}
