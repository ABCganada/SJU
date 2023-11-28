import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Index {
    private JPanel panel1;
    private JButton CreateButton;
    private JButton searchButton;
    private JButton deleteButton;
    private JButton reviewButton;
    private JButton ExitButton;

    public Index() {
        CreateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Create createPage = new Create();
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
                Delete deletePage = new Delete();
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
                Review reviewPage = new Review();
                JFrame reviewFrame = new JFrame("Review Page");
                reviewFrame.setContentPane(reviewPage.getReviewPanel());
                reviewFrame.pack();
                reviewFrame.setVisible(true);
            }
        });
        searchButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Search searchPage = new Search();
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
}
