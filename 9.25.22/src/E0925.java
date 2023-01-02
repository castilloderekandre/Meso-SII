import java.awt.event.*;
import java.util.*;
import java.util.Random;

public class E0925 extends javax.swing.JFrame {

    public E0925() {
        initComponents();
    }

    public String ArrayToString(int[][] a){
        int checker=Integer.MIN_VALUE;
        for(int i=0; i<5; i++)
                if(checker < a[i/5][i%5])
                    checker=a[i/5][i%5];
        String str="[";
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                char[] cv = new char[Integer.toString(checker).length() - Integer.toString(a[i][j]).length()];
                Arrays.fill(cv, ' ');
                str += a[i][j] + (j+1<5 ? ", " : "") + new String(cv);
            }
            str += i+1<5 ? "\n " : "";
        }
        str+="]";
        return str;
    }

    public void GlobalKeyRelease(KeyEvent e){
        int init=Integer.parseInt(jTextField1.getText()), fin=Integer.parseInt(jTextField2.getText());
        if(init>=fin) {e.consume(); return;}
        tpVector.setText("");
        Random r = new Random();
        for(int i=0; i<25; i++)
            v[i/5][i%5] = init + r.nextInt(fin - init + 1);
        tpVector.setText(ArrayToString(v));
        int psum=0, ipsum=0, pcount=0, ipcount=0;
        for(int[] row : v)
            for(int el : row){
                if(el%2==0){
                    pcount++;
                    psum+=el;
                }else{
                    ipcount++;
                    ipsum+=el;
                }
        }
        lPares.setText(Integer.toString(pcount));
        lImpares.setText(Integer.toString(ipcount));
        lSPares.setText(Integer.toString(psum));
        lSImpares.setText(Integer.toString(ipsum));
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">                          
    private void initComponents() {

        jLabel3 = new javax.swing.JLabel();
        jTextField1 = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        jTextField2 = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        lPares = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        tpVector = new javax.swing.JTextPane();
        jLabel2 = new javax.swing.JLabel();
        lImpares = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        lSPares = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        lSImpares = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        jTextField1.addKeyListener(new KeyAdapter(){
            public void keyReleased(KeyEvent e){
                GlobalKeyRelease(e);
            }
        });
        jTextField2.addKeyListener(new KeyAdapter(){
            public void keyReleased(KeyEvent e){
                GlobalKeyRelease(e);
            }
        });

        jLabel3.setText("VALOR INICIAL");

        jLabel4.setText("VALOR FINAL");

        jLabel5.setText("VECTOR:");

        jLabel1.setText("PARES:");

        lPares.setText("N/A");

        tpVector.setEditable(false);
        tpVector.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        tpVector.setPreferredSize(new java.awt.Dimension(40, 40));
        jScrollPane1.setViewportView(tpVector);

        jLabel2.setText("IMPARES:");

        lImpares.setText("N/A");

        jLabel7.setText("SUMA-PARES:");

        lSPares.setText("N/A");

        jLabel9.setText("SUMA-IMPARES:");

        lSImpares.setText("N/A");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jLabel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jTextField1))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel4)
                            .addComponent(jTextField2, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel5)
                        .addGap(56, 56, 56)
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel1)
                            .addComponent(jLabel9)
                            .addComponent(jLabel2)
                            .addComponent(jLabel7))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(lPares)
                            .addComponent(lImpares)
                            .addComponent(lSPares)
                            .addComponent(lSImpares))))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(jLabel4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextField2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel5)
                            .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel7)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel9))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(lPares)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(lImpares)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(lSPares)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(lSImpares)))
                .addContainerGap(15, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>                        

    public static void main(String args[]) {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(E0925.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(E0925.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(E0925.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(E0925.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new E0925().setVisible(true);
            }
        });
    }

    public static int[][] v = new int[5][5];
    // Variables declaration - do not modify                     
    private javax.swing.JTextPane tpVector;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextField jTextField1;
    private javax.swing.JTextField jTextField2;
    private javax.swing.JLabel lImpares;
    private javax.swing.JLabel lPares;
    private javax.swing.JLabel lSImpares;
    private javax.swing.JLabel lSPares;
    // End of variables declaration                   
}
