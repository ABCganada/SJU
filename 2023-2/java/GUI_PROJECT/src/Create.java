import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Create {
    private JTextField textField1;
    private JTextField textField2;
    private JButton cancelButton;
    private JButton createButton;
    private JPanel createPanel;
    
    private final Index index;

    public Create(Index index) {
        this.index = index;
        
        createButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                
                String name = textField1.getText();
                String director = textField2.getText();

                if (!name.isEmpty() && !director.isEmpty()) {
                    Movie newMovie = new Movie(name, director);

                    index.movieList.add(newMovie);

                    JFrame frame = (JFrame) SwingUtilities.getWindowAncestor(createButton);
                    if (frame != null) {
                        frame.dispose();
                    }

                    JOptionPane.showMessageDialog(createPanel, "Created!", "Information", JOptionPane.INFORMATION_MESSAGE);
                } else {
                    JOptionPane.showMessageDialog(createPanel, "Please enter both name and director.", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        cancelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame frame = (JFrame) SwingUtilities.getWindowAncestor(createButton);
                if (frame != null) {
                    frame.dispose();
                }
            }
        });
    }

    public JPanel getCreatePanel() {
        return createPanel;
    }
}
