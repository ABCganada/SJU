import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Search {
    private JPanel searchPanel;
    private JList list1;
    private JRadioButton gradeRadioButton;
    private JRadioButton participantsRadioButton;
    private JButton cancelButton;

    public Search() {
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

    public JPanel getSearchPanel() {
        return searchPanel;
    }
}
