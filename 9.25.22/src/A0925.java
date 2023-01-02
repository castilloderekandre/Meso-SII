import java.awt.event.*;
import java.util.*;
import java.util.Random;

import javax.swing.JOptionPane;

public class A0925 extends javax.swing.JFrame {

    public A0925() {
        initComponents();
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jTFInit = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jTFFin = new javax.swing.JTextField();
        jLVect = new javax.swing.JLabel();
        jLVectOut = new javax.swing.JLabel();
        jLPrimes = new javax.swing.JLabel();
        jLPrimesOut = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("VALOR INICIAL");

        jLabel2.setText("VALOR FINAL");

        jLVect.setText("VECTOR:");

        jLVectOut.setText("N/A");

        jLPrimes.setText("PRIMOS:");

        jLPrimesOut.setText("N/A");

        jTFInit.addKeyListener(new KeyAdapter(){
            public void keyReleased(KeyEvent e){
                GlobalKeyRelease(e);
            }
        });
        jTFFin.addKeyListener(new KeyAdapter(){
            public void keyReleased(KeyEvent e){
                GlobalKeyRelease(e);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jTFInit))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel2)
                            .addComponent(jTFFin, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLVect)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLVectOut))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLPrimes)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLPrimesOut)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jLabel2))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTFInit, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTFFin, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLVect)
                    .addComponent(jLVectOut))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLPrimes)
                    .addComponent(jLPrimesOut))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    public static int[] getPrimes(int[] v){
        List<Integer> primes = new ArrayList<Integer>();  
        for(int i : v){
            boolean prime=true;
            for(int j=2; j<i; j++){
                if(i%j==0){ prime=false; break; }
            }
            if(prime) primes.add(i);
        }
        int[] array = new int[primes.size()];
        for(int i=0; i<primes.size(); i++) array[i] = primes.get(i);
        return array;
    }

    public static void GlobalKeyRelease(KeyEvent e){
        int init=Integer.parseInt(jTFInit.getText()), fin=Integer.parseInt(jTFFin.getText());
        if(init>=fin) {e.consume(); return;}
        jLVectOut.setText("");
        Random r = new Random();
        for(int i=0; i<10; i++){
            v[i]= init + r.nextInt(fin - init + 1);
        }
        jLVectOut.setText(Arrays.toString(v));
        int[] primes = getPrimes(v);
        jLPrimesOut.setText(Arrays.toString(primes));
    }

    public static void main(String args[]) {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(A0925.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(A0925.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(A0925.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(A0925.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new A0925().setVisible(true);
            }
        });
    }

    public static int[] v = new int[10];
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLVect;
    private static javax.swing.JLabel jLVectOut;
    private javax.swing.JLabel jLPrimes;
    private static javax.swing.JLabel jLPrimesOut;
    private static javax.swing.JTextField jTFInit;
    private static javax.swing.JTextField jTFFin;
    // End of variables declaration//GEN-END:variables
}
