import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
import java.util.List;

public class Review {
    private JPanel reviewPanel;
    private JRadioButton a1RadioButton;
    private JRadioButton a2RadioButton;
    private JRadioButton a3RadioButton;
    private JRadioButton a4RadioButton;
    private JRadioButton a5RadioButton;
    private JButton reviewButton;
    private JButton cancelButton;
    private JTable movieListTable;

    private Index index;

    public Review(Index index) {
        this.index = index;

        ButtonGroup buttonGroup = new ButtonGroup();
        buttonGroup.add(a1RadioButton);
        buttonGroup.add(a2RadioButton);
        buttonGroup.add(a3RadioButton);
        buttonGroup.add(a4RadioButton);
        buttonGroup.add(a5RadioButton);

        //Review, cancel btn action
        cancelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame frame = (JFrame) SwingUtilities.getWindowAncestor(cancelButton);

                if (frame != null) {
                    frame.dispose();
                }
            }
        });

        index.updateTable(index.movieList, movieListTable);
    }

    public JPanel getReviewPanel() {
        return reviewPanel;
    }
}
