import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Iterator;

public class Delete {
    private JPanel deletePanel;
    private JTextField textField1;
    private JButton deleteButton;
    private JButton cancelButton;
    private JTable movieListTable;

    private Index index;

    public Delete(Index index) {
        this.index = index;

        index.updateTable(index.movieList, movieListTable);

        deleteButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String delMovieName = textField1.getText();
                Iterator<Movie> iterator = index.movieList.iterator();

                while (iterator.hasNext()) {
                    Movie movie = iterator.next();
                    if (movie.getName().equals(delMovieName)) {
                        iterator.remove();
                        JOptionPane.showMessageDialog(deletePanel, "Delete movie \"" + delMovieName + "\"!", "Delete message", JOptionPane.INFORMATION_MESSAGE);
                    }
                }

                index.updateTable(index.movieList, movieListTable);
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
