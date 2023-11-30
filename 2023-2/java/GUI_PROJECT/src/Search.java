import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

public class Search {
    private JPanel searchPanel;
    private JRadioButton gradeRadioButton;
    private JRadioButton participantsRadioButton;
    private JButton cancelButton;
    private JTable movieListTable;

    private Index index;

    public Search(Index index) {
        this.index = index;

        cancelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame frame = (JFrame) SwingUtilities.getWindowAncestor(cancelButton);

                if (frame != null) {
                    frame.dispose();
                }
            }
        });

        updateTable(index.movieList);
    }

    public JPanel getSearchPanel() {
        return searchPanel;
    }

    private void updateTable(List<Movie> movieList) {
        DefaultTableModel model = new DefaultTableModel();
        model.addColumn("Name");
        model.addColumn("Director");
        model.addColumn("Grade");
        model.addColumn("Participants");

        model.addRow(new Object[]{"Name", "Director", "Grade", "Participants"});

        for (Movie movie : movieList) {
            model.addRow(new Object[]{movie.getName(), movie.getDirector(), movie.getGrade(), movie.getParticipants()});
        }

        movieListTable.setModel(model);

        movieListTable.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
            @Override
            public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
                Component c = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);

                if (row == 0) {
                    c.setBackground(Color.green);
                } else {
                    c.setBackground(table.getBackground());
                }

                return c;
            }
        });
    }
}
