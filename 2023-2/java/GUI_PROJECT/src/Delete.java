import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Delete {
    private JPanel deletePanel;
    private JTextField textField1;
    private JButton deleteButton;
    private JButton cancelButton;

    public Delete() {
        deleteButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });
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

    public JPanel getDeletePanel() {
        return deletePanel;
    }
}
