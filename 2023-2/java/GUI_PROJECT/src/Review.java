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

        // Set the cell renderer to change the selection color
        movieListTable.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
            @Override
            public Component getTableCellRendererComponent(
                    JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {

                super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);

                if (isSelected) {
                    setBackground(Color.BLUE); // Set your desired color
                    setForeground(Color.WHITE);
                } else {
                    setBackground(table.getBackground());
                    setForeground(table.getForeground());
                }

                return this;
            }
        });

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

        //Review, review button
        reviewButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int selectRow = movieListTable.getSelectedRow();

                if (selectRow > 0) {
                    int rating = 0;

                    if (a1RadioButton.isSelected()) {
                        rating = 1;
                    } else if (a2RadioButton.isSelected()) {
                        rating = 2;
                    } else if (a3RadioButton.isSelected()) {
                        rating = 3;
                    } else if (a4RadioButton.isSelected()) {
                        rating = 4;
                    } else if (a5RadioButton.isSelected()) {
                        rating = 5;
                    } else {
                        JOptionPane.showMessageDialog(reviewPanel, "Please enter both movie and rating", "Error", JOptionPane.ERROR_MESSAGE);
                        return;
                    }

                    Movie selectMovie = index.movieList.get(selectRow - 1);
                    selectMovie.setParticipants(selectMovie.getParticipants() + 1);
                    selectMovie.setSum(selectMovie.getSum() + rating);
                    selectMovie.setGrade(selectMovie.getSum() / (double) selectMovie.getParticipants());

                    index.movieList.set(selectRow - 1, selectMovie);
                    index.updateTable(index.movieList, movieListTable);
                } else {
                    JOptionPane.showMessageDialog(reviewPanel, "Please enter both movie and rating", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
    }

    public JPanel getReviewPanel() {
        return reviewPanel;
    }
}
