import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Review {
    private JPanel reviewPanel;
    private JRadioButton a1RadioButton;
    private JRadioButton a2RadioButton;
    private JRadioButton a3RadioButton;
    private JRadioButton a4RadioButton;
    private JRadioButton a5RadioButton;
    private JButton reviewButton;
    private JButton cancelButton;
    private JList list1;

    public Review() {
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

    public JPanel getReviewPanel() {
        return reviewPanel;
    }
}
