import java.util.*;
import java.util.vector.*;
import javax.swing.JOptionPane;

import java.awt.event.*;
import java.lang.*;

public class A1005 extends javax.swing.JFrame {
    String[] words = {"Laboratorio", "Gasosea", "Comida", "Computadora", "Teclado",
                      "Monitor", "Empalmes", "Vocabulario", "Universidad", "Colegio",
                      "Escuela", "Libro", "Lenguaje", "Idioma", "Ropa"};
    String word;
    char[] formattedWord;
    int points=0, interval;
    int[] guesses=new int[2];
    Timer timer = new Timer();
    List<Character> existingKeys = new ArrayList<Character>();

    public void AddStick(){
        switch(guesses[1]){
            case 0:
            TAStick.setText(" _________\n" +
                            " |\n" + 
                            " |\n" + 
                            " |\n" +
                            " |\n" +
                            " |\n" +
                            "/ \\------------");
                break;
            case 1:
            TAStick.setText(" _________\n" +
                            " |       |\n" + 
                            " |\n" + 
                            " |\n" +
                            " |\n" +
                            " |\n" +
                            "/ \\------------");
                break;
            case 2:
            TAStick.setText(" _________\n" +
                            " |       |\n" + 
                            " |       O\n" + 
                            " |\n" +
                            " |\n" +
                            " |\n" +
                            "/ \\------------");
                break;
            case 3:
            TAStick.setText(" _________\n" +
                            " |       |\n" + 
                            " |       O\n" + 
                            " |      /\n" +
                            " |\n" +
                            " |\n" +
                            "/ \\------------");
                break;
            case 4:
            TAStick.setText(" _________\n" +
                            " |       |\n" + 
                            " |       O\n" + 
                            " |      /|\n" +
                            " |\n" +
                            " |\n" +
                            "/ \\------------");
                break;
            case 5:
            TAStick.setText(" _________\n" +
                            " |       |\n" + 
                            " |       O\n" + 
                            " |      /|\\\n" +
                            " |\n" +
                            " |\n" +
                            "/ \\------------");
                break;
            case 6:
            TAStick.setText(" _________\n" +
                            " |       |\n" + 
                            " |       O\n" + 
                            " |      /|\\\n" +
                            " |      /\n" +
                            " |\n" +
                            "/ \\------------");
                break;
            case 7:
            TAStick.setText(" _________\n" +
                            " |       |\n" + 
                            " |       O\n" + 
                            " |      /|\\\n" +
                            " |      / \\\n" +
                            " |\n" +
                            "/ \\------------");
                EndGame();
                break;
        }
    }

    public void GlobalKeyPress(KeyEvent e){
        //Clears input box
        TFInput.setText("");
    }

    public void GlobalKeyRelease(KeyEvent e){
        //If key has already been used, return
        if(TFInput.getText().length()==0 || existingKeys.contains(e.getKeyChar())) return;
        existingKeys.add(e.getKeyChar());
        //Checks if key pressed is part of the word
        if (word.toLowerCase().contains((CharSequence)(new StringBuilder(Character.toString(e.getKeyChar()))))) {
            char[] wordChars = word.toLowerCase().toCharArray();
            for(int i=0; i<wordChars.length; i++)
                if(wordChars[i]==e.getKeyChar())
                    formattedWord[i*2]=e.getKeyChar();
            TABox.setText(new String(formattedWord));
            points+=5;
            guesses[0]++;
        }else{
            points-=3;
            guesses[1]++;
            AddStick();
        }
        UpdateLabels();
        if(!TABox.getText().contains("_")) EndGame();
    }

    public void NewGame(){
        guesses[0]=guesses[1]=0;
        TFInput.setEditable(true);
        TFInput.setText("");
        existingKeys.clear();
        Random r = new Random();
        word=words[r.nextInt(15)];
        String formatStr="";
        for(int i=0; i<word.length(); i++) formatStr+="_ ";
        formattedWord = formatStr.toCharArray();
        TABox.setText(formatStr);
        jButton1.setEnabled(false);
        UpdateLabels();
        TimerHelper();
        AddStick();
    }

    public void EndGame(){
        if(interval>0 && !TABox.getText().contains("_")) points+=50; 
        UpdateLabels();
        timer.cancel();
        JOptionPane.showMessageDialog(null, !TABox.getText().contains("_") ? "Gano" : "Perdio");
        NewGame();
    }

    public void TimerHelper(){
        interval=60;
        timer = new Timer();
        timer.scheduleAtFixedRate(new TimerTask(){
            public void run(){
                LTime.setText(Integer.toString(interval--));
                if(interval<0) {timer.cancel(); points-=40; EndGame();}
            }
        }, 100, 1000);
    }

    public void UpdateLabels(){
        LCorrects.setText(Integer.toString(guesses[0]));
        LIncorrects.setText(Integer.toString(guesses[1]));
        LPoints.setText(Integer.toString(points));
    }

    public A1005() {
        initComponents();
    }
    @SuppressWarnings("unchecked")                       
    private void initComponents() {

        TFInput = new javax.swing.JTextField();
        TAStick = new javax.swing.JTextArea();
        jLabel1 = new javax.swing.JLabel();
        jPanel1 = new javax.swing.JPanel();
        LCorrects = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        LIncorrects = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        LPoints = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        LTime = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        TABox = new javax.swing.JTextArea();
        jButton1 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        jButton1.addMouseListener(new MouseAdapter(){
            public void mouseClicked(MouseEvent e){
                NewGame();
            }
        });

        TFInput.addKeyListener(new KeyAdapter(){
            public void keyPressed(KeyEvent e){
                GlobalKeyPress(e);
            }
        });
        TFInput.addKeyListener(new KeyAdapter(){
            public void keyReleased(KeyEvent e){
                GlobalKeyRelease(e);
            }
        });
        TFInput.setEditable(false);

        TAStick.setColumns(20);
        TAStick.setFont(new java.awt.Font("Courier New", 0, 12)); // NOI18N
        TAStick.setRows(5);
        TAStick.setText(" _________\n |\n |\n |\n |\n |\n/ \\------------");
        TAStick.setEditable(false);

        TABox.setEditable(false);

        jLabel1.setText("INGRESE CONSONANTE O VOCAL");
        jLabel1.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        jPanel1.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        LCorrects.setText("0");

        jLabel4.setText("DESACIERTOS:");

        LIncorrects.setText("0");

        jLabel2.setText("ACIERTOS:");

        jLabel3.setText("PUNTOS:");

        LPoints.setText("0");

        jLabel5.setText("TIEMPO:");

        LTime.setText("0");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel2)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(LCorrects))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel4)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(LIncorrects))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel3)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(LPoints))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(jLabel5)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(LTime)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(LCorrects))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(LIncorrects))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(LPoints))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(LTime))
                .addContainerGap())
        );

        TABox.setColumns(20);
        TABox.setRows(5);
        jScrollPane1.setViewportView(TABox);

        jButton1.setText("COMENZAR");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                    .addComponent(jLabel1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(TAStick, javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(TFInput, javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jButton1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(TAStick, javax.swing.GroupLayout.PREFERRED_SIZE, 111, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 56, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(TFInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jButton1)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>                        

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
            java.util.logging.Logger.getLogger(A1005.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(A1005.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(A1005.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(A1005.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new A1005().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify                     
    private javax.swing.JLabel LCorrects;
    private javax.swing.JLabel LIncorrects;
    private javax.swing.JLabel LPoints;
    private javax.swing.JLabel LTime;
    private javax.swing.JTextArea TABox;
    private javax.swing.JTextArea TAStick;
    private javax.swing.JTextField TFInput;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    // End of variables declaration             
}
