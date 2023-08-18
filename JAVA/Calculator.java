import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;

public class Calculator {
    private JFrame frame;
    private JTextField textField;
    private JButton[] numberButtons;
    private JButton[] functionButtons;
    private JButton addButton, subButton, mulButton, divButton;
    private JButton decButton, equButton, delButton, clrButton, negButton;
    private JButton sqrtButton, sqrButton, invButton;
    private JPanel panel;

    double num1 = 0, num2 = 0, result = 0;
    char operator;

    public Calculator() {
        frame = new JFrame("Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(420, 550);
        frame.setLayout(null);

        textField = new JTextField();
        textField.setBounds(50, 25, 300, 50);
        textField.setFont(new Font("Arial", Font.PLAIN, 24));
        textField.setEditable(false);

        numberButtons = new JButton[10];
        for (int i = 0; i < 10; i++) {
            numberButtons[i] = new JButton(String.valueOf(i));
            numberButtons[i].addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    textField.setText(textField.getText().concat(e.getActionCommand()));
                }
            });
        }

        functionButtons = new JButton[8];
        addButton = new JButton("+");
        subButton = new JButton("-");
        mulButton = new JButton("*");
        divButton = new JButton("/");
        decButton = new JButton(".");
        equButton = new JButton("=");
        delButton = new JButton("Del");
        clrButton = new JButton("Clr");

        functionButtons[0] = addButton;
        functionButtons[1] = subButton;
        functionButtons[2] = mulButton;
        functionButtons[3] = divButton;
        functionButtons[4] = decButton;
        functionButtons[5] = equButton;
        functionButtons[6] = delButton;
        functionButtons[7] = clrButton;

        for (JButton button : functionButtons) {
            button.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    String command = e.getActionCommand();

                    switch (command) {
                        case "Clr":
                            textField.setText("");
                            break;
                        case "Del":
                            String text = textField.getText();
                            textField.setText(text.length() > 0 ? text.substring(0, text.length() - 1) : "");
                            break;
                        case ".":
                            if (!textField.getText().contains(".")) {
                                textField.setText(textField.getText().concat("."));
                            }
                            break;
                        case "=":
                            num2 = Double.parseDouble(textField.getText());
                            switch (operator) {
                                case '+':
                                    result = num1 + num2;
                                    break;
                                case '-':
                                    result = num1 - num2;
                                    break;
                                case '*':
                                    result = num1 * num2;
                                    break;
                                case '/':
                                    result = num1 / num2;
                                    break;
                            }
                            DecimalFormat df = new DecimalFormat("0.############");
                            textField.setText(df.format(result));
                            break;
                        default:
                            if (!textField.getText().isEmpty()) {
                                num1 = Double.parseDouble(textField.getText());
                                operator = command.charAt(0);
                                textField.setText("");
                            }
                            break;
                    }
                }
            });
        }   

        negButton = new JButton("+/-");
        negButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                double temp = Double.parseDouble(textField.getText());
                temp *= -1;
                textField.setText(String.valueOf(temp));
            }
        });

        sqrtButton = new JButton("√");
        sqrtButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                double temp = Double.parseDouble(textField.getText());
                temp = Math.sqrt(temp);
                textField.setText(String.valueOf(temp));
            }
        });

        sqrButton = new JButton("x²");
        sqrButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                double temp = Double.parseDouble(textField.getText());
                temp = Math.pow(temp, 2);
                textField.setText(String.valueOf(temp));
            }
        });

        invButton = new JButton("1/x");
        invButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                double temp = Double.parseDouble(textField.getText());
                temp = 1 / temp;
                textField.setText(String.valueOf(temp));
            }
        });

        panel = new JPanel();
        panel.setBounds(50, 100, 300, 300);
        panel.setLayout(new GridLayout(5, 5, 10, 10));
        panel.add(sqrtButton);
        panel.add(sqrButton);
        panel.add(invButton);
        panel.add(addButton);
        panel.add(numberButtons[1]);
        panel.add(numberButtons[2]);
        panel.add(numberButtons[3]);
        panel.add(subButton);
        panel.add(numberButtons[4]);
        panel.add(numberButtons[5]);
        panel.add(numberButtons[6]);
        panel.add(mulButton);
        
        panel.add(numberButtons[7]);
        panel.add(numberButtons[8]);
        panel.add(numberButtons[9]);
        panel.add(divButton);
        panel.add(numberButtons[0]);
        panel.add(decButton);  
        panel.add(equButton);
        panel.add(negButton);
        delButton.setBounds(50, 410, 145, 50);
        clrButton.setBounds(205, 410, 145, 50);
        frame.add(panel);
        frame.add(delButton);
        frame.add(clrButton);
        frame.add(textField);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        new Calculator();
    }
}