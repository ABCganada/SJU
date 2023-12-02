import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

class Movie {
    private String name;
    private String director;
    private double grade;
    private int sum;
    private int participants;

    public Movie(String name, String director) {
        this.name = name;
        this.director = director;
        grade = 0;
        sum = 0;
        participants = 0;
    }

    public void setGrade(double grade) {
        this.grade = grade;
    }

    public void setSum(int sum) {
        this.sum = sum;
    }

    public void setParticipants(int participants) {
        this.participants = participants;
    }

    public String getName() {
        return name;
    }

    public String getDirector() {
        return director;
    }

    public double getGrade() {
        return grade;
    }

    public int getParticipants() {
        return participants;
    }

    public int getSum() {
        return sum;
    }
}



public class Index {
    List<Movie> movieList = new ArrayList<>();

    private JPanel panel1;
    private JButton CreateButton;
    private JButton searchButton;
    private JButton deleteButton;
    private JButton reviewButton;
    private JButton ExitButton;

    public Index() {
        initMovieList(movieList);

        CreateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Create createPage = new Create(Index.this);
                JFrame createFrame = new JFrame("Create Movie Page");
                createFrame.setContentPane(createPage.getCreatePanel());
                createFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                createFrame.pack();
                createFrame.setVisible(true);
            }
        });
        ExitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        deleteButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Delete deletePage = new Delete(Index.this);
                JFrame deleteFrame = new JFrame("Delete Movie Page");
                deleteFrame.setContentPane(deletePage.getDeletePanel());
                deleteFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                deleteFrame.pack();
                deleteFrame.setVisible(true);
            }
        });
        reviewButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Review reviewPage = new Review(Index.this);
                JFrame reviewFrame = new JFrame("Review Page");
                reviewFrame.setContentPane(reviewPage.getReviewPanel());
                reviewFrame.pack();
                reviewFrame.setVisible(true);
            }
        });
        searchButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Search searchPage = new Search(Index.this);
                JFrame searchFrame = new JFrame("Search Movie Page");
                searchFrame.setContentPane(searchPage.getSearchPanel());
                searchFrame.pack();
                searchFrame.setVisible(true);
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Main Page");
        Index index = new Index();
        frame.setContentPane(index.panel1);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }

    void initMovieList(List<Movie> movieList) {
        Movie movie1 = new Movie("Parasite", "Bong");
        movie1.setParticipants(20);
        movie1.setSum(84);
        movie1.setGrade(84 / (double) 20);

        Movie movie2 = new Movie("The Dark Knight", "Nolan");
        movie2.setParticipants(24);
        movie2.setSum(108);
        movie2.setGrade(108 / (double) 24);

        Movie movie3 = new Movie("Inglourious Basterds", "Tarantino");
        movie3.setParticipants(16);
        movie3.setSum(75);
        movie3.setGrade(75 / (double) 16);

        Movie movie4 = new Movie("LA LA LAND", "Chazelle");
        movie4.setParticipants(4);
        movie4.setSum(15);
        movie4.setGrade(15 / (double) 4);

        Movie movie5 = new Movie("Catch Me If You Can", "Spielberg");
        movie5.setParticipants(67);
        movie5.setSum(213);
        movie5.setGrade(213 / (double) 67);

        Movie movie6 = new Movie("Guardians of the Galaxy Vol.3", "James Gunn");
        movie6.setParticipants(30);
        movie6.setSum(125);
        movie6.setGrade(125 / (double) 30);

        Movie movie7 = new Movie("Tazza", "Choi");
        movie7.setParticipants(11);
        movie7.setSum(37);
        movie7.setGrade(37 / (double) 11);

        movieList.add(movie1);
        movieList.add(movie2);
        movieList.add(movie3);
        movieList.add(movie4);
        movieList.add(movie5);
        movieList.add(movie6);
        movieList.add(movie7);
    }

    public void updateTable(List<Movie> movieList, JTable movieListTable) {
        DefaultTableModel model = new DefaultTableModel();
        model.addColumn("Name");
        model.addColumn("Director");
        model.addColumn("Grade");
        model.addColumn("Participants");

        model.addRow(new Object[]{"Name", "Director", "Grade", "Participants"});

        for (Movie movie : movieList) {
            model.addRow(new Object[]{movie.getName(), movie.getDirector(), formatDecimal(movie.getGrade()), movie.getParticipants()});
        }

        movieListTable.setModel(model);

        // Set the renderer for the table cells
        movieListTable.setDefaultRenderer(Object.class, new DefaultTableCellRenderer() {
            @Override
            public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
                Component c = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);

                if (row == 0) {
                    c.setBackground(Color.green);
                    c.setForeground(Color.black);
                } else {
                    if (isSelected) {
                        c.setBackground(table.getSelectionBackground());
                        c.setForeground(table.getSelectionForeground());
                    } else {
                        c.setBackground(Color.WHITE);
                        c.setForeground(Color.BLACK);
                    }
                }

                return c;
            }
        });

        // Set the renderer for the table header
        movieListTable.getTableHeader().setDefaultRenderer(new DefaultTableCellRenderer() {
            @Override
            public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
                Component c = super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
                c.setBackground(Color.GREEN); // Set the background color for the header row
                return c;
            }
        });
    }

    public String formatDecimal(double value) {
        DecimalFormat df = new DecimalFormat("#.##");
        return df.format(value);
    }
}