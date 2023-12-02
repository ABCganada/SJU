import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;
import javax.swing.table.TableRowSorter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Comparator;
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

        ButtonGroup buttonGroup = new ButtonGroup();
        buttonGroup.add(gradeRadioButton);
        buttonGroup.add(participantsRadioButton);

        index.updateTable(index.movieList, movieListTable);

        //Search, cancel btn action
        cancelButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFrame frame = (JFrame) SwingUtilities.getWindowAncestor(cancelButton);

                if (frame != null) {
                    frame.dispose();
                }
            }
        });

        //Grade btn, Order by
        gradeRadioButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                TableRowSorter<TableModel> sorter = new TableRowSorter<>(movieListTable.getModel());
                movieListTable.setRowSorter(sorter);

                // Define a custom comparator for the "Grade" column
                Comparator<Object> gradeComparator = new Comparator<Object>() {
                    @Override
                    public int compare(Object grade1, Object grade2) {
                        try {
                            // Parse the strings as doubles before comparing
                            Double d1 = Double.parseDouble(grade1.toString());
                            Double d2 = Double.parseDouble(grade2.toString());

                            return Double.compare(d1, d2);
                        } catch (NumberFormatException ex) {
                            // Handle the case where the string is not a valid number
                            return 0; // You can modify this to suit your sorting preference
                        }
                    }
                };


                // Set the custom comparator for the "Grade" column
                sorter.setComparator(2, gradeComparator);

                // Sort by the "Grade" column in ascending order
                sorter.setSortKeys(List.of(new RowSorter.SortKey(2, SortOrder.DESCENDING)));

                // Update the table to apply sorting
                sorter.sort();
            }
        });

        participantsRadioButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                TableRowSorter<TableModel> sorter = new TableRowSorter<>(movieListTable.getModel());
                movieListTable.setRowSorter(sorter);

                // Define a custom comparator for the "Participants" column
                Comparator<Object> participantsComparator = new Comparator<Object>() {
                    @Override
                    public int compare(Object participants1, Object participants2) {
                        try {
                            // Parse the strings as integers before comparing
                            Integer p1 = Integer.parseInt(participants1.toString());
                            Integer p2 = Integer.parseInt(participants2.toString());

                            return Integer.compare(p1, p2);
                        } catch (NumberFormatException ex) {
                            // Handle the case where the string is not a valid number
                            return 0; // You can modify this to suit your sorting preference
                        }
                    }
                };

                // Set the custom comparator for the "Participants" column
                sorter.setComparator(3, participantsComparator);

                // Sort by the "Participants" column in descending order
                sorter.setSortKeys(List.of(new RowSorter.SortKey(3, SortOrder.DESCENDING)));

                // Update the table to apply sorting
                sorter.sort();
            }
        });
    }

    public JPanel getSearchPanel() {
        return searchPanel;
    }
}
