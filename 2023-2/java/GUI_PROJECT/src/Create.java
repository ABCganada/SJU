import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Create {
    private JTextField textField1;
    private JTextField textField2;
    private JButton cancelButton;
    private JButton createButton;
    private JPanel createPanel;

    public Create() {
        cancelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame frame = (JFrame) SwingUtilities.getWindowAncestor(cancelButton);

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
