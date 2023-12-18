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

        //Delete, delete btn
        deleteButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String delMovieName = textField1.getText();
                if (delMovieName.isEmpty()) {
                    JOptionPane.showMessageDialog(deletePanel, "Please enter name.", "Error", JOptionPane.ERROR_MESSAGE);
                    return;
                }

                Iterator<Movie> iterator = index.movieList.iterator();
                boolean modify = false;

                while (iterator.hasNext()) {
                    Movie movie = iterator.next();
                    if (movie.getName().equalsIgnoreCase(delMovieName)) {
                        iterator.remove();
                        JOptionPane.showMessageDialog(deletePanel, "Delete movie \"" + movie.getName() + "\"!", "Delete message", JOptionPane.INFORMATION_MESSAGE);
                        modify = true;
                        break;
                    }
                }

                if (modify) {
                    index.updateTable(index.movieList, movieListTable);
                } else {
                    JOptionPane.showMessageDialog(deletePanel, "Not found movie in list", "Error", JOptionPane.ERROR_MESSAGE);
                }
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