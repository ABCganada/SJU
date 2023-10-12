package arraylists.exercise;

import java.util.Scanner;

/**
 * 강사가 시험에서 학생들의 성적을 유지하는 데 사용할 수 있는 앱
 * GradeBook 수업을 작성하고 성적, 학급 평균, 최저 등급, 최고 등급 및
 * 등급 분포 막대 차트를 포함하는 성적 보고서를 표시하십시오.
 * 클래스 GradeBook 버전은 한 시험의 성적을 1차원 배열에 저장합니다.
 * */

class GradeBook{

    private int[] score;
    private int[] distribution = new int[11];
    private double avg;
    private int min;
    private int max;

    public GradeBook(int n){
        score = new int[n];
    }

    public double getAvg() {
        return avg;
    }

    public int getMin() {
        return min;
    }

    public int getMax() {
        return max;
    }

    void setScore(int i, int score){
        this.score[i] = score;
        this.distribution[score/10]++;
    }

    void calculateAvg(){
        for(int i=0; i<score.length; i++){
            this.avg += score[i];
        }
        avg /= score.length;
    }

    void setMinScore(){
        this.min = this.score[0];

        for(int i=1; i<score.length; i++){
            if(this.min > this.score[i]){
                this.min = this.score[i];
            }
        }
    }

    void setMaxScore(){
        this.max = this.score[0];

        for(int i=1; i<score.length; i++){
            if(this.max < this.score[i]){
                this.max = this.score[i];
            }
        }
    }

    void printAvgMinMax(){
        System.out.println("Class average is " + avg);
        System.out.println("Lowest grade is " + min);
        System.out.println("Highest grade is " + max);
    }

    void printDistribution(){
        for(int i=0; i<distribution.length-1; i++){
            System.out.print(i * 10 + "~" + (i * 10 + 9) + ": ");
            if(distribution[i] >= 1){
                for(int j=0; j<distribution[i]; j++){
                    System.out.print("*");
                }
            }
            System.out.println();
        }

        System.out.print("  100: ");
        for(int i=0; i<distribution[10]; i++){
            System.out.print("*");
        }
        System.out.println();
    }
}

public class Ex3 {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        GradeBook gradeBook = new GradeBook(10);

        System.out.println("The grades are : ");
        System.out.println();
        for(int i=0; i<10; i++){
            System.out.print("Student " + i+1 + ":");

            int scr = sc.nextInt();
            gradeBook.setScore(i, scr);
        }

        gradeBook.calculateAvg();
        gradeBook.setMinScore();
        gradeBook.setMaxScore();

        System.out.println();
        gradeBook.printAvgMinMax();

        gradeBook.printDistribution();
    }
}
